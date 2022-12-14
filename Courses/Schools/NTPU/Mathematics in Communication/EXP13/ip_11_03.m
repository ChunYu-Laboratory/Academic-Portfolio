clear all;
close all;

Nt = 2;                                 % No. of transmit antennas
Nr = 2;                                 % No. of receive antennas
S = [1 1 -1 -1; 1 -1 1 -1];             % Reference codebook
Eb = 1;                                 % Energy per bit
EbNo_dB = 0:1:30;                       % Average SNR per bit
No = Eb*10.^(-1*EbNo_dB/10);            % Noise variance
BER_ML = zeros(1,length(EbNo_dB));      % Bit-Error-Rate Initialization
BER_MMSE = zeros(1,length(EbNo_dB));    % Bit-Error-Rate Initialization
BER_ICD = zeros(1,length(EbNo_dB));     % Bit-Error-Rate Initialization


% Maximum Likelihood Detector:

for i = 1:length(EbNo_dB)
    no_errors = 0;
    no_bits = 0;
    %for iter=1:10000
    while no_errors <=200
        mu = zeros(1,4);
        %s = 2*randi([0 1],Nt,1) - 1;
        s = 2*floor(2*rand([Nt,1]))-1;
        no_bits = no_bits + length(s);
        H = (randn(Nr,Nt) + 1i*randn(Nr,Nt))/sqrt(2*Nr);
        noise = sqrt(No(i)/2)*(randn(Nr,1) + 1i*randn(Nr,1));
        y = H*s + noise;
        for j = 1:4
            mu(j) = sum(abs(y - H*S(:,j)).^2);  % Euclidean distance metric
        end
        [Min idx] = min(mu);
        s_h = S(:,idx);
        no_errors = no_errors + nnz(s_h-s);
    end
    BER_ML(i) = no_errors/no_bits;
end

% Minimum Mean-Sqaure-Error (MMSE) Detector:

for i = 1:length(EbNo_dB)
    no_errors = 0;
    no_bits = 0;
    %for iter=1:10000
    while no_errors <=200
        %s = 2*randi([0 1],Nt,1) - 1;
        s = 2*floor(2*rand([Nt,1]))-1;
        no_bits = no_bits + length(s);
        H = (randn(Nr,Nt) + 1i*randn(Nr,Nt))/sqrt(2*Nr);
        noise = sqrt(No(i)/2)*(randn(Nr,1) + 1i*randn(Nr,1));
        y = H*s + noise;
        w1 = (H*H' + No(i)*eye(Nr))^(-1) * H(:,1); % Optimum weight vector 1
        w2 = (H*H' + No(i)*eye(Nr))^(-1) * H(:,2); % Optimum weight vector 2
        W = [w1 w2];
        s_h = W'*y;
        for j = 1:Nt
            if real(s_h(j)) >= 0
                s_h(j) = 1;
            else
                s_h(j) = -1;
            end
        end
        no_errors = no_errors + nnz(s_h-s);
    end
    BER_MMSE(i) = no_errors/no_bits;
end


% Inverse Channel Detector:

for i = 1:length(EbNo_dB)
    no_errors = 0;
    no_bits = 0;
    %for iter=1:10000
    while no_errors <=200
        %s = 2*randi([0 1],Nt,1) - 1;
        s = 2*floor(2*rand([Nt,1]))-1;
        no_bits = no_bits + length(s);
        H = (randn(Nr,Nt) + 1i*randn(Nr,Nt))/sqrt(2*Nr);
        noise = sqrt(No(i)/2)*(randn(Nr,1) + 1i*randn(Nr,1));
        y = H*s + noise;

        s_h = H\y;  %%<=== Fill here
        for j = 1:Nt
            if real(s_h(j)) >= 0
                s_h(j) = 1;
            else
                s_h(j) = -1;
            end
        end
        no_errors = no_errors + nnz(s_h-s);
    end
    BER_ICD(i) = no_errors/no_bits;
end
% Plot the results:
semilogy(EbNo_dB,BER_ML,'r-o',EbNo_dB,BER_MMSE,'c-*',EbNo_dB,BER_ICD,'k-x', 'LineWidth', 1.5)
xlabel('Average SNR/bit (dB)','fontsize',10)
ylabel('BER','fontsize',10)
legend('ML','MMSE','ICD')
title(['Performance of MLD, MMSE and ICD for MIMO channel (410887040)'],'fontname','Helvetica');
fname = 'prob_11_03(410887040).png';
print (fname, '-dpng'); 
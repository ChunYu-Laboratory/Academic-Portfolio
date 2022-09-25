% MATLAB script for Illustrative Problem 7.10.
clear all;
close all;

SNRindB1=0:1:12;
SNRindB2=0:0.1:12;
M=16;
k=log2(M);
for i=1:length(SNRindB1)
    smld_err_prb(i)=cm_sm41(SNRindB1(i), 1000);	% simulated error rate
end

for i=1:length(SNRindB2)
    SNR=exp(SNRindB2(i)*log(10)/10);    	% signal-to-noise ratio
    % theoretical symbol error rate
    theo_err_prb(i)=4*qfunc(sqrt(3*k*SNR/(M-1)));
    %theo_err_prb(i)=4*erfc(sqrt(3*k*SNR/(M-1)/2))/2;
end

% Plotting commands follow.
semilogy(SNRindB1,smld_err_prb,'*');
hold
semilogy(SNRindB2,theo_err_prb);
legend(['Simulated symbol error rate  ';'Theoretical symbol error rate']);
xlabel('E_b/N_0 in dB','fontsize',16,'fontname','Helvetica');
ylabel('Error Probability','fontsize',16,'fontname','Helvetica');
title('Performance of a 16-QAM system from Monte Carlo simulation (410887040)','fontname','Helvetica');
fname = 'prob_07_10(410887040).png';
print (fname, '-dpng'); 
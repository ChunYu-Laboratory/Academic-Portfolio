% MATLAB script for Illustrative Problem 7.10.
clear all;
close all;

SNRindB1=0:1:12;
SNRindB2=0:0.1:12;
M=16;
k=log2(M);
for i=1:length(SNRindB1)
    [p_sym_err_a, p_sym_err_b, p_bit_err_a, p_bit_err_b] = cm_sm41(SNRindB1(i), 1000);	% simulated error rate
    smld_sym_err_prb_a(i) = p_sym_err_a;
    smld_sym_err_prb_b(i) = p_sym_err_b;
    smld_bit_err_prb_a(i) = p_bit_err_a;
    smld_bit_err_prb_b(i) = p_bit_err_b;
end

for i=1:length(SNRindB2)
    SNR=exp(SNRindB2(i)*log(10)/10);    	% signal-to-noise ratio
    % theoretical symbol error rate
    theo_sym_err_prb(i)=4*qfunc(sqrt(3*k*SNR/(M-1)));
    %theo_sym_err_prb(i)=4*erfc(sqrt(3*k*SNR/(M-1)/2))/2;
    
    % theoretical bit error rate of mapping a
    theo_bit_err_prb_a(i) = ( (erfc(sqrt(2*SNR/5))+erfc(3*sqrt(2*SNR/5)))/4 + (2*erfc(sqrt(2*SNR/5))+erfc(3*sqrt(2*SNR/5))-erfc(5*sqrt(2*SNR/5)))/4 )/2;
end

% Plotting commands follow.
semilogy(SNRindB1,smld_sym_err_prb_a,'k*');
hold on
semilogy(SNRindB1,smld_sym_err_prb_b,'mh');
hold on
semilogy(SNRindB1,smld_bit_err_prb_a,'bo');
hold on
semilogy(SNRindB1,smld_bit_err_prb_b,'rd');
hold on
semilogy(SNRindB2,theo_sym_err_prb, 'c');
hold on
semilogy(SNRindB2,theo_bit_err_prb_a, 'k');

legend({'Simulated symbol error rate of mapping a', 'Simulated symbol error rate of mapping b', 'Simulated bit error rate of mapping a', 'Simulated bit error rate of mapping b', 'Theoretical symbol error rate', 'Theoretical bit error rate of mapping a'}, 'Location', 'southwest');
xlabel('E_b/N_0 in dB','fontsize',16,'fontname','Helvetica');
ylabel('Error Probability','fontsize',16,'fontname','Helvetica');
title('Performance of a 16-QAM system from Monte Carlo simulation (410887040)','fontname','Helvetica');
fname = 'prob_07_10(410887040).png';
print (fname, '-dpng'); 
%graphics_toolkit gnuplot;
clear all;
close all;

SNRindB1=0:1:10;
SNRindB2=0:0.1:10;
for i=1:length(SNRindB1)
  [pb,ps]=cm_sm32(SNRindB1(i), 100);    	% simulated bit and symbol error rates
  smld_bit_err_prb(i)=pb; 
  smld_symbol_err_prb(i)=ps;
end

for i=1:length(SNRindB2)
  SNR=exp(SNRindB2(i)*log(10)/10);     	% signal-to-noise ratio
  theo_err_prb(i)=qfunc(sqrt(2*SNR)); 	% theoretical bit-error rate
  %theo_err_prb(i)=erfc(sqrt(2*SNR/2))/2; 	% theoretical bit-error rate
end

% Plotting commands follow

semilogy(SNRindB1,smld_bit_err_prb,'*');
hold on;
semilogy(SNRindB1,smld_symbol_err_prb,'o');
semilogy(SNRindB2,theo_err_prb, '-k');

legend(['Simulated bit-error rate   ';'Simulated symbol-error rate';'Theoretical bit-error rate ']);
xlabel('E_b/N_0 in dB (fixed NumofSymbolErr = 100)','fontsize',16,'fontname','Helvetica');
ylabel('Error Probability','fontsize',16,'fontname','Helvetica');
title('Performance of a 4-PSK system from Monte Carlo simulation (410887040)','fontname','Helvetica');
fname = 'prob_07_05(410887040)_numofsymbolerr_100.png';
print (fname, '-dpng'); 

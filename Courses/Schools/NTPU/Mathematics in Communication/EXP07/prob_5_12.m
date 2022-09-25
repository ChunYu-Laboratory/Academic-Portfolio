clear all;
close all;
SNRindB1=0:1:12;	  		
SNRindB2=0:0.1:12;			
for i=1:length(SNRindB1)
  % simulated error rate 
  smld_err_prb1(i)=smldpe512(SNRindB1(i), 5);    
  smld_err_prb2(i)=smldpe512(SNRindB1(i), 50);    
  smld_err_prb3(i)=smldpe512(SNRindB1(i), 500);
end

for i=1:length(SNRindB2)
  % signal-to-noise ratio
  %SNR_per_bit=exp(SNRindB2(i)*log(10)/10);  
  SNR_per_bit=10^(SNRindB2(i)/10);
  % theoretical error rate
  theo_err_prb(i)=(3/2)*qfunc(sqrt((4/5)*SNR_per_bit)); 
  %theo_err_prb(i)=(3/2)*erfc(sqrt((4/5)*SNR_per_bit/2))/2;  
end

% Plotting commands follow.
semilogy(SNRindB1,smld_err_prb1,'r*');
hold on
semilogy(SNRindB1,smld_err_prb2,'c*');
hold on
semilogy(SNRindB1,smld_err_prb3,'k*');
hold on
semilogy(SNRindB2,theo_err_prb);
grid;
xlabel('10 log_{10}E_{avb}/N_0');
ylabel('Error Probability')
title('Symbol Error Probability for 4-PAM');
legend('numoferr=5  ','numoferr=50 ','numoferr=500');

fname = 'prob_05_12(410887040).png';
print (fname, '-dpng');
% MATLAB script for Illustrative Problem 5.6.
clear all;
close all;
%graphics_toolkit gnuplot;

echo on
SNRindB1=0:1:12;
SNRindB2=0:0.1:12;
smld_err_prb1 = zeros(length(SNRindB1));
smld_err_prb2 = zeros(length(SNRindB1));
smld_err_prb3 = zeros(length(SNRindB1));
for i=1:length(SNRindB1)
  % simulated error rate
  % rename smldpe56_student.m to smldpe56.m
  smld_err_prb1(i)=smldpe56(SNRindB1(i), 10);   
  smld_err_prb2(i)=smldpe56(SNRindB1(i), 100);  
  smld_err_prb3(i)=smldpe56(SNRindB1(i), 1000);  
  echo off ;
end
echo on ;
for i=1:length(SNRindB2)
  SNR=exp(SNRindB2(i)*log(10)/10);  
  % theoretical error rate    
  % theo_err_prb(i) = qfunc(sqrt(SNR)); 
  theo_err_prb(i) = qfunc(sqrt(SNR));    
  echo off ;
end
echo on;
% Plotting commands follow.
semilogy(SNRindB1,smld_err_prb1,'r*');
hold on
semilogy(SNRindB1,smld_err_prb2,'c*');
hold on
semilogy(SNRindB1,smld_err_prb3,'k*');
hold on
semilogy(SNRindB2,theo_err_prb);
grid;
xlabel('10 log_{10}E/N_0');
ylabel('Error Probability');
legend('numoferr=10  ','numoferr=100 ','numoferr=1000');


fname = 'prob_05_06(410887040).png';
print (fname, '-dpng'); 


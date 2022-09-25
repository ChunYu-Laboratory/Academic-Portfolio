% Problem 9.7
clear all;
close all;
Eb = 1;
EbNo_dB = 0:1:35;
No_over_2  = Eb*10.^(-EbNo_dB/10);
sigma = 1;
BER = zeros(1,length(EbNo_dB));
for i=1:length(EbNo_dB)
   numoferr = 0;
   N = 1; % the number of samples of data source
   while numoferr < 1000
      % Generate a random bit
      %  m= 0 or 1
      t=rand;
      if t<0.5
         m=0;
      else
         m=1;
      end
      
      % Generate a Rayleigh rv  
      u=rand;
      alpha = sigma*sqrt(-2*log(u));  %%%%<=== (a) fill here
       
      % Generate AWGN
      noise = sqrt(No_over_2(i))*randn;

      % Generate received data
      y = ((-1)^m)*alpha*sqrt(Eb) + noise;   % <===fill here

      
      % Make decision
      if y > 0
         m_d = 0;   % <===fill here
      else
         m_d = 1;   % <===fill here
      end
      
      if m~=m_d
          numoferr = numoferr + 1;      
      end
      
      N = N+1;
   end
   BER(i) = numoferr/N;

end

rho_b = Eb./No_over_2*sigma^2;
P2 = 1/2*(1-sqrt(rho_b./(1+rho_b)));

semilogy(EbNo_dB,BER,'-*',EbNo_dB,P2,'-o');
xlabel('Average SNR/bit (dB)','fontsize',16,'fontname','Helvetica');
ylabel('Error Probability','fontsize',16,'fontname','Helvetica');
legend('Monte Carlo Simulation','Theoretical Value');
title(['Monte Carlo Simulation of Frequency Nonselective Channel (410887040)'], 'fontname','Helvetica');
fname = 'prob_09_07(410887040).png';
print (fname, '-dpng'); 

function [p]=smldpe56(snr_in_dB, err_num)
E=1;
SNR=exp(snr_in_dB*log(10)/10);	   	% signal-to-noise ratio
sgma=E/sqrt(2*SNR);		   	% sigma, standard deviation of noise

% detection, and probability of error calculation 
numoferr = 0;
N = 1; % the number of samples of data source
while numoferr < err_num
  % generation of the binary data source
  temp = rand;   	      			% a uniform random variable over (0,1)
  if (temp<0.5)
    dsource(N) = 0;   	      		% With probability 1/2, source output is 0.
  else
    dsource(N) = 1;	      		% With probability 1/2, source output is 1.
  end
  % matched filter outputs
  if (dsource(N)==0)
    r0 = E + sgma*randn;                %<=== AWGN, use randn
    r1 = sgma*randn;	      		%<=== AWGN, use randn,  if the source output is "0"    
  else
    r0 = sgma*randn;                 %<=== AWGN, use randn
    r1 = E + sgma*randn;    		   %<=== AWGN, use randn% if the source output is "1"
  end
  % Detector follows.
  if (r0>r1)
    decis = 0;		      		% Fill the decision
  else
    decis = 1;		      		% Fill the decision 
  end
  if (decis~=dsource(N))    		% If it is an error, increase the error counter.
    numoferr=numoferr+1;
  end
  N = N+1;
end
p=numoferr/N;	  	      		% probability of error estimate

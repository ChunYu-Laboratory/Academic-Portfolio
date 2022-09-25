function [pb,ps]=cm_sm32(snr_in_dB, symbol_err_num)
% [pb,ps]=cm_sm32(snr_in_dB)
%		CM_SM32  finds the probability of bit error and symbol error for the 
%   		given value of snr_in_dB, signal-to-noise ratio in dB.

E=1;				  	% energy per symbol
snr=10^(snr_in_dB/10);	 	  	% signal-to-noise ratio
sgma=sqrt(E/snr)/2;	  	  	% noise variance

% the signal mapping
s00=[1 0];
s01=[0 1];
s11=[-1 0];
s10=[0 -1];

% detection and the probability of error calculation
numofsymbolerror = 0;
numofbiterror = 0;
N = 1; % the number of samples of data source

while numofsymbolerror < symbol_err_num
  % generation of the data source
  temp = rand;			  	% a uniform random variable between 0 and 1
  if (temp<0.25)		  	% With probability 1/4, source output is "00."
    dsource1(N) = 0;
    dsource2(N) = 0;
  elseif (temp<0.5)		  	% With probability 1/4, source output is "01."
    dsource1(N) = 0;              %<============== Fill here
    dsource2(N) = 1;              %<============== Fill here
  elseif (temp<0.75)	 	  	% With probability 1/4, source output is "10."
    dsource1(N) = 1;                %<============== Fill here
    dsource2(N) = 0;                 %<============== Fill here
  else			           	% With probability 1/4, source output is "11."
   dsource1(N) = 1;             %<============== Fill here
   dsource2(N) = 1;             %<============== Fill here
  end
  % The received signal at the detector, 
  n = [sgma*randn,sgma*randn];
  if ((dsource1(N)==0) && (dsource2(N)==0))
    r = s00+n;
  elseif ((dsource1(N)==0) && (dsource2(N)==1))
    r = s01+n;                     %<============== Fill here
  elseif ((dsource1(N)==1) && (dsource2(N)==0))
    r = s10+n;                  %<============== Fill here
  else
    r = s11+n;                  %<============== Fill here
  end
  % The correlation metrics are computed below.
  % by dot product
%   c00 = dot(r,s00);
%   c01 = dot(r,s01);             %<============== Fill here
%   c10 = dot(r,s10);             %<============== Fill here
%   c11 = dot(r,s11);             %<============== Fill here 
  c00 = r(1)*s00(1) + r(2)*s00(2);
  c01 = r(1)*s01(1) + r(2)*s01(2);
  c10 = r(1)*s10(1) + r(2)*s10(2);
  c11 = r(1)*s11(1) + r(2)*s11(2);

  % The decision on the ith symbol is made next.
  c_max=max([c00 c01 c10 c11]);
  if (c00==c_max)
    decis1=0; decis2=0;
  elseif (c01==c_max)
    decis1=0; decis2=1;    %<============== Fill here
  elseif (c10==c_max)
    decis1=1; decis2=0;   %<============== Fill here
  else
    decis1=1; decis2=1;    %<============== Fill here
  end
  % Increment the error counter, if the decision is not correct.
  symbolerror = 0;
  if (decis1~=dsource1(N))
    numofbiterror=numofbiterror+1;
    symbolerror=1;
  end
  if (decis2~=dsource2(N))
    numofbiterror=numofbiterror+1;
    symbolerror=1;
  end
  if (symbolerror==1)
    numofsymbolerror = numofsymbolerror+1;
  end
  
  N = N+1;
end
ps=numofsymbolerror/N;	          	% since there are totally N symbols
pb=numofbiterror/(2*N);    	  	% since 2N bits are transmitted

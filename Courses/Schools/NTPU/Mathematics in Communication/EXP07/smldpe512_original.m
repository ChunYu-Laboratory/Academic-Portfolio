function [p]=smldpe512(snr_in_dB)

d=1;
SNR=exp(snr_in_dB*log(10)/10);	   	% signal to noise ratio per bit
sgma=sqrt((5*d^2)/(4*SNR));	   	% sigma, standard deviation of noise
N=10000;	 		   	% number of symbols being simulated
% Generation of the quaternary data source follows.
for i=1:N
  temp=rand;   	      			% generate the messages 0, 1, 2, 3 with equal probability (1/4)
  if (temp<0.25)               % generate the messages 0
    dsource(i)=0;           		
  elseif (temp<0.5)                    % <======== your codes, generate the messages 1
    dsource(i)=1;     		                % <======== your codes
  elseif (temp<0.75)                   % <======== your codes, generate the messages 2
    dsource(i)=2;    		                % <======== your codes
  else                          % <======== your codes, generate the messages 3
   	dsource(i)=3;      		                % <======== your codes
  end
end
% detection, and probability of error calculation
numoferr=0;
for i=1:N
  % Do PAM and add the noise 
  if (dsource(i)==0)           % if the message is 0, the detector output is -3d + noise
       r=-3*d+sgma*randn;  		
  elseif (dsource(i)==1)       % if the message is 1, the detector output is -d + noise
 		r=-d+sgma*randn;                        % <======== your codes
  elseif (dsource(i)==2)        % if the message is 2, the detector output is d + noise
 		r=d+sgma*randn;                        % <======== your codes
  else                          % if the message is 3, the detector output is 3d + noise
        r=3*d+sgma*randn;                        % <======== your codes
  end
  % Detector follows.
  if ( r<-2*d  ),                      % <======== your codes
    decis=0;		     		% Decision is message 0
  elseif ( r<0 ),                   % <======== your codes
    decis=1;		     		% Decision is message 1
  elseif ( r<2*d ),                  % <======== your codes
    decis=2;		     		% Decision is message 2
  else
    decis=3;		     		% Decision is message 3
  end
  if (decis~=dsource(i))   		% If it is an error, increase the error counter.
    numoferr=numoferr+1;
  end
end;
p=numoferr/N;	  	     		% probability of error estimate

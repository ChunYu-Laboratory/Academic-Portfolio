function [p]=smldpe512(snr_in_dB, err_num)
d=1;
SNR=exp(snr_in_dB*log(10)/10);	   	% signal to noise ratio per bit
sgma=sqrt((5*d^2)/(4*SNR));	   	% sigma, standard deviation of noise

% detection, and probability of error calculation
numoferr = 0;
N = 1; % the number of samples of data source
while numoferr < err_num
  % Generation of the quaternary data source follows.
  temp = rand;   	      			% generate the messages 0, 1, 2, 3 with equal probability (1/4)
  if (temp<0.25)               % generate the messages 0
    dsource(N) = 0;           		
  elseif (temp<0.5)                    % <======== your codes, generate the messages 1
    dsource(N) = 1;     		                % <======== your codes
  elseif (temp<0.75)                   % <======== your codes, generate the messages 2
    dsource(N) = 2;    		                % <======== your codes
  else                          % <======== your codes, generate the messages 3
   	dsource(N) = 3;      		                % <======== your codes
  end

  % Do PAM and add the noise 
  if (dsource(N)==0)           % if the message is 0, the detector output is -3d + noise
       r = -3*d + sgma*randn;  		
  elseif (dsource(N)==1)       % if the message is 1, the detector output is -d + noise
 		r = -d + sgma*randn;                        % <======== your codes
  elseif (dsource(N)==2)        % if the message is 2, the detector output is d + noise
 		r = d + sgma*randn;                        % <======== your codes
  else                          % if the message is 3, the detector output is 3d + noise
        r = 3*d + sgma*randn;                        % <======== your codes
  end
  % Detector follows.
  if ( r<-2*d )                      % <======== your codes
    decis = 0;		     		% Decision is message 0
  elseif ( r<0 )                   % <======== your codes
    decis = 1;		     		% Decision is message 1
  elseif ( r<2*d )                  % <======== your codes
    decis = 2;		     		% Decision is message 2
  else
    decis = 3;		     		% Decision is message 3
  end
  if (decis~=dsource(N))   		% If it is an error, increase the error counter.
    numoferr=numoferr+1;
  end
  N = N+1;
end
p=numoferr/N;	  	     		% probability of error estimate

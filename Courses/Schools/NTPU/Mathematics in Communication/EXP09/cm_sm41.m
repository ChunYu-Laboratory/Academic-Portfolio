function [p]=cm_sm41(snr_in_dB, err_num)
% [p]=cm_sm41(snr_in_dB)
%		CM_SM41  finds the probability of error for the given
%   		value of snr_in_dB, SNR in dB.
d=1;				  	% min. distance between symbols
Eav=10*d^2;		 	  	% energy per symbol
snr=10^(snr_in_dB/10);	 	  	% SNR per bit (given)
sgma=sqrt(Eav/(8*snr));	  	  	% noise variance
M=16;

% Mapping to the signal constellation follows.
mapping=[-3*d 3*d;
	      -d  3*d;
           d  3*d;
	     3*d  3*d;
	      -3*d  d;
	         -d  d;
             d  d;
	      3*d  d;
     	 -3*d  -d; 
 	   -d  -d; 
	    d  -d;
      3*d  -d;
	 -3*d  -3*d;
	   -d  -3*d;
	    d  -3*d;
	  3*d  -3*d];

numoferr = 0;
N = 1; % the number of samples of data source
while numoferr < err_num
  % Generation of the data source follows.
  temp = rand;		        	  	% a uniform R.V. between 0 and 1
  dsource = 1+floor(M*temp);	  	% a number between 1 and 16, uniform 

  qam_sig = mapping(dsource,:);

  % received signal

  n = [sgma*randn sgma*randn];
  %[n(1) n(2)]=gngauss(sgma);
  r = qam_sig + n;

% detection and error probability calculation
 
    % write your decoder here
    % The decision is named decis
    % Hint.
    % Given received signal vector r(i,:),
    % find the minimum distance among r(i,:) and the 16 signal points in
    % mapping(j,:), j=1,2,... 16. If the distance to mapping(k,:) is
    % minimum, decis=k

%  comparison of minimum distance in signal constellation diagram (not efficient way)
%     for j=1:16
%         squared_len(j) = sum( (r - mapping(j,:)).^2 );
%     end
%     [x,decis] = min(squared_len);


% binary search for decoding signal in constellation diagram (efficient)
    if r(1) < 0
        if r(1) < -2*d
            if r(2) < 0
                if r(2) < -2*d
                    decis = 13;
                else
                    decis = 9;
                end
            else
                if r(2) < 2*d
                    decis = 5;
                else
                    decis = 1;
                end
            end
                
        else
            if r(2) < 0
                if r(2) < -2*d
                    decis = 14;
                else
                    decis = 10;
                end
            else
                if r(2) < 2*d
                    decis = 6;
                else
                    decis = 2;
                end
            end
                
        end
  
    else
        if r(1) < 2*d
            if r(2) < 0
                if r(2) < -2*d
                    decis = 15;
                else
                    decis = 11;
                end
            else
                if r(2) < 2*d
                    decis = 7;
                else
                    decis = 3;
                end
            end
                
        else
            if r(2) < 0
                if r(2) < -2*d
                    decis = 16;
                else
                    decis = 12;
                end
            else
                if r(2) < 2*d
                    decis = 8;
                else
                    decis = 4;
                end
            end
                
        end
    end
    
  if (decis~=dsource)
    numoferr=numoferr+1;
  end
  N = N+1;
end
p=numoferr/N;		  
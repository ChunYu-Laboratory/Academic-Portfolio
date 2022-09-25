function [p_sym_err_a, p_sym_err_b, p_bit_err_a, p_bit_err_b] = cm_sm41(snr_in_dB, err_num)
% [p]=cm_sm41(snr_in_dB)
%		CM_SM41  finds the probability of error for the given
%   		value of snr_in_dB, SNR in dB.
d=1;				  	% min. distance between symbols
Eav=10*d^2;		 	  	% energy per symbol
snr=10^(snr_in_dB/10);	 	  	% SNR per bit (given)
sgma=sqrt(Eav/(8*snr));	  	  	% noise variance
M=16;

% Mapping to the signal constellation follows.
mapping_a = [     d  d;
	            d  3*d;
              3*d    d;
	          3*d  3*d;
	             d  -d;
	           d  -3*d;
               3*d  -d;
	         3*d  -3*d;
         	     -d  d;
 	           -d  3*d;
	           -3*d  d;
             -3*d  3*d;
	            -d  -d;
	          -d  -3*d;
	          -3*d  -d;
	        -3*d  -3*d ];

mapping_b = [ -3*d 3*d;
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
	         3*d  -3*d ];

numof_symbol_err_a = 0;
numof_symbol_err_b = 0;
numof_bit_err_a = 0;
numof_bit_err_b = 0;
N = 1; % the number of samples of data source
while ( numof_symbol_err_a < err_num ) || ( numof_symbol_err_b < err_num )
  % Generation of the data source follows.
  temp = rand;		        	  	% a uniform R.V. between 0 and 1
  dsource = 1+floor(M*temp);	  	% a number between 1 and 16, uniform

  qam_sig_a = mapping_a(dsource,:);
  qam_sig_b = mapping_b(dsource,:);

  % received signal

  n = [sgma*randn sgma*randn];
  %[n(1) n(2)]=gngauss(sgma);
  r_a = qam_sig_a + n;
  r_b = qam_sig_b + n;

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

% mapping_a
if r_a(1) < 0
    if r_a(1) < -2*d
        if r_a(2) < 0
            if r_a(2) < -2*d
                decis_a = 16;
            else
                decis_a = 15;
            end
        else
            if r_a(2) < 2*d
                decis_a = 11;
            else
                decis_a = 12;
            end
        end

    else
        if r_a(2) < 0
            if r_a(2) < -2*d
                decis_a = 14;
            else
                decis_a = 13;
            end
        else
            if r_a(2) < 2*d
                decis_a = 9;
            else
                decis_a = 10;
            end
        end

    end

else
    if r_a(1) < 2*d
        if r_a(2) < 0
            if r_a(2) < -2*d
                decis_a = 6;
            else
                decis_a = 5;
            end
        else
            if r_a(2) < 2*d
                decis_a = 1;
            else
                decis_a = 2;
            end
        end

    else
        if r_a(2) < 0
            if r_a(2) < -2*d
                decis_a = 8;
            else
                decis_a = 7;
            end
        else
            if r_a(2) < 2*d
                decis_a = 3;
            else
                decis_a = 4;
            end
        end

    end
end

% mapping_b
    if r_b(1) < 0
        if r_b(1) < -2*d
            if r_b(2) < 0
                if r_b(2) < -2*d
                    decis_b = 13;
                else
                    decis_b = 9;
                end
            else
                if r_b(2) < 2*d
                    decis_b = 5;
                else
                    decis_b = 1;
                end
            end

        else
            if r_b(2) < 0
                if r_b(2) < -2*d
                    decis_b = 14;
                else
                    decis_b = 10;
                end
            else
                if r_b(2) < 2*d
                    decis_b = 6;
                else
                    decis_b = 2;
                end
            end

        end

    else
        if r_b(1) < 2*d
            if r_b(2) < 0
                if r_b(2) < -2*d
                    decis_b = 15;
                else
                    decis_b = 11;
                end
            else
                if r_b(2) < 2*d
                    decis_b = 7;
                else
                    decis_b = 3;
                end
            end

        else
            if r_b(2) < 0
                if r_b(2) < -2*d
                    decis_b = 16;
                else
                    decis_b = 12;
                end
            else
                if r_b(2) < 2*d
                    decis_b = 8;
                else
                    decis_b = 4;
                end
            end

        end
    end

% error detection
  if (decis_a~=dsource)
    numof_symbol_err_a = numof_symbol_err_a + 1;
    numof_bit_err_a = numof_bit_err_a + sum( dec2bin((decis_a-1), 4) ~= dec2bin((dsource-1), 4) );
  end

  if (decis_b~=dsource)
    numof_symbol_err_b = numof_symbol_err_b + 1;
    numof_bit_err_b = numof_bit_err_b + sum( dec2bin((decis_b-1), 4) ~= dec2bin((dsource-1), 4) );
  end

  N = N+1;
end
p_sym_err_a = numof_symbol_err_a/N;  % there are N symbols in total
p_sym_err_b = numof_symbol_err_b/N;
p_bit_err_a = numof_bit_err_a/(4*N); % 4N bits are transmitted
p_bit_err_b = numof_bit_err_b/(4*N);
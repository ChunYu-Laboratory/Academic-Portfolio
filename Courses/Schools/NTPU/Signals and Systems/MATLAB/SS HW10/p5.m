% Length of signal
N = 10;
M = 10;

% Signals in Time-Domain
x = ones( 1, N ) % x[n]
y = ones( 1, M ) % y[n]

% z = x convolve with y in Time-Domain
z = conv( x, y ) % z[n]

% Signals in Frequency-Domain using discrete Fourier transform

% Using Fast Fourier transform algorithm with O( N log N )
% fft and ifft function return n-point DFT
% If no n-point value is specified, length of output signal is the same length of input signal
% x, y both only with dc term 1, so their DFT frequency response are also only with dc term which value is 10
X = fft(x)
Y = fft(y)

% convolution in Time-Domain is equivalent to the multiplication in Frequency-Domain
Z = X .* Y
fft_z = fft(z)

% inverse Fast Fourier transform
% The inverse transform result does not equal to conv(x,y) because Z only with 10 points
% The full convolution would be of length length(x)+length(y)-1 = 19
ifft_Z = ifft(Z)

% Fast Fourier transform with (N+M-1) points
% By padding with trailing zeros or truncating to specified length
Xp = fft( x, N+M-1 )
Yp = fft( y, N+M-1 )
Zp = Xp .* Yp
zp = ifft(Zp)

% error signal computing the sum of magnitude of difference of two signals
% one in time-domain doing convolution
% another by transforming to frequency-domain doing multiplication and inverse back to time-domain
err = sum( abs( z - zp ) ) % the result is approximately equal to zero

% plot the graph

figure(1)
tiledlayout(3,1)

nexttile
stem( 0:9, x, 'filled', LineWidth=3, MarkerSize=8 )
title( 'x[n]' )
axis( [-1, 19, -1, 3] );
grid on

nexttile
stem( 0:9, y, 'filled', LineWidth=3, MarkerSize=8 )
title( 'y[n]' )
axis( [-1, 19, -1, 3] );
grid on

nexttile
stem( 0:18, z, 'filled', LineWidth=3, MarkerSize=8 )
title( 'z[n] = x[n] \ast y[n]' )
axis( [-1, 19, -1, 12] );
grid on

figure(2)
tiledlayout(3,1)

nexttile
stem( 0:9, X, 'filled', LineWidth=3, MarkerSize=8 )
title( 'X' )
axis( [-1, 10, -1, 12] );
grid on

nexttile
stem( 0:9, Y, 'filled', LineWidth=3, MarkerSize=8 )
title( 'Y' )
axis( [-1, 10, -1, 12] );
grid on

nexttile
stem( 0:9, Z, 'filled', LineWidth=3, MarkerSize=8 )
title( 'Z = X * Y' )
axis( [-1, 10, -1, 120] );
grid on

figure(3)
tiledlayout(2,1)

nexttile
stem( 0:9, abs(Z), 'filled', LineWidth=3, MarkerSize=8 )
title( '|Z| = |X * Y|' )
axis( [-1, 19, -1, 120] );
grid on

nexttile
stem( 0:18, abs(fft_z), 'filled', LineWidth=3, MarkerSize=8 )
title( '|fft(z)|' )
axis( [-1, 19, -1, 120] );
grid on

figure(4)
tiledlayout(2,1)

nexttile
stem( 0:18, z, 'filled', LineWidth=3, MarkerSize=8 )
title( 'z[n] = x[n] \ast y[n]' )
axis( [-1, 19, -1, 12] );
grid on

nexttile
stem( 0:9, ifft_Z, 'filled', LineWidth=3, MarkerSize=8 )
title( 'ifft(Z)' )
axis( [-1, 19, -1, 12] );
grid on

figure(5)
tiledlayout(3,1)

nexttile
stem( 0:18, abs(Xp), 'filled', LineWidth=3, MarkerSize=8 )
title( '|Xp|' )
axis( [-1, 19, -1, 12] );
grid on

nexttile
stem( 0:18, abs(Yp), 'filled', LineWidth=3, MarkerSize=8 )
title( '|Yp|' )
axis( [-1, 19, -1, 12] );
grid on

nexttile
stem( 0:18, abs(Zp), 'filled', LineWidth=3, MarkerSize=8 )
title( '|Zp| = |Xp * Yp|' )
axis( [-1, 19, -1, 120] );
grid on

figure(6)
tiledlayout(2,1)

nexttile
stem( 0:18, z, 'filled', LineWidth=3, MarkerSize=8 )
title( 'z[n] = x[n] \ast y[n]' )
axis( [-1, 19, -1, 12] );
grid on

nexttile
stem( 0:18, z, 'filled', LineWidth=3, MarkerSize=8 )
title( 'zp[n] = ifft(Zp)' )
axis( [-1, 19, -1, 12] );
grid on
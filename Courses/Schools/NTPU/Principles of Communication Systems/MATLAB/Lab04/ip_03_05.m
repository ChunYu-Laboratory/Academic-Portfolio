% DSB-AM demodulation
% The message signal is +1 for 0 < t < t0/3, -2 for t0/3 < t < 2t0/3, and zero otherwise
echo on
t0=.15;         % signal duration
ts=1/1500;      % sampling interval
fc=250;         % carrier frequency
fs=1/ts;        % sampling frequency
t=[0:ts:t0];    % time vector
df=0.3;         % desired frequency resolution
% message signal
m=[ones(1,t0/(3*ts)),-2*ones(1,t0/(3*ts)),zeros(1,t0/(3*ts)+1)];
c=cos(2*pi*fc.*t);      % carrier signal
u=m.*c;     % modulated signal
y=u.*c;     % mixing by the same carrier at receiver
[M,m,df1]=fftseq(m,ts,df);      % Fourier transform (DFT)
M=M/fs;     % scaling to CTFT
[U,u,df1]=fftseq(u,ts,df);      % Fourier transform (DFT)
U=U/fs;     % scaling to CTFT
[Y,y,df1]=fftseq(y,ts,df);      % Fourier transform (DFT)
Y=Y/fs;     % scaling to CTFT
f_cutoff=300;       % cutoff freq. of the Lowpass filter
n_cutoff=floor(f_cutoff/df1);       % index of cutoff freq. in frequency vector
f=[0:df1:df1*(length(y)-1)]-fs/2;       % frequency vector
H=zeros(size(f));       % Lowpass filter (LPF) with bandwidth of f_cutoff
H(1:n_cutoff)=2*ones(1,n_cutoff);   % LPF at 0 <= f <= f_cutoff with magnitude of 2
H(length(f)-n_cutoff+1:length(f))=2*ones(1,n_cutoff);   % LPF at -f_cutoff <= f < 0 with magnitude of 2
DEM=H.*Y;       % spectrum of the LPF output
dem=real(ifft(DEM))*fs;     % demodulated output
pause % Press a key to see the effect of mixing.
clf
subplot(3,1,1)
plot(f,fftshift(abs(M)))
title('Spectrum of the Message Signal')
xlabel('Frequency')
subplot(3,1,2)
plot(f,fftshift(abs(U)))
title('Spectrum of the Modulated Signal')
xlabel('Frequency')
subplot(3,1,3)
plot(f,fftshift(abs(Y)))
title('Spectrum of the Mixer Output')
xlabel('Frequency')
pause % Press a key to see the effect of filtering on the mixer output.
clf
subplot(3,1,1)
plot(f,fftshift(abs(Y)))
title('Spectrum of the Mixer Output')
xlabel('Frequency')
subplot(3,1,2)
plot(f,fftshift(abs(H)))
title('Lowpass Filter Characteristics')
xlabel('Frequency')
subplot(3,1,3)
plot(f,fftshift(abs(DEM)))
title('Spectrum of the Demodulator output')
xlabel('Frequency')
pause % Press a key to compare the spectra of the message and the received signal.
clf
subplot(2,1,1)
plot(f,fftshift(abs(M)))
title('Spectrum of the Message Signal')
xlabel('Frequency')
subplot(2,1,2)
plot(f,fftshift(abs(DEM)))
title('Spectrum of the Demodulator Output')
xlabel('Frequency')
pause % Press a key to see the message and the demodulator output signals.
subplot(2,1,1)
plot(t,m(1:length(t)))
title('The Message Signal')
xlabel('Time')
subplot(2,1,2)
plot(t,dem(1:length(t)))
title('The Demodulator Output')
xlabel('Time')
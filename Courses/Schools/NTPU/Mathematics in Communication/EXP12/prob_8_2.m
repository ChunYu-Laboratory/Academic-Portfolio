clear all;
close all;
K = 10;
N = 2*K;
T = 0.5; % symbol duration

% 16 QAM constellation
A = zeros(4,4);
for i = 1:4
  for k = 1:4
     A(i,k) = (i-2.5)*2 + sqrt(-1)*(k-2.5)*2;
  end
end
A

% randomly generate K 16-QAM symbols
X = zeros(1,K);
for i = 1:K
   ind = 1+floor(16*rand);
   X(i) = A(ind);
end

% form conjugate symmetry sequence  X prime
Xp = [ real(X(1)) X(2:K) imag(X(1)) conj(X(K:-1:2)) ]; %<== Fill here. Form conjugate symmetry sequence  X prime

% form OFDM signal by interpolating the IDFT of X

t = 0:T/(20*N):T;
xt = zeros(size(t));
for k = 0:N-1
   xt = xt + Xp(k+1)*exp(1i*2*pi*k*t/T);
end

% IFFT of Xp, note that the definition of IFFT in OCTAVE may differ from that in textbook by a scalar.
xs = ifft(Xp)*N;
max_abs_imag_xs = max(abs(imag(xs)))  % whether xs is real or not    

hold on;
plot(t,real(xt), 'LineWidth', 1.5);
stem(0:T/N:(T-T/(20*N)),real(xs), 'LineWidth', 2);
grid;
legend('OFDM signal x(t)','IFFT of symbol sequence');
xlabel('time','fontsize',16,'fontname','Helvetica');
ylabel('Amplitude','fontsize',16,'fontname','Helvetica');
title(['OFDM Signal of ', num2str(K),' sub-carriers (410887040)'],'fontsize',16,'fontname','Helvetica');
fname = 'prob_08_02(410887040).png';
print (fname, '-dpng'); 


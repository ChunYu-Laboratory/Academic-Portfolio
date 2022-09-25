%graphics_toolkit gnuplot;
clear all;
close all;

t0=.4;                              	% signal duration
ts=0.0004;                            	% sampling interval
fc=250;                              	% carrier frequency
a=0.2;                              	% Modulation index
fs=1/ts;                             	% sampling frequency
t=[0:ts:t0];                         	% time vector
                         	            % required frequency resolution

% message signal
% modified version
t_seg_points = t0/4/ts;
m = [ t(1:t_seg_points), (t0/4).*ones(1, t_seg_points), (3*t0/4)-t(2*t_seg_points+1:3*t_seg_points), zeros(1, t_seg_points+1) ];

% teacher's version
% for i=0:length(t)-1
%     tt=i*ts;
%     if tt<t0/4
%         m(i+1)= tt;
%     elseif tt<t0/4*2
%         m(i+1)= t0/4;
%     elseif tt<t0/4*3
%         m(i+1)= t0/4*3 - tt;
%     else
%         m(i+1)=0;
%     end
% end

c=cos(2*pi*fc.*t);                   	% carrier signal
m_n=m/max(abs(m));                   	% normalized message signal
u=(1+a*m_n).*c;                      	% modulated signal
   
r=u;                                    % recieved signal, without noise
y=r.*c;                                 % 

%%% demodulation

w_cutoff = fc/fs/2;
dem = lowpass(y,fc,fs);
dem=dem*2;
dem=(dem-1)/a; 

subplot(3,1,1);
plot(t,m_n);
xlabel('Time')
title('The normalized message signal')

subplot(3,1,2);
plot(t,u);
xlabel('Time')
title('The modulated signal');

subplot(3,1,3);
plot(t,dem);
xlabel('Time');
title('The demodulated signal');

fname = 'prob_03_09(410887040).png';
print (fname, '-dpng'); 



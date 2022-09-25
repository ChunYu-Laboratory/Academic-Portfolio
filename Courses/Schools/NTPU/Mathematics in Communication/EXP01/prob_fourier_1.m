clear all;  % clear all variables
close all;  % close all window of figures


t=(-0.2:0.0001:0.2);

s1 = zeros(size(t));
N1=10;
for n=0:N1
   s1 = s1 + sin((2*n+1)*t)/(2*n+1);
end
s1=s1*4/pi;


s2 = zeros(size(t));
N2=50;
for n=0:N2
   s2 = s2 + sin((2*n+1)*t)/(2*n+1);
end
s2=s2*4/pi;


% add a line for the Fourier series of N=100
s3 = zeros(size(t));
N3=100
for n=0:N3
   s3 = s3 + sin((2*n+1)*t)/(2*n+1);
end
s3=s3*4/pi;

% extra
s4 = zeros(size(t));
N4=500
for n=0:N4
   s4 = s4 + sin((2*n+1)*t)/(2*n+1);
end
s4=s4*4/pi;


s5 = zeros(size(t));
N5=1000
for n=0:N5
   s5 = s5 + sin((2*n+1)*t)/(2*n+1);
end
s5=s5*4/pi;


figure
% Modify the following lines to add a GREEN line for N3
plot(t,s1,'r-',t,s2,'k-.',t,s3,'g--',t,s4,'m-',t,s5,'b:', 'LineWidth', 1);
xlabel('t','fontsize',16,'fontname','Helvetica');
ylabel('x(t)','fontsize',16,'fontname','Helvetica');
title('Fourier Series of x(t) (410887040)','fontsize',16,'fontname','Helvetica'); %<-- Fill your id

% Modify the following line to (1) show N3 in addition, and (2) change the location to top-left
legend(['N=',num2str(N1),'  '; 'N=',num2str(N2),'  '; 'N=',num2str(N3),' '; 'N=',num2str(N4),' '; 'N=',num2str(N5);],'location','northwest');

fname = 'prob_fourier_01(410887040).png';  %<-- Fill your id
print (fname, '-dpng'); 

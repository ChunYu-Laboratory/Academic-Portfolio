% prob 2.1
% graphics_toolkit gnuplot; % for OCTAVE
clear;
close all;

NX1 = 50
X1 = rand(NX1,1); % generate NX uniformly distributed rv
NX2 = 500
X2 = rand(NX2,1); % generate NX uniformly distributed rv
NX3 = 5000
X3 = rand(NX3,1); % generate NX uniformly distributed rv

Y1 = 2 - 2*sqrt(1-X1);  % <=== Modify here
Y2 = 2 - 2*sqrt(1-X2);  % <=== Modify here
Y3 = 2 - 2*sqrt(1-X3);  % <=== Modify here

Nbin=10000  % Split into Nbin equal parts in the range
FY1 = zeros(Nbin,1); % prepare to store the cdf for Nbin bins
FY2 = zeros(Nbin,1); % prepare to store the cdf for Nbin bins
FY3 = zeros(Nbin,1); % prepare to store the cdf for Nbin bins

Ymin=0; % min Y % <=== Modify here
Ymax=2; % max % <=== Modify here

bins = Ymin + (Ymax-Ymin)*(1:Nbin)/Nbin;

for i=1:Nbin
  FY1(i) = length(find(Y1<=bins(i)))/NX1;
  FY2(i) = length(find(Y2<=bins(i)))/NX2;
  FY3(i) = length(find(Y3<=bins(i)))/NX3;
end

figure

idealFY = bins - bins.^2/4;  % <=== ModiFY here

plot(bins,FY1,':r',bins,FY2,'--m',bins,FY3,'-.k',bins,idealFY,'-b');

xlabel('Y','fontsize',16,'fontname','Helvetica');
ylabel('CDF of Y','fontsize',16,'fontname','Helvetica');
title('CDF of Y (410887040)','fontsize',16,'fontname','Helvetica');
legend(['NX1=50   ';'NX2=500  ';'NX3=5000 ';'Ideal CDF'],'location','northwest');
fname = 'prob_02_01(410887040).png';
print (fname, '-dpng');
% prob 2.a03
% graphics_toolkit gnuplot;
clear all;
close all;

N=10000;
M=500;

sig=1;
data_uni=zeros(M,1);

for i=1:M
    x = 6*rand(N,1) -3;
    fx = 1/6*ones(size(x));
    iz = find(abs(x)<=3);
    target = exp(-x.^2/2/sig^2)/sqrt(2*pi)/sig;
    S = sum(target(iz)./fx(iz));
    data_uni(i) = S/N;
end

[fX1,bins1]=hist(data_uni);

data_nor=zeros(M,1);

for i=1:M
    x = sig*randn(N,1);
    fx=exp(-x.^2/2/sig^2)/sqrt(2*pi)/sig;
    iz = find(abs(x)<=3);
    target = exp(-x.^2/2/sig^2)/sqrt(2*pi)/sig;
    S = sum(target(iz)./fx(iz));
    data_nor(i) = S/N;
end

[fX2,bins2]=hist(data_nor);

figure

estimation1 = mean(data_uni);  % compute your estimation here
variance1=var(data_uni);
truevalue=0.9973;
plot(bins1,fX1,"-",'linewidth',2);
hold on;
line([truevalue,truevalue],[0,max(fX1)]);
line([estimation1,estimation1],[0,max(fX1)],'color','red');


xlabel('estimated value','fontsize',16,'fontname','Helvetica');
ylabel('Histogram','fontsize',16,'fontname','Helvetica');
title(['True=',num2str(truevalue),', est by uniform rv=',num2str(estimation1),...
', var=',num2str(variance1),' (410887040)'],'fontname','Helvetica');
fname = 'prob_02_a03_uni(410887040).png';
print (fname, '-dpng'); 



figure

estimation2 = mean(data_nor);  % compute your estimation here
variance2=var(data_nor);
truevalue=0.9973;
plot(bins2,fX2,"-",'linewidth',2);
hold on;
line([truevalue,truevalue],[0,max(fX2)]);
line([estimation2,estimation2],[0,max(fX2)],'color','red');


xlabel('estimated value','fontsize',16,'fontname','Helvetica');
ylabel('Histogram','fontsize',16,'fontname','Helvetica');
title(['True=',num2str(truevalue),', est by normal rv=',num2str(estimation2),...
', var=',num2str(variance2),' (410887040)'],'fontname','Helvetica');
fname = 'prob_02_a03_nor(410887040).png';
print (fname, '-dpng');

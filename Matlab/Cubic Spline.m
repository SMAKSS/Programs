%%%%%Approximate The Top Profile Of The Duck%%%%%%
 
%Initial Values
 
x=[0.9;1.3;1.9;2.1;2.6;3;3.9;4.4;4.7;5;6;7;8;9.2;10.5;11.3;11.6;12;12.6;13;13.3];
y=[1.3;1.5;1.85;2.1;2.6;2.7;2.4;2.15;2.05;2.1;2.25;2.3;2.25;1.95;1.4;0.9;0.7;0.6;0.5;0.4;0.25];

l=length(x);
n=l-1;
 
%Result=[j,x,a,b,c,d]
%j : Index
Result=NuturalCubicSpiline(n,x,y)
a=Result(:,3);
b=Result(:,4);
c=Result(:,5);
d=Result(:,6);
 
%%%Plot The Duck%%%
X=[];
Y=[];
for j=1:n
    tempx=linspace(x(j),x(j+1),1000);
    tempy=a(j)+b(j)*(tempx-x(j))+c(j)*((tempx-x(j)).^2)+d(j)*((tempx-x(j)).^3);
    X=[X;tempx'];
    Y=[Y;tempy'];
end
figure(1);
plot(X,Y,'o-');
title('The Top Profile Of The Duck');
xlabel('x axis');
ylabel('y axis');
legend('y=f(x)');
axis([0 14 0 7]);
grid on   


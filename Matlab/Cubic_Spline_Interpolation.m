% All Right Resevered by the Programmer SMAliKSS
% Cubic Spline Interpolation.
% Intro. Run the code and ENTER the requirements that the code asks.
clear all
clc
format long
digits(8)

syms x
N = [2.7,2.8,2.9,3,0.7 ,0.9 ,1.3 ,1.9 ,2.1 ,2.6 ,3.0 ,3.9 ,4.4 ,4.7 ,5.0 ,6.0 ,7.0 ,8.0 ,9.2 ,10.5 ,11.3 ,11.6 ,12.0 ,12.6 ,13.0 ,13.3,0.75 ,1.3 ,2.4 ,3 ,4 ,4.2 ,4.5 ,5 ,5.6 ,6.2 ,8.6 ,9 ,10 ,10.7 , 11 ,12 ,13 ,13.3,4.8,5,5.5,4.9,6,8,2.7,2.8,2.9,3,1.8,2,2.2];% insert the points as a vector in form for example [x1,x2,x3,...].
a = [2.2,2.22,2.26,2.1,1.2 ,1.3 ,1.5 ,1.85 ,2.1 ,2.6 ,2.7 ,2.4 ,2.15 ,2.05 ,2.1 ,2.25 ,2.3 ,2.25 ,1.95 ,1.4 ,0.9 ,0.7 ,0.6 ,0.5 ,0.4 ,0.1,1.25 ,1 ,1.25 ,1.1 ,1.07 ,1.08 ,.8 ,.5 ,.2 ,0 ,-0.3 ,-0.3 ,-0.2 ,0 ,-0.1 ,0 ,0.1 ,0.1,-4,-4,.1,-4,-3.9,-.2,2.2,2.17,2.14,2.1,1.7,1.4,1.2]; % Insert the function f as a vector in form for example [f(x1),f(x2),f(x3),...].
n = max(size(N));
% q = input('If it is a clamped spline interpolation ENTER #1 otherwise press enter >>>>');
% % clamped
% if q==1
%     diffa = input('Insert the slope in first node >>>>');
%     diffb = input('Insert the slope in last node >>>>');
%  for i=1:n-1;
%     h(i)=N(i+1)-N(i); % i is index of N vector
% end
% A=zeros(n,n);
% A(1,1)=2*h(1);
% A(1,2)=h(1);
% A(n,n)=2*h(n-1);
% A(n,n-1)=h(n-1);
% y(1)=(3*(a(2)-a(1))/h(1))-(3*diffa);
% y(n)=-(3*(a(n)-a(n-1))/h(n-1))+(3*diffb);
% for j=1:n-2;
%     A(j+1,j)=h(j);
%     A(j+1,j+1)=2*(h(j)+h(j+1));
%     A(j+1,j+2)=h(j+1);
%     y(j+1)=((3*(a(j+2)-a(j+1)))/h(j+1))-((3*(a(j+1)-a(j)))/h(j));
% end
% c = A\y';
% for k=1:n-1
%     b(k,1)=((a(k+1)-a(k))/h(k))-((2*c(k)+c(k+1))*h(k))/3;
%     d(k,1)=(c(k+1)-c(k))/(3*h(k));
% end
% % S(t)s are the pieces of the spline
% for t=1:n-1
%     x=N(t):.01:N(t+1);
%     S =a(t)+b(t).*(x-N(t))+c(t).*(x-N(t)).^2+d(t).*(x-N(t)).^3;
%     plot(x,S,'r');
%     hold on
% end
% % natural   
% else
for i=1:n-1;
    h(i)=N(i+1)-N(i);
end
A=zeros(n,n);
A(1,1)=1;
A(n,n)=1;
y(1)=0;
y(n)=0;
for j=1:n-2;
    A(j+1,j)=h(j);
    A(j+1,j+1)=2*(h(j)+h(j+1));
    A(j+1,j+2)=h(j+1);
    y(j+1)=((3*(a(j+2)-a(j+1)))/h(j+1))-((3*(a(j+1)-a(j)))/h(j));
end
c = A\y';
for k=1:n-1
    b(k,1)=((a(k+1)-a(k))/h(k))-((2*c(k)+c(k+1))*h(k))/3;
    d(k,1)=(c(k+1)-c(k))/(3*h(k));
end
% S(t)s are the pieces of the spline
for t=1:n-1
    x=N(t):.01:N(t+1);
    S=a(t)+b(t).*(x-N(t))+c(t).*(x-N(t)).^2+d(t).*(x-N(t)).^3;
    plot(x,S);
    hold on
end
% end


   
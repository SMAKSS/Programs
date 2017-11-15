function rep=NuturalCubicSpiline(n,X,Y)
%A function that approximate the curve y=f(x) using Natural or Free Cubic
%Spilne Interpolation
%Satisfing S"(x_0)=S"(x_n)
%n: The Number of steps
%X: the nodes x_0 < x_1 < ... < x_n
%Y: the function values of X a_0 = f(x_0) , ... , a_n = f(x_n)
 
 
%%%%%Algoritm 3.4%%%%%%%%
 
a=Y;
h=[];
for i=0:n-1
    h=[h;X(i+2)-X(i+1)];
end
 
alpha=[];
for i=1:n-1
    alpha=[alpha;(3/h(i+1))*(a(i+2)-a(i+1))-(3/h(i))*(a(i+1)-a(i))];
end
 
l=[1];
mu=[0];
z=[0];
 
for i=1:n-1
    l=[l;2*(X(i+2)-X(i))-h(i)*mu(i)];
    mu=[mu;h(i+1)/l(i+1)];
    z=[z;(alpha(i)-h(i)*z(i))/l(i+1)];
end
 
l=[l;1];
z=[z;0];
b=zeros(n,1);
c=zeros(n+1,1);
d=zeros(n,1);
c(n+1)=0;
 
for j=n-1:-1:0
    c(j+1)=z(j+1)-mu(j+1)*c(j+2);
    b(j+1)=((a(j+2)-a(j+1))/h(j+1))-h(j+1)*(c(j+2)+3*c(j+1))/3;
    d(j+1)=(c(j+2)-c(j+1))/(3*h(j+1));
end
b=[b;0];
d=[d;0];
j=0:n;
rep=[j',X,a,b,c,d];
end


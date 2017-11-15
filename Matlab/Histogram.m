clc;
clear all;
close all;
im = imread('G:\Multimedia\Picture\coder-boy456789.jpg');
imshow(rgb2gray(im));
im = double(rgb2gray(im));
a= size(im,1);
b= size(im,2);
Hist= zeros(1,256);

for i=1:a
    for j=1:b
       q=im(i,j);
       Hist(q+1)=Hist(q+1)+1;
    end
end
figure
plot(Hist);
for i=1:256
    t(i)=sum(Hist(1:i));
end
plot(t);

for i=1:a
    for j=1:b
        temp=im(i,j);
        imnew(i,j)=t(temp+1);
    end
end
imnew=mat2gray(imnew);
figure
imshow(imnew)
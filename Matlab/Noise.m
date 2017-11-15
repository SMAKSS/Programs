im = imread('C:\Documents and Settings\All Users\Documents\My Pictures\Sample Pictures/Water lilies.jpg');
im = rgb2gray(im);
imshow(im);
figure
F=fft2(im);
T=10;
a=.2;
N=size(im,1);
M=size(im,2);
d=0:M-1;%domain
u=repmat(d,N,1);%repeat
H=(T./(eps+pi*u*a)).*(sin(pi*u*a)).*(exp(-i*pi*u*a));%noise formula
G=F.*H;
% see result
s=mat2gray(real(ifft2(G)));
imshow(s,[]);



N=size(im,1);
M=size(im,2);
d=0:M-1;%domain
u=repmat(d,N,1);%repeat
H=(T./(eps+pi*u*a)).*(sin(pi*u*a)).*(exp(-i*pi*u*a));%noise formula

OriginalImage=G./(H+eps);
T=real(ifft2(OriginalImage));
figure
imshow(T,[]);

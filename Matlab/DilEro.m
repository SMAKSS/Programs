clear all
close all
clc
a=imread('G:\Multimedia\Picture\coder-boy456789.jpg');
figure, imshow(a), title('Original')
a=255-a;
figure, imshow(a), title('Original')
se = strel('disk',7);
sr = strel('square',7);
% show erosion
a_erode_se = imerode(a,se); 
figure, imshow(a_erode_se), title('Eroded')
a_erode_sr = imerode(a,sr); 
figure, imshow(a_erode_sr), title('Eroded')
% show dilation
a_dilate_se = imdilate(a,se);
figure, imshow(a_dilate_se), title('Dilated')
a_dilate_sr = imdilate(a,sr);
figure, imshow(a_dilate_sr), title('Dilated')
%  show opening
a_open_se = imopen(a,se);
figure, imshow(a_open_se), title('open')
a_open_sr = imopen(a,sr);
figure, imshow(a_open_sr), title('open')
% show closing
a_closed_se = imclose(a,se);
figure, imshow(a_closed_se), title('close')
a_closed_sr = imclose(a,sr);
figure, imshow(a_closed_sr), title('close')
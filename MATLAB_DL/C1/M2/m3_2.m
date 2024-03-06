%If we only have few images, or it is hard to align control point
%automatically, it is better to choose it manually.

movingImage = imread("Orion1.png");
fixedImage = imread("Orion2.png");

%we can get x,y value by image viewer but its not efficient
% so we use control point selection tool

cpselect(movingImage,fixedImage)

%we can select the points by clicking on them,
%first click on left(moving) image then click on right(fixed)
%image to match control points, then we export the control point matrices

tform = estgeotform2d(movingPoints,fixedPoints,"similarity");

movingImageT = imwarp(movingImage,tform,"OutputView",imref2d(size(fixedImage)));

%with outputview and imref2d selected as fixed image we make the alignment


montage({fixedImage,movingImageT})




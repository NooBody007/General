setupModule3Quiz

img1 = imread("venice_msi_2021308_lrg.jpg");
img2 = imread("venice_oli_adj.jpg");


cpselect(img2,img1);

[tform, inlierIdx] = estgeotform2d(movingPoints,fixedPoints,"similarity");


warpedImg2 = imwarp(img2,tform,"OutputView",imref2d(size(img1)));

imshowpair(img1,warpedImg2)
img1 = imread("eye1.jpg");
img2 = imread("eye2.jpg");

imshowpair(img1,img2,"montage");

reg = registerEyes(img1,img2)

imtool(reg.RegisteredImage)
imtool(img2)


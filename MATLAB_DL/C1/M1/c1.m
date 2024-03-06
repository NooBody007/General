img1 = imread("stop1.jpg");
img2 = imread("stop2.jpg");

img1_G = im2gray(img1);
img2_G = im2gray(img2);

points_1 = detectSURFFeatures(img1_G);
points_2 = detectSURFFeatures(img2_G);


[feat1, validPoints1] = extractFeatures(img1_G,points_1);
[feat2, validPoints2] = extractFeatures(img2_G,points_2);


matching = matchFeatures(extract_1,extract_2);

matchedPoints1 = validPoints1(matching(:,1),:);
matchedPoints2 = validPoints2(matching(:,2),:);


imshow(img1);
imshow(img2);
showMatchedFeatures(img1,img2,matchedPoints1,matchedPoints2);


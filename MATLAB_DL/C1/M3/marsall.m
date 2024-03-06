
fixedImg = imread("sol_03333_opgs_edr_ncam_NLB_693387385EDR_F0921230NCAM00259M_.JPG");
movingImg = imread("sol_03333_opgs_edr_ncam_NLB_693387301EDR_F0921230NCAM00259M_.JPG");
movingImg2 = imread("sol_03333_opgs_edr_ncam_NLB_693387416EDR_F0921230NCAM00259M_.JPG");
montage({movingImg, fixedImg, movingImg2},"BorderSize",[10 10]);

regleft = registerMarsImages(movingImg,fixedImg);
regright = registerMarsImage2(movingImg2,fixedImg);

movingT1 = regleft.Transformation;
movingT2 = regright.Transformation;

fixedT = projtform2d();

[rows1,columns1, ~] = size(movingImg);
[rows2,columns2, ~ ] = size(movingImg2);

[xlimMoving1, ylimMoving1] = outputLimits(movingT,[1 columns1], [1 rows1]);
[xlimMoving2, ylimMoving2] = outputLimits(movingT2,[1 columns2], [1 rows2]);

[xlimFixed, ylimFixed] = outputLimits(fixedT, [1 columns1], [1 rows1]);

[xlim(1,:), ylim(1,:)] = outputLimits(movingT1,[1 columns1], [1 rows1]);
[xlim(2,:), ylim(2,:)] = outputLimits(movingT2,[1 columns2], [1 rows2]);



xMin = min(xlim(:));
xMax = max(xlim(:));
yMin = min(ylimMoving(:));
yMax = max(ylimMoving(:));

w = round(xMax - xMin)
h = round(yMax - yMin)

panorama = zeros([h, w, 1],"uint8");

blender = vision.AlphaBlender("Operation","Binary Mask","MaskSource","Input port")

panoramaView = imref2d([h w],[xMin xMax],[yMin yMax])


movingWarped1 = imwarp(movingImg, movingT1, "OutputView",panoramaView);
movingWarped2 = imwarp(movingImg2, movingT2, "OutputView",panoramaView);
fixedWarped = imwarp(fixedImg,fixedT,"OutputView",panoramaView);

mask = ones(rows1,columns1,"logical");
mask2 = ones(rows2,columns2,"logical");

fixedMask = imwarp(mask,fixedT,"OutputView",panoramaView);
movingMask = imwarp(mask,movingT1,"OutputView",panoramaView);
movingMask2 = imwarp(mask2,movingT2,"OutputView",panoramaView);

panorama = blender(panorama,movingWarped1,movingMask);
panorama = blender(panorama,fixedWarped,fixedMask);
panorama = blender(panorama,movingWarped2,movingMask2);
imshow(panorama)




img = imread("Data/MathWorks Images/Roadside Ground Cover/No Snow/RoadsideA_1.jpg");

saturationAvg = [];
saturationSTD = [];
imgName = [];


imgHSV = rgb2hsv(img);
imgSaturation = imgHSV(:,:,2);


saturationAvg = [saturationAvg; mean(imgSaturation(:))]
saturationSTD = [saturationSTD; std(imgSaturation(:))]



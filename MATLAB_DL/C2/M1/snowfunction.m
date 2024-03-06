function snowtable = snowfunction(ds)

saturationAvg = [];
saturationSTD = [];
imgName = [];

while hasdata(ds)
    [img,info] = read(ds);
    
    imgHSV = rgb2hsv(img);
    imgSaturation = imgHSV(:,:,2);
    


    saturationAvg = [saturationAvg; mean2(imgSaturation(:))];
    saturationSTD = [saturationSTD; std(imgSaturation(:))];

    [~, name, ext] = fileparts(info.Filename);
    imgName = [imgName;string(name)+string(ext)];
end

label = categorical(ds.Labels);
snowtable = table(label,imgName,saturationAvg,saturationSTD);


end

%Extract predictor features from the images for classification. Extract
%color saturation-based features. In MATLAB pixel saturation values are
%stored in the second color plane of the HSV(Hue-Saturation-Value) color
%space. Since the images are initially in RGB color space, use the code
%below to extract the saturation color plane from a given image. You can
%save an image's saturation values using the code below.

% imgSaturation = imgHSV(:,:,2); % Save the image saturation data
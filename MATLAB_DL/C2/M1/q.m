%Organize Roadside Ground Cover Images into an image datastore Use
%subfolder names "Snow" "No Snow" as labels. Split datastore into training
%and testing subsets as 85% training. How many images are labeled as "Snow"
%in the training datastore.


dsGround = imageDatastore("C:\Users\efpla\OneDrive\Masaüstü\Computer Programming\MATLAB\Computer Vision\Computer Vision for Engineering and Science\Data\Data\MathWorks Images\Roadside Ground Cover", "IncludeSubfolders",true,"LabelSource","foldernames");

[dsTrain, dsTest] = splitEachLabel(dsGround,0.85,"randomize");
countEachLabel(dsTrain)



%Extract predictor features from the images for classification. Extract
%color saturation-based features. In MATLAB pixel saturation values are
%stored in the second color plane of the HSV(Hue-Saturation-Value) color
%space. Since the images are initially in RGB color space, use the code
%below to extract the saturation color plane from a given image. You can
%save an image's saturation values using the code below.

% imgSaturation = imgHSV(:,:,2); % Save the image saturation data

snowtable = snowfunction(dsTrain)



%Create a table for the training dataset that contains a row for each image
%and a column for its "Filename", "Label", "Mean Saturation", "STD".


save snowsaturationfeatures.mat snowtable dsTrain dsTest



gscatter(snowtable.saturationAvg,snowtable.saturationSTD, snowtable.label)
xlabel("Mean Saturation")
ylabel("STD of Saturation")






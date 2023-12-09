#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include "main.h"
#include <string>
#include <cstring>
using namespace std;

//int main()
//{
//    Copying Image Test
//    WriteImage(LoadImage("car.tga"), "carCopy.tga");
//    Task 1
//    MultiplyImage(LoadImage("layer1.tga"), LoadImage("pattern1.tga"));
//    Task 2
//    SubtractImage(LoadImage("car.tga"),LoadImage("layer2.tga"));
//    Task 3
//    ScreenImage(MultiplyImageStored(LoadImage("layer1.tga"), LoadImage("pattern2.tga")),LoadImage("text.tga"));
//    Task 4
//    SubtractImage(MultiplyImageStored(LoadImage("layer2.tga"), LoadImage("circles.tga")),LoadImage("pattern2.tga"));
//    Task 5
//    OverlayImage(LoadImage("layer1.tga"), LoadImage("pattern1.tga"));
//    Task 6
//    AddColor(LoadImage("car.tga"),0,200,0);
//    Task 7
//    MultiplyColor(LoadImage("car.tga"),0,1,4);
//    Task 8
//    SeparateColor(LoadImage("car.tga"));
//    Task 9
//    CombineColor(LoadImage("layer_blue.tga"), LoadImage("layer_green.tga"), LoadImage("layer_red.tga"));
//    Task 10
//    FlipImage(LoadImage("text2.tga"));
//    return 0;
//}
//Test 1
//g++ --std=c++11 main.cpp -o test
//./test output/part1.tga input/layer1.tga multiply input/pattern1.tga
//Test 2
//test output/part2.tga input/car.tga subtract input/layer2.tga
//Test 3
//test output/part3.tga input/layer1.tga multiply input/pattern2.tga screen input/text.tga
//Test 4
// test output/part4.tga input/layer2.tga multiply input/circles.tga subtract input/pattern2.tga
//Test 5
// test output/part5.tga input/layer1.tga overlay input/pattern1.tga
//Test 6
// test output/part6.tga input/car.tga addgreen 200
//Test 7
// test output/part7.tga input/car.tga scalered 4 scaleblue 0
//Test 8
// test output/part8.tga input/car.tga separate
//Test 9
// test output/part9.tga input/layer_red.tga combine input/layer_blue.tga input/layer_green.tga
//Test 10
// test output/part10.tga input/text2.tga flip
int main(int argc, const char* argv[])
{
    bool processDone = false;
    bool errorRead = false;
    if(argc == 1 || strcmp(argv[1], "--help") == 0)
    {
        cout << "Project 2: Image Processing, Spring 2023" << endl;
        errorRead = true;
    }
    else
    {
        try
        {
            LoadImage(argv[2]);
            if(LoadImage(argv[2]).imageSize < 100)
            {
                throw runtime_error("error");
            }
        }
        catch(...)
        {
            cout << "Invalid file name." << endl;
            errorRead = true;
        }
    }
    string outputFileName = argv[1];
    for(int i = 3; i < argc; i++)
    {
//        if(!errorRead)
//        {
//            Image inputtedImage;
//            try
//            {
//                LoadImage(argv[i]);
//                inputtedImage = LoadImage(argv[i]);
//            }
//            catch(...)
//            {
//                cout << "Invalid file name." << endl;
//                break;
//            }
//        }
        if(errorRead)
        {
            break;
        }
        if(strcmp(argv[i], "multiply") == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                string imageOneString = argv[i];
                if(LoadImage(imageOneString).imageSize < 100)
                {
                    throw runtime_error("error");
                }
            }
            catch(...)
            {
                cout << "Invalid argument, invalid file name." << endl;
                break;
            }
            if(processDone)
            {
                cout << "Multiplying " << argv[i] << " and " << "previous step" << endl;
                string imageOneString = argv[i];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(outputFileName);
                Image combinedImage = MultiplyImageStored(imageOne,imageTwo);
                WriteImage(combinedImage,outputFileName);
                WriteImage(combinedImage,outputFileName);
            }
            else
            {
                cout << "Multiplying " << argv[i] << " and " << argv[i-2] << endl;
                string imageOneString = argv[i];
                string imageTwoString = argv[i-2];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(argv[i-2]);
                Image combinedImage = MultiplyImageStored(imageOne,imageTwo);
                WriteImage(combinedImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("subtract",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                string imageOneString = argv[i];
                if(LoadImage(imageOneString).imageSize < 100)
                {
                    throw runtime_error("error");
                }
            }
            catch(...)
            {
                cout << "Invalid argument, invalid file name." << endl;
                break;
            }
            if(processDone)
            {
                cout << "Subtracting " << argv[i] << " and " << "previous step" << endl;
                string imageOneString = argv[i];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(outputFileName);
                Image combinedImage = SubtractImage(imageTwo,imageOne);
                WriteImage(combinedImage,outputFileName);
            }
            else
            {
                cout << "Subtracting " << argv[i] << " and " << argv[i-2] << endl;
                string imageOneString = argv[i];
                string imageTwoString = argv[i-2];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(argv[i-2]);
                Image combinedImage = SubtractImage(imageTwo,imageOne);
                WriteImage(combinedImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("screen",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                string imageOneString = argv[i];
                if(LoadImage(imageOneString).imageSize < 100)
                {
                    throw runtime_error("error");
                }
            }
            catch(...)
            {
                cout << "Invalid argument, invalid file name." << endl;
                break;
            }
            if(processDone)
            {
                cout << "Screening " << argv[i] << " and " << "previous step" << endl;
                string imageOneString = argv[i];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(outputFileName);
                Image combinedImage = ScreenImage(imageOne,imageTwo);
                WriteImage(combinedImage,outputFileName);
            }
            else
            {
                cout << "Screening " << argv[i] << " and " << argv[i-2] << endl;
                string imageOneString = argv[i];
                string imageTwoString = argv[i-2];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(argv[i-2]);
                Image combinedImage = ScreenImage(imageOne,imageTwo);
                WriteImage(combinedImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("overlay", argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                string imageOneString = argv[i];
                if(LoadImage(imageOneString).imageSize < 100)
                {
                    throw runtime_error("error");
                }
            }
            catch(...)
            {
                cout << "Invalid argument, invalid file name." << endl;
                break;
            }
            if(processDone)
            {
                cout << "Overlaying " << argv[i] << " and " << "previous step" << endl;
                string imageOneString = argv[i];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(outputFileName);
                Image combinedImage = OverlayImage(imageOne,imageTwo);
                WriteImage(combinedImage,outputFileName);
            }
            else
            {
                cout << "Overlaying " << argv[i] << " and " << argv[i-2] << endl;
                string imageOneString = argv[i];
                string imageTwoString = argv[i-2];
                Image imageOne = LoadImage(argv[i]);
                Image imageTwo = LoadImage(argv[i-2]);
                Image combinedImage = OverlayImage(imageTwo,imageOne);
                WriteImage(combinedImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("addblue",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                int valueAdd = stoi(argv[i]);
            }
            catch(...)
            {
                cout << "Invalid argument, expected number." << endl;
                break;
            }
            int valueAdd = stoi(argv[i]);
            if(processDone)
            {
                cout << "Adding " << valueAdd << " to blue channel of previous step" << endl;
                Image imageOne = LoadImage(outputFileName);
                Image newImage = AddColor(imageOne,valueAdd,0,0);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Adding " << valueAdd << " to blue channel of " << argv[i-2] << endl;
                string imageOneString = argv[i - 2];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = AddColor(imageOne,valueAdd,0,0);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("addgreen",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                int valueAdd = stoi(argv[i]);
            }
            catch(...)
            {
                cout << "Invalid argument, expected number." << endl;
                break;
            }
            int valueAdd = stoi(argv[i]);
            if(processDone)
            {
                cout << "Adding " << valueAdd << " to green channel of previous step" << endl;
                Image imageOne = LoadImage(outputFileName);
                Image newImage = AddColor(imageOne,0,valueAdd,0);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Adding " << valueAdd << " to green channel of " << argv[i-2] << endl;
                string imageOneString = argv[i - 2];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = AddColor(imageOne,0,valueAdd,0);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("addred",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                int valueAdd = stoi(argv[i]);
            }
            catch(...)
            {
                cout << "Invalid argument, expected number." << endl;
                break;
            }
            int valueAdd = stoi(argv[i]);
            if(processDone)
            {
                cout << "Adding " << valueAdd << " to red channel of previous step" << endl;
                Image imageOne = LoadImage(outputFileName);
                Image newImage = AddColor(imageOne,0,0,valueAdd);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Adding " << valueAdd << " to red channel of " << argv[i-2] << endl;
                string imageOneString = argv[i - 2];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = AddColor(imageOne,0,0,valueAdd);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("scaleblue",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                int scaleValue = stoi(argv[i]);
            }
            catch(...)
            {
                cout << "Invalid argument, expected number." << endl;
                break;
            }
            float scaleValue = stoi(argv[i]);
            if(processDone)
            {
                cout << "Scaling the blue channel of previous step by " << scaleValue << endl;
                Image imageOne = LoadImage(outputFileName);
                Image newImage = MultiplyColor(imageOne,scaleValue,1,1);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Scaling the blue channel of " << argv[i - 2] << " by " << scaleValue << endl;
                string imageOneString = argv[i - 2];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = MultiplyColor(imageOne,scaleValue,1,1);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("scalegreen",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                int scaleValue = stoi(argv[i]);
            }
            catch(...)
            {
                cout << "Invalid argument, expected number." << endl;
                break;
            }
            float scaleValue = stoi(argv[i]);
            if(processDone)
            {
                cout << "Scaling the green channel of previous step by " << scaleValue << endl;
                Image imageOne = LoadImage(outputFileName);
                Image newImage = MultiplyColor(imageOne,1,scaleValue,1);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Scaling the green channel of " << argv[i - 2] << " by " << scaleValue << endl;
                string imageOneString = argv[i - 2];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = MultiplyColor(imageOne,1,scaleValue,1);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("scalered",argv[i]) == 0)
        {
            i++;
            try
            {
                string imageOneString = argv[i];
            }
            catch(...)
            {
                cout << "Missing argument." << endl;
                break;
            }
            try
            {
                int scaleValue = stoi(argv[i]);
            }
            catch(...)
            {
                cout << "Invalid argument, expected number." << endl;
                break;
            }
            float scaleValue = stoi(argv[i]);
            if(processDone)
            {
                cout << "Scaling the red channel of previous step by " << scaleValue << endl;
                Image imageOne = LoadImage(outputFileName);
                Image newImage = MultiplyColor(imageOne,1,1,scaleValue);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Scaling the red channel of " << argv[i - 2] << " by " << scaleValue << endl;
                string imageOneString = argv[i - 2];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = MultiplyColor(imageOne,1,1,scaleValue);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("separate", argv[i]) == 0)
        {
            if(processDone)
            {
                cout << "Separating the colors into different files" << endl;
                Image imageOne = LoadImage(outputFileName);
                SeparateColor(imageOne);
            }
            else
            {
                cout << "Separating the colors into different files" << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(imageOneString);
                SeparateColor(imageOne);
            }
            processDone = true;
        }
        else if(strcmp("onlyblue",argv[i]) == 0)
        {
            if(processDone)
            {
                cout << "Isolating the blue channel of previous step" << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(outputFileName);
                Image newImage = SeperateBlue(imageOne);
                WriteImage(newImage, outputFileName);
            }
            else
            {
                cout << "Isolating the blue channel of " << argv[i - 1] << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = SeperateBlue(imageOne);
                WriteImage(newImage, outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("onlygreen",argv[i]) == 0)
        {
            if(processDone)
            {
                cout << "Isolating the green channel of previous step" << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(outputFileName);
                Image newImage = SeperateGreen(imageOne);
                WriteImage(newImage, outputFileName);
            }
            else
            {
                cout << "Isolating the green channel of " << argv[i - 1] << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = SeperateGreen(imageOne);
                WriteImage(newImage, outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("onlyred",argv[i]) == 0)
        {
            if(processDone)
            {
                cout << "Isolating the red channel of previous step" << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(outputFileName);
                Image newImage = SeperateRed(imageOne);
                WriteImage(newImage, outputFileName);
            }
            else
            {
                cout << "Isolating the red channel of " << argv[i - 1] << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = SeperateRed(imageOne);
                WriteImage(newImage, outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("combine", argv[i]) == 0)
        {
            i++;
            if(processDone)
            {
                cout << "Combining images with previous step" << endl;
                string imageOneString = argv[i];
                string imageTwoString = argv[i + 1];
                Image imageOne = LoadImage(imageOneString);
                Image imageTwo = LoadImage(imageTwoString);
                Image imageThree = LoadImage(outputFileName);
                Image newImage = CombineColor(imageOne,imageTwo,imageThree);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Combining images " << endl;
                string imageOneString = argv[i];
                string imageTwoString = argv[i + 1];
                string imageThreeString = argv[i - 2];
                Image imageOne = LoadImage(imageOneString);
                Image imageTwo = LoadImage(imageTwoString);
                Image imageThree = LoadImage(imageThreeString);
                Image newImage = CombineColor(imageOne,imageTwo,imageThree);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else if(strcmp("flip", argv[i]) == 0)
        {
            if(processDone)
            {
                cout << "Flipping output of previous step" << endl;
                Image imageOne = LoadImage(outputFileName);
                Image newImage = FlipImage(imageOne);
                WriteImage(newImage,outputFileName);
            }
            else
            {
                cout << "Flipping " << argv[i - 1] << endl;
                string imageOneString = argv[i - 1];
                Image imageOne = LoadImage(imageOneString);
                Image newImage = FlipImage(imageOne);
                WriteImage(newImage,outputFileName);
            }
            processDone = true;
        }
        else
        {
            cout << "Invalid method name." << endl;
        }
    }
   if(processDone)
   {
       cout << " and saving output to " << outputFileName << endl;
   }
    return 0;
}
Image LoadImage(string fileName)
{
    ifstream testFile(fileName, ios::in | ios::binary);
//    if(testFile.is_open())
//    {
//        cout << "I opened" << endl;
//    }
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
    Image testImage;
    testFile.read(reinterpret_cast<char*>(&idLength),1);
    testFile.read(reinterpret_cast<char*>(&colorMapType),1);
    testFile.read(reinterpret_cast<char*>(&dataTypeCode), 1);
    testFile.read(reinterpret_cast<char*>(&colorMapOrigin),2);
    testFile.read(reinterpret_cast<char*>(&colorMapLength),2);
    testFile.read(reinterpret_cast<char*>(&colorMapDepth),1);
    testFile.read(reinterpret_cast<char*>(&xOrigin),2);
    testFile.read(reinterpret_cast<char*>(&yOrigin),2);
    testFile.read(reinterpret_cast<char*>(&width),2);
    testFile.read(reinterpret_cast<char*>(&height),2);
    testFile.read(reinterpret_cast<char*>(&bitsPerPixel),1);
    testFile.read(reinterpret_cast<char*>(&imageDescriptor),1);
    int imageSize = height * width;
    for(int i = 0; i < imageSize; i++)
    {
        Image::Pixel tempPixel;
        testFile.read(reinterpret_cast<char*>(&tempPixel.blue),1);
        testFile.read(reinterpret_cast<char*>(&tempPixel.green),1);
        testFile.read(reinterpret_cast<char*>(&tempPixel.red),1);
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    return testImages;
}
void WriteImage(Image testImage, string fileName)
{
    ofstream testFileCopy(fileName, ios::out | ios::binary);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.idLength),1);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.colorMapType),1);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.dataTypeCode), 1);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.colorMapOrigin),2);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.colorMapLength),2);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.colorMapDepth),1);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.xOrigin),2);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.yOrigin),2);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.width),2);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.height),2);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.bitsPerPixel),1);
    testFileCopy.write(reinterpret_cast<char*>(&testImage.testHeader.imageDescriptor),1);
    for(int i = 0; i < testImage.imageSize; i++)
    {
        testFileCopy.write(reinterpret_cast<char*>(&testImage.pixels.at(i).blue),1);
        testFileCopy.write(reinterpret_cast<char*>(&testImage.pixels.at(i).green),1);
        testFileCopy.write(reinterpret_cast<char*>(&testImage.pixels.at(i).red),1);
    }
}

Image::Image()
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
    vector<Pixel> pixels;
    int imageSize;
}

Image::Image(char idLength, char colorMapType, char dataTypeCode, short colorMapOrigin, short colorMapLength,
             char colorMapDepth, short xOrigin, short yOrigin, short width, short height, char bitsPerPixel,
             char imageDescriptor, int imageSize, vector<Pixel> pixels)
             {
    testHeader.idLength = idLength;
    testHeader.colorMapType = colorMapType;
    testHeader.dataTypeCode = dataTypeCode;
    testHeader.colorMapOrigin = colorMapOrigin;
    testHeader.colorMapLength = colorMapLength;
    testHeader.colorMapDepth = colorMapDepth;
    testHeader.xOrigin = xOrigin;
    testHeader.yOrigin = yOrigin;
    testHeader.width = width;
    testHeader.height = height;
    testHeader.bitsPerPixel = bitsPerPixel;
    testHeader.imageDescriptor = imageDescriptor;
    this->imageSize = imageSize;
    this->pixels = pixels;
}
void AddImage(Image topLayer, Image bottomLayer)
{

}
Image SubtractImage(Image topLayer, Image bottomLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        int bluePixel = topLayer.pixels.at(i).blue - bottomLayer.pixels.at(i).blue;
        if(bluePixel > 0)
        {
            tempPixel.blue = (unsigned char)bluePixel;
        }
        else
        {
            tempPixel.blue = (unsigned char)0;
        }
        int greenPixel = topLayer.pixels.at(i).green - bottomLayer.pixels.at(i).green;
        if(greenPixel > 0)
        {
            tempPixel.green = (unsigned char)greenPixel;
        }
        else
        {
            tempPixel.green = (unsigned char)0;
        }
        int redPixel = topLayer.pixels.at(i).red - bottomLayer.pixels.at(i).red;
        if(redPixel > 0)
        {
            tempPixel.red = (unsigned char)redPixel;
        }
        else
        {
            tempPixel.red = (unsigned char)0;
        }
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    return testImages;
    //WriteImage(testImages,"taskFour.tga");
}
void MultiplyImage(Image topLayer, Image bottomLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        float normalizedBluePixel = (float)(topLayer.pixels.at(i).blue) / 255;
        normalizedBluePixel = ((float)(bottomLayer.pixels.at(i).blue) / 255) * normalizedBluePixel;
        normalizedBluePixel = (normalizedBluePixel * 255) + 0.5f;
        tempPixel.blue = (unsigned char)normalizedBluePixel;
        float normalizedGreenPixel = (float)(topLayer.pixels.at(i).green) / 255;
        normalizedGreenPixel = ((float)(bottomLayer.pixels.at(i).green) / 255) * normalizedGreenPixel;
        normalizedGreenPixel = (normalizedGreenPixel * 255) + 0.5f;
        tempPixel.green = (unsigned char)normalizedGreenPixel;
        float normalizedRedPixel = (float)(topLayer.pixels.at(i).red) / 255;
        normalizedRedPixel = ((float)(bottomLayer.pixels.at(i).red) / 255) * normalizedRedPixel;
        normalizedRedPixel = (normalizedRedPixel * 255) + 0.5f;
        tempPixel.red = (unsigned char)normalizedRedPixel;
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    WriteImage(testImages,"taskOne.tga");
}
Image MultiplyImageStored(Image topLayer, Image bottomLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        float normalizedBluePixel = (float)(topLayer.pixels.at(i).blue) / 255;
        normalizedBluePixel = ((float)(bottomLayer.pixels.at(i).blue) / 255) * normalizedBluePixel;
        normalizedBluePixel = (normalizedBluePixel * 255) + 0.5f;
        tempPixel.blue = (unsigned char)normalizedBluePixel;
        float normalizedGreenPixel = (float)(topLayer.pixels.at(i).green) / 255;
        normalizedGreenPixel = ((float)(bottomLayer.pixels.at(i).green) / 255) * normalizedGreenPixel;
        normalizedGreenPixel = (normalizedGreenPixel * 255) + 0.5f;
        tempPixel.green = (unsigned char)normalizedGreenPixel;
        float normalizedRedPixel = (float)(topLayer.pixels.at(i).red) / 255;
        normalizedRedPixel = ((float)(bottomLayer.pixels.at(i).red) / 255) * normalizedRedPixel;
        normalizedRedPixel = (normalizedRedPixel * 255) + 0.5f;
        tempPixel.red = (unsigned char)normalizedRedPixel;
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    return testImages;
}
Image ScreenImage(Image topLayer, Image bottomLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        float normalizedBluePixel = 1 - ((float)(topLayer.pixels.at(i).blue) / 255);
        normalizedBluePixel = (1 - ((float)(bottomLayer.pixels.at(i).blue) / 255)) * normalizedBluePixel;
        normalizedBluePixel = 1 - normalizedBluePixel;
        normalizedBluePixel = (normalizedBluePixel * 255) + 0.5f;
        tempPixel.blue = normalizedBluePixel;
        float normalizedGreenPixel = 1 - ((float)(topLayer.pixels.at(i).green) / 255);
        normalizedGreenPixel = (1 - ((float)(bottomLayer.pixels.at(i).green) / 255)) * normalizedGreenPixel;
        normalizedGreenPixel = 1 - normalizedGreenPixel;
        normalizedGreenPixel = (normalizedGreenPixel * 255) + 0.5f;
        tempPixel.green = normalizedGreenPixel;
        float normalizedRedPixel = 1 - ((float)(topLayer.pixels.at(i).red) / 255);
        normalizedRedPixel = (1 - ((float)(bottomLayer.pixels.at(i).red) / 255)) * normalizedRedPixel;
        normalizedRedPixel = 1 - normalizedRedPixel;
        normalizedRedPixel = (normalizedRedPixel * 255) + 0.5f;
        tempPixel.red = normalizedRedPixel;
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    //WriteImage(testImages,"taskThree.tga");
    return testImages;
}
Image OverlayImage(Image topLayer, Image bottomLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        float normalizedBluePixel = (float)(bottomLayer.pixels.at(i).blue) / 255;
        if(normalizedBluePixel <= 0.5)
        {
            normalizedBluePixel = normalizedBluePixel * (float)(topLayer.pixels.at(i).blue) / 255;
            normalizedBluePixel = normalizedBluePixel * 2;
            normalizedBluePixel = (normalizedBluePixel * 255) + 0.5f;
            tempPixel.blue = (unsigned char)normalizedBluePixel;
        }
        else if(normalizedBluePixel > 0.5)
        {
            normalizedBluePixel = 0;
            normalizedBluePixel = 1 - ((float)(topLayer.pixels.at(i).blue) / 255);
            normalizedBluePixel = (1 - ((float)(bottomLayer.pixels.at(i).blue) / 255)) * normalizedBluePixel;
            normalizedBluePixel = normalizedBluePixel * 2;
            normalizedBluePixel = 1 - normalizedBluePixel;
            normalizedBluePixel = (normalizedBluePixel * 255) + 0.5f;
            tempPixel.blue = (unsigned char)normalizedBluePixel;
        }
        float normalizedGreenPixel = (float)(bottomLayer.pixels.at(i).green) / 255;
        if(normalizedGreenPixel <= 0.5)
        {
            normalizedGreenPixel = normalizedGreenPixel * (float)(topLayer.pixels.at(i).green) / 255;
            normalizedGreenPixel = normalizedGreenPixel * 2;
            normalizedGreenPixel = (normalizedGreenPixel * 255) + 0.5f;
            tempPixel.green = (unsigned char)normalizedGreenPixel;
        }
        else if(normalizedGreenPixel > 0.5)
        {
            normalizedGreenPixel = 0;
            normalizedGreenPixel = 1 - ((float)(topLayer.pixels.at(i).green) / 255);
            normalizedGreenPixel = (1 - ((float)(bottomLayer.pixels.at(i).green) / 255)) * normalizedGreenPixel;
            normalizedGreenPixel = normalizedGreenPixel * 2;
            normalizedGreenPixel = 1 - normalizedGreenPixel;
            normalizedGreenPixel = (normalizedGreenPixel * 255) + 0.5f;
            tempPixel.green = (unsigned char)normalizedGreenPixel;
        }
        float normalizedRedPixel = (float)(bottomLayer.pixels.at(i).red) / 255;
        if(normalizedRedPixel <= 0.5)
        {
            normalizedRedPixel = normalizedRedPixel * (float)(topLayer.pixels.at(i).red) / 255;
            normalizedRedPixel = normalizedRedPixel * 2;
            normalizedRedPixel = (normalizedRedPixel * 255) + 0.5f;
            tempPixel.red = (unsigned char)normalizedRedPixel;
        }
        else if(normalizedRedPixel > 0.5)
        {
            normalizedRedPixel = 0;
            normalizedRedPixel = 1 - ((float)(topLayer.pixels.at(i).red) / 255);
            normalizedRedPixel = (1 - ((float)(bottomLayer.pixels.at(i).red) / 255)) * normalizedRedPixel;
            normalizedRedPixel = normalizedRedPixel * 2;
            normalizedRedPixel = 1 - normalizedRedPixel;
            normalizedRedPixel = (normalizedRedPixel * 255) + 0.5f;
            tempPixel.red = (unsigned char)normalizedRedPixel;
        }
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    //WriteImage(testImages,"taskFive.tga");
    return testImages;
}
Image AddColor(Image topLayer, int blueScale, int greenScale, int redScale)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        int bluePixel = topLayer.pixels.at(i).blue;
        bluePixel = bluePixel + blueScale;
        if(bluePixel > 255)
        {
            bluePixel = 255;
        }
        tempPixel.blue = (unsigned char)bluePixel;
        int greenPixel = topLayer.pixels.at(i).green;
        greenPixel = greenPixel + greenScale;
        if(greenPixel > 255)
        {
            greenPixel = 255;
        }
        tempPixel.green = (unsigned char)greenPixel;
        int redPixel = topLayer.pixels.at(i).red;
        redPixel = redPixel + redScale;
        if(redPixel > 255)
        {
            redPixel = 255;
        }
        tempPixel.red = (unsigned char)redPixel;
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    //WriteImage(testImages,"taskSix.tga");
    return testImages;
}
Image MultiplyColor(Image topLayer, float blueScale, float greenScale, float redScale)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = 0; i < topLayer.imageSize; i++) {
        Image::Pixel tempPixel;
        float normalizedBluePixel = (float) (topLayer.pixels.at(i).blue) / 255;
        normalizedBluePixel = normalizedBluePixel * blueScale;
        normalizedBluePixel = (normalizedBluePixel * 255) + 0.5f;
        if(normalizedBluePixel > 255)
        {
            normalizedBluePixel = 255;
        }
        tempPixel.blue = (unsigned char)normalizedBluePixel;
        float normalizedGreenPixel = (float) (topLayer.pixels.at(i).green) / 255;
        normalizedGreenPixel = normalizedGreenPixel * greenScale;
        normalizedGreenPixel = (normalizedGreenPixel * 255) + 0.5f;
        if(normalizedGreenPixel > 255)
        {
            normalizedGreenPixel = 255;
        }
        tempPixel.green = (unsigned char)normalizedGreenPixel;
        float normalizedRedPixel = (float) (topLayer.pixels.at(i).red) / 255;
        normalizedRedPixel = normalizedRedPixel * redScale;
        normalizedRedPixel = (normalizedRedPixel * 255) + 0.5f;
        if(normalizedRedPixel > 255)
        {
            normalizedRedPixel = 255;
        }
        tempPixel.red = (unsigned char)normalizedRedPixel;
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    //WriteImage(testImages,"taskSeven.tga");
    return testImages;
}
void SeparateColor(Image topLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImageBlue;
    Image testImageGreen;
    Image testImageRed;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = topLayer.pixels.at(i).blue;
        tempPixel.red = topLayer.pixels.at(i).blue;
        tempPixel.green = topLayer.pixels.at(i).blue;
        testImageBlue.pixels.push_back(tempPixel);
    }
    Image blue(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImageBlue.pixels);
    WriteImage(blue,"output/part8_b.tga");
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = topLayer.pixels.at(i).green;
        tempPixel.red = topLayer.pixels.at(i).green;
        tempPixel.green = topLayer.pixels.at(i).green;
        testImageGreen.pixels.push_back(tempPixel);
    }
    Image green(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImageGreen.pixels);
    WriteImage(green,"output/part8_g.tga");
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = topLayer.pixels.at(i).red;
        tempPixel.red = topLayer.pixels.at(i).red;
        tempPixel.green = topLayer.pixels.at(i).red;
        testImageRed.pixels.push_back(tempPixel);
    }
    Image red(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                imageDescriptor,imageSize,testImageRed.pixels);
    WriteImage(red,"output/part8_r.tga");
}
Image SeperateBlue(Image topLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImageBlue;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = topLayer.pixels.at(i).blue;
        tempPixel.red = topLayer.pixels.at(i).blue;
        tempPixel.green = topLayer.pixels.at(i).blue;
        testImageBlue.pixels.push_back(tempPixel);
    }
    Image blue(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
               colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
               imageDescriptor,imageSize,testImageBlue.pixels);
    return blue;
}
Image SeperateGreen(Image topLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImageGreen;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = topLayer.pixels.at(i).green;
        tempPixel.red = topLayer.pixels.at(i).green;
        tempPixel.green = topLayer.pixels.at(i).green;
        testImageGreen.pixels.push_back(tempPixel);
    }
    Image green(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                imageDescriptor,imageSize,testImageGreen.pixels);
    return green;
}
Image SeperateRed(Image topLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImageRed;
    for(int i = 0; i < topLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = topLayer.pixels.at(i).red;
        tempPixel.red = topLayer.pixels.at(i).red;
        tempPixel.green = topLayer.pixels.at(i).red;
        testImageRed.pixels.push_back(tempPixel);
    }
    Image red(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
              colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
              imageDescriptor,imageSize,testImageRed.pixels);
    return red;
}
Image CombineColor(Image blueLayer, Image greenLayer, Image redLayer)
{
    char idLength = blueLayer.testHeader.idLength;
    char colorMapType = blueLayer.testHeader.colorMapType;
    char dataTypeCode = blueLayer.testHeader.dataTypeCode;
    short colorMapOrigin = blueLayer.testHeader.colorMapOrigin;
    short colorMapLength = blueLayer.testHeader.colorMapLength;
    char colorMapDepth = blueLayer.testHeader.colorMapDepth;
    short xOrigin = blueLayer.testHeader.xOrigin;
    short yOrigin = blueLayer.testHeader.yOrigin;
    short width = blueLayer.testHeader.width;
    short height = blueLayer.testHeader.height;
    char bitsPerPixel = blueLayer.testHeader.bitsPerPixel;
    char imageDescriptor = blueLayer.testHeader.imageDescriptor;
    int imageSize = blueLayer.imageSize;
    Image testImage;
    for(int i = 0; i < blueLayer.imageSize; i++)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = blueLayer.pixels.at(i).blue;
        tempPixel.green = greenLayer.pixels.at(i).green;
        tempPixel.red = redLayer.pixels.at(i).red;
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    //WriteImage(testImages,"taskNine.tga");
    return testImages;
}
Image FlipImage(Image topLayer)
{
    char idLength = topLayer.testHeader.idLength;
    char colorMapType = topLayer.testHeader.colorMapType;
    char dataTypeCode = topLayer.testHeader.dataTypeCode;
    short colorMapOrigin = topLayer.testHeader.colorMapOrigin;
    short colorMapLength = topLayer.testHeader.colorMapLength;
    char colorMapDepth = topLayer.testHeader.colorMapDepth;
    short xOrigin = topLayer.testHeader.xOrigin;
    short yOrigin = topLayer.testHeader.yOrigin;
    short width = topLayer.testHeader.width;
    short height = topLayer.testHeader.height;
    char bitsPerPixel = topLayer.testHeader.bitsPerPixel;
    char imageDescriptor = topLayer.testHeader.imageDescriptor;
    int imageSize = topLayer.imageSize;
    Image testImage;
    for(int i = topLayer.imageSize - 1; i >= 0; i--)
    {
        Image::Pixel tempPixel;
        tempPixel.blue = topLayer.pixels.at(i).blue;
        tempPixel.green = topLayer.pixels.at(i).green;
        tempPixel.red = topLayer.pixels.at(i).red;
        testImage.pixels.push_back(tempPixel);
    }
    Image testImages(idLength,colorMapType,dataTypeCode,colorMapOrigin, colorMapLength,
                     colorMapDepth,xOrigin,yOrigin,width,height,bitsPerPixel,
                     imageDescriptor,imageSize,testImage.pixels);
    //WriteImage(testImages,"taskTen.tga");
    return testImages;
}


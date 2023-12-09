//
// Created by chlaw on 3/24/2023.
//
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include "main.h"
using namespace std;

class Image
{
public:
    struct Header
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
    };
//    char idLength;
//    char colorMapType;
//    char dataTypeCode;
//    short colorMapOrigin;
//    short colorMapLength;
//    char colorMapDepth;
//    short xOrigin;
//    short yOrigin;
//    short width;
//    short height;
//    char bitsPerPixel;
//    char imageDescriptor;
    struct Pixel
    {
        unsigned char blue;
        unsigned char green;
        unsigned char red;
    };
    vector<Pixel> pixels;
    int imageSize;
    Header testHeader;
    Image();
    Image(char idLength, char colorMapType, char dataTypeCode, short colorMapOrigin, short colorMapLength, char colorMapDepth,
          short xOrigin, short yOrigin, short width, short height, char bitsPerPixel, char imageDescriptor, int imageSize,
          vector<Pixel> pixels);
};
Image LoadImage(string fileName);
void WriteImage(Image testImage, string fileName);
void AddImage(Image imageOne, Image imageTwo);
Image SubtractImage(Image topLayer, Image bottomLayer);
void MultiplyImage(Image topLayer, Image bottomLayer);
Image MultiplyImageStored(Image topLayer, Image bottomLayer);
Image ScreenImage(Image topLayer, Image bottomLayer);
Image OverlayImage(Image topLayer, Image bottomLayer);
Image AddColor(Image topLayer, int blueScale, int greenScale, int redScale);
Image MultiplyColor(Image topLayer, float blueScale, float greenScale, float redScale);
void SeparateColor(Image topLayer);
Image SeperateBlue(Image topLayer);
Image SeperateGreen(Image topLayer);
Image SeperateRed(Image topLayer);
Image CombineColor(Image blueLayer, Image greenLayer, Image redLayer);
Image FlipImage(Image topLayer);
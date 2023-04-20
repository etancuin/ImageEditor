//
//  ImageEditor.cpp
//  ImageEditor
//
//  Created by Ethan Quinn on 3/4/23.
//

#include "ImageEditor.h"
using namespace std;

ImageEditor::ImageEditor(string inFileName)
{
    Picture newPic(inFileName);
    pic = newPic;
}
void ImageEditor::flipVertical()
{
    for(int i = 0; i < pic.width(); i++)
    {
        for(int j = 0; j < pic.height() / 2; j++)
        {
            swapPixels(i, j, i, pic.height() - j - 1);
        }
    }
}
void ImageEditor::flipHorizontal()
{
    for(int i = 0; i < pic.height(); i++)
    {
        for(int j = 0; j < pic.width() / 2; j++)
        {
            swapPixels(j, i, pic.width() - j - 1, i);
        }
    }
}
void ImageEditor::doubleSize()
{
    Picture picOut(pic.width() * 2, pic.height() * 2);
    int xOut = 0;
    int yOut = 0;
    for(int i = 0; i < pic.width(); i++)
    {
        yOut = 0;
        for(int j = 0; j < pic.height(); j++)
        {
            picOut.set(xOut, yOut, pic.red(i, j), pic.green(i, j), pic.blue(i, j));
            picOut.set(xOut + 1, yOut, pic.red(i, j), pic.green(i, j), pic.blue(i, j));
            picOut.set(xOut, yOut + 1, pic.red(i, j), pic.green(i, j), pic.blue(i, j));
            picOut.set(xOut + 1, yOut + 1, pic.red(i, j), pic.green(i, j), pic.blue(i, j));
            yOut += 2;
        }
        xOut += 2;
    }
    pic = picOut;
}
void ImageEditor::colorFilter(int redTarget, int blueTarget, int greenTarget, int tolerance, int newRed, int newBlue, int newGreen)
{
    for(int i = 0; i < pic.width(); i++)
    {
        for(int j = 0; j < pic.height(); j++)
        {
            int redDist = abs(redTarget - pic.red(i, j));
            int blueDist = abs(blueTarget - pic.blue(i, j));
            int greenDist = abs(greenTarget - pic.green(i, j));
            if(redDist <= tolerance && greenDist <= tolerance && blueDist <= tolerance)
                pic.set(i, j, newRed, newGreen, newBlue);
        }
    }
}
void ImageEditor::save(string outFileName)
{
    pic.save(outFileName);
}
void ImageEditor::swapPixels(int x1, int y1, int x2, int y2)
{
    int tempRed = pic.red(x1, y1);
    int tempGreen = pic.green(x1, y1);
    int tempBlue = pic.blue(x1, y1);
    pic.set(x1, y1, pic.red(x2, y2), pic.green(x2, y2), pic.blue(x2, y2));
    pic.set(x2, y2, tempRed, tempGreen, tempBlue);
}

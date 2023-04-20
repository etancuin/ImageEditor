//
//  main.cpp
//  ImageEditor
//
//  Created by Ethan Quinn on 3/4/23.
//

#include "ImageEditor.h"
using namespace std;

int main()
{
    string fileName;
    cout << "<Enter file name>:" << endl;
    cin >> fileName;
    int redTarget, blueTarget, greenTarget, tolerance, newRed, newBlue, newGreen;
    cout << "<Enter filter parameters>:" << endl;
    cin >> redTarget >> blueTarget >> greenTarget >> tolerance >> newRed >> newBlue >> newGreen;
    cout << "---------------------------------------------------------" << endl;
    
    ImageEditor image("/Users/ethanquinn/Desktop/ImageEditorProject/ImageEditor/Pictures/" + fileName);
    cout << "File opened..." << endl;
    cout << "Parameters entered..." << endl;
    image.flipHorizontal();
    cout << "Flipped horizontally..." << endl;
    image.flipVertical();
    cout << "Flipped vertically..." << endl;
    image.colorFilter(redTarget, blueTarget, greenTarget, tolerance, newRed, newBlue, newGreen);
    cout << "Color filtered..." << endl;
    image.doubleSize();
    cout << "Size doubled..." << endl;
    image.save("/Users/ethanquinn/Desktop/ImageEditorProject/ImageEditor/Pictures/new-" + fileName);
    cout << "Image saved...\n" << endl;
    
    return 0;
}



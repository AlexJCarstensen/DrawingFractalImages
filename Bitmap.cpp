//
// Created by plex on 9/28/16.
//
#include <exception>
#include <iostream>
#include <fstream>

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace bitmapSanity;
using namespace std;
namespace bitmapSanity
{

    Bitmap::Bitmap(int width, int height)
            : width_(width), height_(height),
              pixels_(new uint8_t[width * height * 3]{}) // initialize all to zero with {}
    {


    }


    Bitmap::~Bitmap()
    {}

    bool Bitmap::write(string filename)
    {
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;

        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + width_ * height_ * 3;
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

        infoHeader.width = width_;
        infoHeader.height = height_;

        ofstream file;
        file.open(filename, ios::out | ios::binary);

        if (!file)
        {
            return false;
        }


        file.write((char *) &fileHeader, sizeof(fileHeader));
        file.write((char *) &infoHeader, sizeof(infoHeader));
        file.write((char *) pixels_.get(), width_ * height_ * 3);

        file.close();

        if (!file)
        {
            return false;
        }

        return true;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green)
    {
        uint8_t *pPixel = pixels_.get();

        pPixel += 3 * y * width_ + x * 3;

        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;


    }

}
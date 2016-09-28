//
// Created by plex on 9/28/16.
//

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace bitmapSanity;
namespace bitmapSanity
{

    Bitmap::Bitmap(int width, int height)
            : width_(width), height_(height),
              pixels_(new uint8_t[width * height * 3]{}) // initialize all to zero with {}
    {}

    Bitmap::~Bitmap()
    {}

    bool Bitmap::write(std::string filename)
    {
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;

        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + width_ * height_ * 3;
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

        infoHeader.width = width_;
        infoHeader.height = height_;

        return false;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green)
    {

    }

}
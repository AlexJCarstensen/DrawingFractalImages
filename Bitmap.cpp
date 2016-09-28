//
// Created by plex on 9/28/16.
//

#include "Bitmap.h"


namespace bitmapSanity
{

    Bitmap::Bitmap(int width, int height)
            : width_(width), height_(height), pixels_(new uint8_t[width * height * 3])
    {}

    Bitmap::~Bitmap()
    {}

    bool Bitmap::write(std::string filename)
    { return false; }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green)
    {

    }

}
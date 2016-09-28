//
// Created by plex on 9/28/16.
//

#ifndef DRAWINGFRACTALIMAGES_BITMAP_H
#define DRAWINGFRACTALIMAGES_BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

namespace bitmapSanity
{
    class Bitmap
    {
    public:
        Bitmap(int width, int height);

        virtual ~Bitmap();

        bool write(std::string filename);

        void setPixel(int x, int y, uint8_t red, uint8_t blue, uint8_t green);

    private:
        int width_{0};
        int height_{0};
        std::unique_ptr<uint8_t[]> pixels_{nullptr};

    };
}

#endif //DRAWINGFRACTALIMAGES_BITMAP_H

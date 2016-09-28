//
// Created by plex on 9/28/16.
//

#ifndef DRAWINGFRACTALIMAGES_BITMAPFILEHEADER_H
#define DRAWINGFRACTALIMAGES_BITMAPFILEHEADER_H

#include <cstdint>

#pragma  pack(2)

namespace bitmapSanity
{
    struct BitmapFileHeader
    {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;

    };
}

#endif //DRAWINGFRACTALIMAGES_BITMAPFILEHEADER_H


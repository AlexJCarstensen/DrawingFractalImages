//
// Created by plex on 10/3/16.
//

#ifndef DRAWINGFRACTALIMAGES_ZOOM_H
#define DRAWINGFRACTALIMAGES_ZOOM_H

namespace bitmapSanity
{
    struct Zoom
    {
        int x_{0};
        int y_{0};
        double scale_{0.0};

        Zoom(int x, int y, double scale) : x_(x), y_(y), scale_(scale)
        {}
    };
}


#endif //DRAWINGFRACTALIMAGES_ZOOM_H

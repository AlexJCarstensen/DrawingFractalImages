//
// Created by plex on 10/3/16.
//

#include <iostream>
#include "ZoomList.h"

namespace bitmapSanity
{


    ZoomList::ZoomList(int height, int width) : height_(height), width_(width)
    {

    }

    void ZoomList::add(const Zoom &zoom)
    {
        zooms.push_back(zoom);

        xCenter_ += (zoom.x_ - width_ / 2) * scale_;
        yCenter_ += -(zoom.y_ - height_ / 2) * scale_;

        scale_ *= zoom.scale_;

    }

    std::pair<double, double> ZoomList::doZoom(int x, int y)
    {

        double xFractal = (x - width_ / 2) * scale_ + xCenter_;
        double yFractal = (y - height_ / 2) * scale_ + yCenter_;
        return std::pair<double, double>(xFractal, yFractal);
    }
}
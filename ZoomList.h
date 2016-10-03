//
// Created by plex on 10/3/16.
//

#ifndef DRAWINGFRACTALIMAGES_ZOOMLIST_H
#define DRAWINGFRACTALIMAGES_ZOOMLIST_H

#include <vector>
#include <utility>

#include "Zoom.h"

namespace bitmapSanity
{
    class ZoomList
    {
    public:
        ZoomList(int height, int width);

        void add(const Zoom &zoom);

        std::pair<double, double> doZoom(int x, int y);

    private:
        double xCenter_{0.0};
        double yCenter_{0.0};
        double scale_{1.0};

        int width_{0};
        int height_{0};

        std::vector<Zoom> zooms;
    };
}

#endif //DRAWINGFRACTALIMAGES_ZOOMLIST_H

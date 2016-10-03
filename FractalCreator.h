//
// Created by plex on 10/3/16.
//

#ifndef DRAWINGFRACTALIMAGES_FRACTALCREATOR_H
#define DRAWINGFRACTALIMAGES_FRACTALCREATOR_H

#include <string>
#include <bits/unique_ptr.h>
#include "Zoom.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "RGB.h"

namespace bitmapSanity
{


    class FractalCreator
    {
    public:
        FractalCreator(int width, int height);

        virtual ~FractalCreator();

        void run(std::string name);

        void addZoom(const Zoom &zoom);

        void addRange(double rangeEnd, const RGB &rgb);

    private:
        void calculateIteration();

        void drawFractal();

        void writeBitmap(std::string name);

        void calculateTotalIterations();

        void calculateRangeTotals();

        int getRange(int iterations) const;

    private:
        int width_;
        int height_;
        int total_{0};
        std::vector<int> ranges_;
        std::vector<int> rangeTotals_;
        std::vector<RGB> colors_;
        ZoomList zoomList_;
        Bitmap bitmap_;
        std::unique_ptr<int[]> histogram_;
        std::unique_ptr<int[]> fractal_;

        bool gotFirstRange_{false};
    };
}


#endif //DRAWINGFRACTALIMAGES_FRACTALCREATOR_H

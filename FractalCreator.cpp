//
// Created by plex on 10/3/16.
//


#include "FractalCreator.h"
#include "RGB.h"
#include <assert.h>

namespace bitmapSanity
{

    bitmapSanity::FractalCreator::FractalCreator(int width, int height)
            : width_(width), height_(height), zoomList_(height_, width_), bitmap_(width_, height_),
              histogram_(new int[Mandelbrot::MAX_ITERATIONS]{}), fractal_(new int[width_ * height_]{})
    {
        zoomList_.add(Zoom(width_ / 2, height_ / 2, 4.0 / width_));
    }

    FractalCreator::~FractalCreator()
    {

    }

    void FractalCreator::calculateIteration()
    {
        for (int y = 0; y < height_; y++)
        {
            for (int x = 0; x < width_; x++)
            {
                std::pair<double, double> coords = zoomList_.doZoom(x, y);


                int iterations = Mandelbrot::getIterations(coords.first, coords.second);
                fractal_[y * width_ + x] = iterations;

                if (iterations != Mandelbrot::MAX_ITERATIONS)
                    histogram_[iterations]++;
            }
        }
    }

    void FractalCreator::drawFractal()
    {
        RGB startColor(0, 0, 20);
        RGB endColor(0, 0, 255);
        RGB diffColor = endColor - startColor;

        for (int y = 0; y < height_; y++)
        {
            for (int x = 0; x < width_; x++)
            {
                int iterations = fractal_[y * width_ + x];

                int range = getRange(iterations);
                int rangeTotal = rangeTotals_[range];
                int rangeStart = ranges_[range];

                RGB &startColor = colors_[range];
                RGB &endColor = colors_[range + 1];

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;


                if (iterations != Mandelbrot::MAX_ITERATIONS)
                {

                    int totalPixels = 0;
                    for (int i = rangeStart; i <= iterations; i++)
                    {
                        totalPixels += histogram_[i];

                    }

                    red = startColor.r_ + diffColor.r_ * (double) totalPixels / rangeTotal;
                    blue = startColor.b_ + diffColor.b_ * (double) totalPixels / rangeTotal;
                    green = startColor.g_ + diffColor.g_ * (double) totalPixels / rangeTotal;
                }
                bitmap_.setPixel(x, y, red, blue, green);
            }
        }
    }

    void FractalCreator::writeBitmap(std::string name)
    {
        bitmap_.write(name);
    }

    void FractalCreator::addZoom(const Zoom &zoom)
    {
        zoomList_.add(zoom);
    }

    void FractalCreator::calculateTotalIterations()
    {


        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            total_ += histogram_[i];
        }
    }

    void FractalCreator::run(std::string name)
    {

        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(name);
    }

    void FractalCreator::addRange(double rangeEnd, const RGB &rgb)
    {
        ranges_.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        colors_.push_back(rgb);

        if (gotFirstRange_)
            rangeTotals_.push_back(0);

        gotFirstRange_ = true;


    }

    void FractalCreator::calculateRangeTotals()
    {
        int rangeIndex = 0;
        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            int pixels = histogram_[i];
            if (i >= ranges_[rangeIndex + 1])
                rangeIndex++;

            rangeTotals_[rangeIndex] += pixels;
        }
    }

    int FractalCreator::getRange(int iterations) const
    {
        int range = 0;

        for (int i = 1; i < ranges_.size(); i++)
        {
            range = i;

            if (ranges_[i] > iterations)
                break;
        }

        range--;

        assert(range > -1);
        assert(range < ranges_.size());

        return range;

    }


}

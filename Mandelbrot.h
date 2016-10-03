//
// Created by plex on 10/3/16.
//

#ifndef DRAWINGFRACTALIMAGES_MANDELBROT_H
#define DRAWINGFRACTALIMAGES_MANDELBROT_H

namespace bitmapSanity
{
    class Mandelbrot
    {
    public:
        static const int MAX_ITERATIONS = 1000;
    public:
        Mandelbrot();

        virtual ~Mandelbrot();

        static int getIterations(double x, double y);


    };
};

#endif //DRAWINGFRACTALIMAGES_MANDELBROT_H

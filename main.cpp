#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <cmath>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"
#include "RGB.h"

using namespace bitmapSanity;

int main()
{
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.3, RGB(255, 24, 0));
    fractalCreator.addRange(0.5, RGB(255, 152, 231));
    fractalCreator.addRange(1.0, RGB(255, 165, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("test.bmp");

    return 0;
}
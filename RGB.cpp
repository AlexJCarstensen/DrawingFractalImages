//
// Created by plex on 10/3/16.
//

#include "RGB.h"

namespace bitmapSanity
{
    bitmapSanity::RGB::RGB(double r, double g, double b) : r_(r), g_(g), b_(b)
    {

    }


    RGB operator-(const RGB &first, const RGB &second)
    {
        return RGB(first.r_ - second.r_, first.g_ - second.g_, first.b_ - second.b_);
    }
}
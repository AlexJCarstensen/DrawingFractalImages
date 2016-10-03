//
// Created by plex on 10/3/16.
//

#ifndef DRAWINGFRACTALIMAGES_RGB_H
#define DRAWINGFRACTALIMAGES_RGB_H

namespace bitmapSanity
{

    struct RGB
    {
        double r_;
        double g_;
        double b_;
    public:
        RGB(double r, double g, double b);


    };

    RGB operator-(const RGB &first, const RGB &second);

}


#endif //DRAWINGFRACTALIMAGES_RGB_H

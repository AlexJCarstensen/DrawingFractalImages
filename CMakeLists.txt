cmake_minimum_required(VERSION 3.6)
project(DrawingFractalImages)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h Zoom.h ZoomList.cpp ZoomList.h FractalCreator.cpp FractalCreator.h RGB.cpp RGB.h)
add_executable(DrawingFractalImages ${SOURCE_FILES})
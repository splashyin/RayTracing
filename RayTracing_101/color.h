#pragma once

#include "vec3.h"

#include <iostream>

void write_color( std::ostream& io_out, color i_pixelColor )
{
    io_out << static_cast< int > ( 255.999 * i_pixelColor.x() ) << " "
           << static_cast< int > ( 255.999 * i_pixelColor.y() ) << " "
           << static_cast< int > ( 255.999 * i_pixelColor.z() ) << "\n";
}
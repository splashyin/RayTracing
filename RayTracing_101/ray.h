#pragma once

#include "vec3.h"

class Ray
{
public:
    // Ctor
    Ray() {}

    Ray( const point3& i_origin, const vec3& i_direction )
        : m_origin( i_origin ),
          m_direction( i_direction )
    {}
    
    // Get origin
    inline point3 origin() const { return m_origin; }

    // Get direction
    inline vec3 direction() const { return m_direction; }

    // Ray function P(t) = A + tB
    inline point3 at( double i_t ) const
    {
        return m_origin + i_t * m_direction;
    }

    point3 m_origin;
    vec3 m_direction;
};
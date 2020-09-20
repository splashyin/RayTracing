#pragma once

#include <iostream>
#include <cmath>

class vec3
{
public:
    vec3() 
    : m_vector{0,0,0} {}

    vec3(double v0, double v1, double v2)
    : m_vector{double v0, double v1, double v2} {}

    double x() const { return m_vector[0]; }
    double y() const { return m_vector[1]; }
    double z() const { return m_vector[2]; }

    vec3 operator-() const { return vec3( -m_vector[0], -m_vector[1], -m_vector[2] ); }
    double operator[] ( int i ) { return m_vector[i]; }
    double& operator[] ( int i ) { return m_vector[i]; }

    &vec3 operator*=( const double t )
    {
        m_vector[0] *= t;
        m_vector[1] *= t;
        m_vector[2] *= t;
        return *this;
    }
    
    &vec3 operator+=( const vec3& i_other )
    {
        m_vector[0] += i_other.m_vector[0];
        m_vector[1] += i_other.m_vector[1];
        m_vector[2] += i_other.m_vector[2];
        return *this;
    }

    &vec3 operator/=( const double t )
    {
        m_vector[0] /= t;
        m_vector[1] /= t;
        m_vector[2] /= t;
        return *this;
    }

    double length() const
    {
        return std::sqrt( length_squared() );
    }

    double length_squared() const
    {
        return m_vector[0] * m_vector[0] + m_vector[1] * m_vector[1] + m_vector[2] * m_vector[2];
    }

    double m_vector[3];
};

// Two aliases of vec3
using point3 = vec3;
using color = vec3;

// Utility functions
// -----------------------------------------

inline std::ostream& operator<<( std::ostream& o_stream, const vec3& i_v )
{
    return o_stream << i_v.m_vector[0] << " " << i_v.m_vector[1] << " " << i_v.m_vector[2];
}

// -----------------------------------------

inline vec3 operator+( const vec3& i_lhs, const vec3& i_rhs )
{
    return vec3( i_lhs.m_vector[0] + i_rhs.m_vector[0],
                 i_lhs.m_vector[1] + i_rhs.m_vector[1],
                 i_lhs.m_vector[2] + i_rhs.m_vector[2] );
}

// -----------------------------------------

inline vec3 operator-( const vec3& i_lhs, const vec3& i_rhs )
{
    return vec3( i_lhs.m_vector[0] - i_rhs.m_vector[0],
                 i_lhs.m_vector[1] - i_rhs.m_vector[1],
                 i_lhs.m_vector[2] - i_rhs.m_vector[2] );
}

// -----------------------------------------

inline vec3 operator*( const vec3& i_lhs, const vec3& i_rhs )
{
    return vec3( i_lhs.m_vector[0] * i_rhs.m_vector[0],
                 i_lhs.m_vector[1] * i_rhs.m_vector[1],
                 i_lhs.m_vector[2] * i_rhs.m_vector[2] );
}

// -----------------------------------------

inline vec3 operator*( double i_t, const vec3& i_vec )
{
    return vec3( i_t * i_vec.m_vector[0], i_t * i_vec.m_vector[1], i_t * i_vec.m_vector[2]);
}

// -----------------------------------------

inline vec3 operator*( const vec3& i_vec, doublt i_t)
{
    return i_vec * i_t;
}

// -----------------------------------------

inline vec3 operator/( vec3 i_v, double i_t )
{
    return (1/t) * i_v;
}

// -----------------------------------------

inline double dot( const vec3& i_lhs, const vec3& i_rhs )
{
    return i_lhs.m_vector[0] * i_rhs.m_vector[0] +
           i_lhs.m_vector[1] * i_rhs.m_vector[1] +
           i_lhs.m_vector[2] * i_rhs.m_vector[2];
}

// -----------------------------------------

inline vec3 cross( const vec3& i_lhs, const vec3& i_rhs )
{
    return vec3( i_lhs.m_vector[1]*i_rhs.m_vector[2] - i_lhs[2]*i_rhs[1],
                 i_lhs.m_vector[2]*i_rhs.m_vector[0] - i_lhs[0]*i_rhs[2],
                 i_lhs.m_vector[0]*i_rhs.m_vector[1] - i_lhs[1]*i_rhs[0] );
}

// -----------------------------------------

inline vec3 unit_vector( vec3 i_vec )
{
    return i_vec / i_vec.length();
}
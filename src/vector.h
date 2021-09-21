#pragma once

#include "global.h"

class Vector2
{
public:
	float x;
	float y;

public:
	Vector2( ) : x( 0.f ), y( 0.f ) { }
	Vector2( float xx, float yy ) : x( xx ), y( yy ) { }
	Vector2 operator*( float f ) const
	{
		return Vector2( x * f, y * f );
	}
	Vector2 operator+( Vector2 v ) const
	{
		return Vector2( x + v.x, y + v.y );
	}

	void Clear( )
	{
		x = 0.f;
		y = 0.f;
	}

	void Dump( ) const
	{
		std::cout << "Vector2[ " << x << ", " << y << " ]" << std::endl;
	}
};

class Vector3
{
public:
	float x;
	float y;
	float z;

public:
	Vector3( ): x( 0.f ), y( 0.f ), z( 0.f ) { }
	Vector3( float xx, float yy, float zz ): x( xx ), y( yy ), z( zz ) { }
	Vector3 operator*( float f ) const
	{
		return Vector3( x * f, y * f, z * f );
	}
	Vector3 operator+( Vector3 v ) const
	{
		return Vector3( x + v.x, y + v.y, z + v.z );
	}

	void Clear( )
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	void Dump( ) const
	{
		std::cout << "Vector3[ " << x << ", " << y << ", " << z << " ]" << std::endl;
	}
};

class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	Vector4( ) : x( 0.f ), y( 0.f ), z( 0.f ), w( 1.f ) { }
	Vector4( Vector3 v3, float ww = 1.0f ) : x( v3.x ), y( v3.y ), z( v3.z ), w( ww ) { }
	Vector4( float xx, float yy, float zz, float ww = 1.0f ) : x( xx ), y( yy ), z( zz ), w( ww ) { }

	void Dump( ) const
	{
		std::cout << "Vector4[ " << x << ", " << y << ", " << z << ", " << w << " ]" << std::endl;
	}
};

template<typename T>
T Interpolation( const T& t1, const T& t2, float interpolation )
{
	return t1 * ( 1.f - interpolation ) + t2 * interpolation;
}

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

	void Clear( )
	{
		x = 0.f;
		y = 0.f;
	}

	void Dump( )
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

	void Clear( )
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	void Dump( )
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

	void Dump( )
	{
		std::cout << "Vector4[ " << x << ", " << y << ", " << z << ", " << w << " ]" << std::endl;
	}
};

#pragma once

#include "global.h"

class Vector3
{
public:
	float x;
	float y;
	float z;

public:
	Vector3( ): x( 0.f ), y( 0.f ), z( 0.f ) { }
	Vector3( float xx, float yy, float zz ): x( xx ), y( yy ), z( zz ) { }

	void Dump( )
	{
		std::cout << "Vector3[ " << x << ", " << y << ", " << z << " ]" << std::endl;
	}
};

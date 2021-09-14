#pragma once

#include "global.h"
#include "vector.h"

class Camera
{
public:
	Vector3 pos;
	Vector3 look;
	Vector3 up;
	float fov;

public:
	// default: look is -z, up is +y
	Camera( ): pos( ), look( 0.f, 0.f, -1.f ), up( 0.f, 1.f, 0.f ), fov( 45.f ) { }

	void Dump( )
	{
		std::cout << "Camera:\n"
			<< "\tpos\t: ";
		pos.Dump( );
		std::cout << "\tlook\t: ";
		look.Dump( );
		std::cout << "\tup\t: ";
		up.Dump( );
		std::cout << "\tfov\t: " << fov << std::endl;
	}
};


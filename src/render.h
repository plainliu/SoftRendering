#pragma once

#include "global.h"
#include "vector.h"

#include <fstream>

class Render
{
private:
	int width;
	int height;
	Vector3* framebuffer;

public:
	Render( int w = 512, int h = 512 ): width( w ), height( h )
	{
		framebuffer = new Vector3[ width * height ];
	}
	~Render( )
	{
		delete[] framebuffer;
	}

	void Clear( )
	{
		for ( int i = 0; i < width * height; ++i )
			framebuffer[i].Clear( );
	}

	void SetColor( int i, int j, Vector3 color )
	{
		framebuffer[ GetIndex( i, j ) ] = color;
	}

	void Draw( )
	{
		std::ofstream out;
		out.open( "render.ppm", std::ios::out );

		out << "P3\n" << width << ' ' << height << "\n255\n";

		for ( int j = height - 1; j >= 0; --j ) {
			for ( int i = 0; i < width; ++i ) {
				//auto r = double( i ) / ( width - 1 );
				//auto g = double( j ) / ( height - 1 );
				//auto b = 0.25;

				Vector3& color = framebuffer[ GetIndex( i, j ) ];
				auto r = color.x;
				auto g = color.y;
				auto b = color.z;

				int ir = static_cast<int>( 255.999 * r );
				int ig = static_cast<int>( 255.999 * g );
				int ib = static_cast<int>( 255.999 * b );

				out << ir << ' ' << ig << ' ' << ib << '\n';
			}
		}
		out.close( );
	}

	int GetIndex( int i, int j )
	{
		return j * width + i;
	}

public:
	static Render* sRender;
	static Render* GetRender( )
	{
		if ( sRender ) return sRender;
		sRender = new Render( );
		return sRender;
	}
};

Render* Render::sRender = nullptr;

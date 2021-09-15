#pragma once

#include "global.h"
#include "vector.h"

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

	int GetIndex( int i, int j )
	{
		return j * width + i;
	}

	void SetColor( int i, int j, Vector3 color )
	{
		framebuffer[ GetIndex( i, j ) ] = color;
	}

public:
	void Draw( );
	void DrawPoint( const Vector2& p, const Vector3& color );

public:
	static Render* sRender;
	static Render* GetRender( )
	{
		if ( sRender ) return sRender;
		sRender = new Render( );
		return sRender;
	}
};

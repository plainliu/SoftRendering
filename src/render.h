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

	void SetColor( int i, int j, const Vector3& color )
	{
		assert( i < width && j < height );
		framebuffer[ GetIndex( i, j ) ] = color;
	}

public:
	void Draw( );

	void Draw2DPoint( const Vector2& p, const Vector3& color = Vector3( 1.f, 1.f, 1.f ) );
	void Draw2DLine( const Vector2& p1, const Vector2& p2, const Vector3& color1 = Vector3( 1.f, 1.f, 1.f ), const Vector3& color2 = Vector3( 1.f, 1.f, 1.f ) );

public:
	static Render* sRender;
	static Render* GetRender( )
	{
		if ( sRender ) return sRender;
		sRender = new Render( );
		return sRender;
	}
};

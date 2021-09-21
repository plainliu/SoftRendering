#include "render.h"

#include <fstream>

Render* Render::sRender = nullptr;

void Render::Draw( )
{
	std::ofstream out;
	out.open( "render.ppm", std::ios::out );

	out << "P3\n" << width << ' ' << height << "\n255\n";

	for ( int j = 0; j < height; ++j ) {
		for ( int i = 0; i < width; ++i ) {
			//auto r = double( i ) / ( width - 1 );
			//auto g = double( j ) / ( height - 1 );
			//auto b = 0.25;

			Vector3& color = framebuffer[GetIndex( i, j )];
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

void Render::Draw2DPoint( const Vector2& p, const Vector3& color )
{
	SetColor( p.x, p.y, color );
}

void Render::Draw2DLine( const Vector2& p1, const Vector2& p2, const Vector3& color1, const Vector3& color2 )
{
	int dx = std::abs( p1.x - p2.x );
	int dy = std::abs( p1.y - p2.y );
	if ( dy == 0 && dx == 0 )
	{
		SetColor( p1.x, p1.y, color1 );
	}
	else if ( dx >= dy )
	{
		for ( int i = 0; i <= dx; ++i )
		{
			float inter = (float) i / dx;
			const Vector2 p = Interpolation( p1, p2, inter );
			SetColor( p.x, p.y, Interpolation( color1, color2, inter ) );
		}
	}
	else if ( dy > dx )
	{
		for ( int j = 0; j <= dy; ++j )
		{
			float inter = (float)j / dy;
			const Vector2 p = Interpolation( p1, p2, inter );
			SetColor( p.x, p.y, Interpolation( color1, color2, inter ) );
		}
	}
}

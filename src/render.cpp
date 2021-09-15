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

void Render::DrawPoint( const Vector2& p, const Vector3& color )
{
	assert( p.x < width && p.y < height );
	SetColor( p.x, p.y, color );
}

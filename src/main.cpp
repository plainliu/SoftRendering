#include "global.h"
#include "vector.h"
#include "camera.h"
#include "matrix.h"
#include "render.h"

void TestBaseType( )
{
	Vector3 point;
	point.Dump( );

	Camera camera;
	camera.Dump( );

	Vector4 v4;
	v4.Dump( );

	Matrix4x4 matrix;
	matrix.Dump( );

	Matrix4x4 matrix1(
		1.f, 0.f, 0.f, 0.f,
		0.f, 2.f, 0.f, 0.f,
		0.f, 0.f, 3.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	);

	( matrix1 * matrix1 ).Dump( );

	( matrix * v4 ).Dump( );
}

int main( )
{
	std::cout << "Hello SoftRendering!" << std::endl;

	TestBaseType( );

	Render* render = Render::GetRender( );
	render->Draw2DPoint( Vector2( 10, 10 ) );
	render->Draw2DPoint( Vector2( 20, 10 ), Vector3( 1.f, 0.f, 0.f ) );
	render->Draw2DLine( Vector2( 30, 20 ), Vector2( 30, 20 ) );
	render->Draw2DLine( Vector2( 20, 20 ), Vector2( 20, 100 ) );
	render->Draw2DLine( Vector2( 20, 20 ), Vector2( 200, 200 ), Vector3( 1.f, 0.f, 0.f ), Vector3( 0.f, 1.f, 0.f ) );
	render->Draw( );
}

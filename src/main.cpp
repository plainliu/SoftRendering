#include "global.h"
#include "vector.h"
#include "camera.h"
#include "matrix.h"

int main( )
{
	std::cout << "Hello SoftRendering!" << std::endl;

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

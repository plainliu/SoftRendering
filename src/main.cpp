#include "global.h"
#include "vector.h"
#include "camera.h"

int main( )
{
	std::cout << "Hello SoftRendering!" << std::endl;

	Vector3 point;
	point.Dump( );

	Camera camera;
	camera.Dump( );
}

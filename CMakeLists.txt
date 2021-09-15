cmake_minimum_required(VERSION 3.10)
project(SoftRendering)

set(CMAKE_CXX_STANDARD 17)

add_executable(SoftRendering
	"src/global.h"
	"src/vector.h"
	"src/matrix.h"
	"src/camera.h"
	"src/main.cpp"
)

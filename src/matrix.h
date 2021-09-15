#pragma once

#include "global.h"

class Matrix4x4
{
public:
	float v[4][4];

public:
	Matrix4x4( )
	{
		Identity( );
	}

	Matrix4x4( float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15 )
	{
		v[0][0] = v0;
		v[0][1] = v1;
		v[0][2] = v2;
		v[0][3] = v3;
		v[1][0] = v4;
		v[1][1] = v5;
		v[1][2] = v6;
		v[1][3] = v7;
		v[2][0] = v8;
		v[2][1] = v9;
		v[2][2] = v10;
		v[2][3] = v11;
		v[3][0] = v12;
		v[3][1] = v13;
		v[3][2] = v14;
		v[3][3] = v15;
	}

	void Identity( )
	{
		for ( int i = 0; i < 4; ++ i )
		{
			for ( int j = 0; j < 4; ++ j )
			{
				if ( i == j )
					v[i][j] = 1.f;
				else
					v[i][j] = 0.f;
			}
		}
	}

	Matrix4x4 operator*( const Matrix4x4& m ) const
	{
		Matrix4x4 ret;
		for ( int i = 0; i < 4; ++i )
		{
			for ( int j = 0; j < 4; ++j )
			{
				ret.v[i][j] = 0.f;
				for ( int k = 0; k < 4; ++k )
					ret.v[i][j] += v[i][k] * m.v[k][j];
			}
		}
		return ret;
	}

	Vector4 operator*( const Vector4& v4 ) const
	{
		Vector4 ret;
		ret.x = v[0][0] * v4.x + v[0][1] * v4.y + v[0][2] * v4.z + v[0][3] * v4.w;
		ret.y = v[1][0] * v4.x + v[1][1] * v4.y + v[1][2] * v4.z + v[1][3] * v4.w;
		ret.z = v[2][0] * v4.x + v[2][1] * v4.y + v[2][2] * v4.z + v[2][3] * v4.w;
		ret.w = v[3][0] * v4.x + v[3][1] * v4.y + v[3][2] * v4.z + v[3][3] * v4.w;
		return ret;
	}

	void Dump( )
	{
		for ( int i = 0; i < 4; ++i )
		{
			std::cout << "[ ";
			for ( int j = 0; j < 4; ++j )
				std::cout << v[i][j] << " ";
			std::cout << "]" << std::endl;
		}
	}
};

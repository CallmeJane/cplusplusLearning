#pragma once

struct Vertex {
	union
	{
		struct { float x, y, z; };
		float v[3];
	};
	Vertex operator+(const Vertex ver)
	{
		Vertex temp;
		temp.x = this->x + ver.x;
		temp.y = this->y + ver.y;
		temp.z = this->z + ver.z;
		for (int i = 0; i < 3; i++)
		{
			temp.v[i] = this->v[i] + ver.v[i];
		}
		return temp;
	}
};

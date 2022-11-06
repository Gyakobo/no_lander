#ifndef POINTS_H
#define POINTS_H

#include <vector> 

using namespace std;

class Point {
	private:
		vec3 pos;
		vec4 color;

	public:
		Point();
		Point(vec3 pos, vec4 color) {
			this->pos = pos;
			this->color = color;
		}

		vec3 get_pos() { return pos;}
		vec4 get_color() { return color;}
};

#endif

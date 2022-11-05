#ifndef ALT_GRID_H
#define ALT_GRID_H

#include "alpha_numeric.h"

using namespace std;

class Alt_Grid {
    protected:
        int width = 1280, height = 720;
        vector<Renderable2D*> sprites = {};
	    vector<vector<vec4>> sprite;
	    void DrawOnScreen(int& x, int& y, const vec4& color);         

    public:
        Alt_Grid(); 
        void update(); // Update the screen

        vector<Renderable2D*> getRenderables() {return sprites;}
};
/*
namespace grid {
    void randomize();
    int rand_range(int start, int end);

    vec4 unit_len(const vec4& v);

    enum eDir {
        STOP = 0,

        LEFT =		1,
        RIGHT =		2,
		UP =		7,
		DOWN =		8,

		UPLEFT =	3,
        DOWNLEFT =	4,
        UPRIGHT =	5,
        DOWNRIGHT =	6
    };    
}*/

#endif
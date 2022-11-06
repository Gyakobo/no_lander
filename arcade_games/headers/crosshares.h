#ifndef CROSSHARES_H
#define CROSSHARES_H

#include "../../headers/alpha_numeric.h"
#include "../../headers/points.h"
#include <vector>

using namespace std;


class CrossHares {
private:
    int width, height;
    vector<Point> points;
    int grid_layout[100][100];
    
    vector<Renderable2D*> sprites = {};
	void DrawOnScreen(Point point) { points.push_back(point); }

public:
    CrossHares(int width, int height);
    void update();

    void add_landmass();

    vector<Renderable2D*> getRenderables() {return sprites;}

};

#endif

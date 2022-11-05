#include "../headers/alt_grid.h"

Alt_Grid::Alt_Grid() {
    /*int _width = 32;
    int _height = 32;

    vector<vec4> row_color;
    vec4 color = DEFAULT;

    for (int i=0; i<_width; i++) row_color.push_back(color);
    for (int j=0; j<_height; j++) sprite.push_back(row_color);

    for (int x=0; x<_width; x++) 
        for (int y=0; y<_height; y++) 
            DrawOnScreen(x, y, color);*/
}

/*void Alt_Grid::DrawOnScreen(int &x, int &y, const vec4 &color)
{
    sprite.at(x).at(y) = color;
}*/

void Alt_Grid::update()
{
    sprites = {};

    bool flag = false;

    int box_w = 2;
    int box_h = 2;

    vec4 color;

    for (int i=0; i<20; i+=2) {
        flag = !flag;
        if (flag) color = vec4(1, 0, 0, 1);
        else color = vec4(0, 0, 1, 1);

        sprites.push_back(new Sprite(vec3(i, 0, 0), vec3(box_w + i, 0, 0), vec3(box_w+i, box_h, 0), color));
        sprites.push_back(new Sprite(vec3(box_w+i, box_h, 0), vec3(i, box_h, 0), vec3(i, 0, 0) , color));
    }

}




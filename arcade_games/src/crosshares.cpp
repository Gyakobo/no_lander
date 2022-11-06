#include "../headers/crosshares.h" 

#define DEFAULT_ 0
#define SAND    1 
#define WATER   2   
#define FIRE    3 
#define SMOKE   4   

CrossHares::CrossHares(int width, int height) {
    this->width = width;
    this->height = height;

    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            grid_layout[i][j] = DEFAULT_; 
        }
    }

    add_landmass();
}

void CrossHares::add_landmass() {
    points = {};

    bool flag = false;

    for (int i=0; i<80; i++) {
        flag = !flag;
        for (int j=0; j<80; j++) {
            flag = !flag;
            if (flag)
                DrawOnScreen(Point(vec3(i, j, 0), vec4(1, 0, 0, 1)));
            else DrawOnScreen(Point(vec3(i, j, 0), vec4(1, 0, 1, 1)));
        }
    }
}

void CrossHares::update() {
    sprites = {};

    int offset = 1.0f;
    vec4 color;

    // Landmass update
    


    // Texture Update
    for (int i=0; i< points.size(); i++) {
        vec3 pos = points.at(i).get_pos()*offset;
        vec4 color = points.at(i).get_color();

        sprites.push_back(new Sprite(pos, vec3(pos.x+offset, pos.y, 0), vec3(pos.x+offset, pos.y+offset, 0), color));
        sprites.push_back(new Sprite(vec3(pos.x+offset, pos.y+offset, 0), vec3(pos.x, pos.y+offset, 0), pos, color)); 
    }
}



#ifndef Camera_h
#define Camera_h

#include <vector>

#include "var.h"
#include "map.h"

class camera {

    public:
        camera();
        camera(map *m);

        int getSurface(int x, int y);
        void update();

    private:
        int surface[var::C_HEIGHT][var::C_WIDTH];
        map *origine;
};

#endif
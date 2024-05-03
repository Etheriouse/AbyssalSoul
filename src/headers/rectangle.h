#ifndef Rectangle_h
#define Rectangle_h

#include "vector.h"

class rectangle {

    public:
        /**
         * rectangle 1*1
        */
        rectangle();
        /**
         * @param x x of left up
         * @param y y of left up
         * @param z x of right down
         * @param t y of right down
        */
        rectangle(int x, int y, int z, int t);
        /**
         * @param v1 coordinate left up
         * @param v2 coordinate right down
        */
        rectangle(vector v1, vector v2);
        rectangle(rectangle *r);

        int a;
        int b;
        int c;
        int d;

    private:

};

#endif
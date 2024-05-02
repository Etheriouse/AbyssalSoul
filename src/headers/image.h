#ifndef Image_h
#define Image_h

#include "vector.h"

class image {

    public:
        image();
        image(const char* filename);
        int* getPixel(vector xy);

    private:
        int width, height, channels;
        unsigned char* data;


};

#endif
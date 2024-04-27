#ifndef Image_h
#define Image_h

class image {

    public:
        image();
        image(const char* filename);
        int* getPixel(int xy);

    private:
        int width, height, channels;
        unsigned char* data;


};

#endif
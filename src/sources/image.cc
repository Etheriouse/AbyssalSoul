#include <iostream>
#include "../headers/image.h"
#include "../headers/function.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../headers/stb_image.h"

image::image()
{
    this->data = stbi_load("", &width, &height, &channels, 0);
}

image::image(const char *filename)
{
    this->data = stbi_load(filename, &width, &height, &channels, 0);
}

/**
 * @param coordonnée les coordonée du pixel rechercher
 * @return les couleur rgb {r, g ,b}
*/
int *image::getPixel(vector xy)
{
    int x = xy.x;
    int y = xy.y;

    int index = (y * this->width + x) * this->channels;
    unsigned char r = this->data[index];
    unsigned char g = this->data[index + 1];
    unsigned char b = this->data[index + 2];

    return new int[3]{r, g ,b};
}
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../headers/stb_image.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const char* filename = "ressources/assets/image.png";
    cout << filename << endl;
    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);

    if (!data) {
        std::cerr << "Erreur : Impossible de charger l'image." << std::endl;
        return 1;
    }

    std::cout << "Dimensions de l'image : " << width << "x" << height << std::endl;

    // Transformer l'image en tableau de pixels
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * channels;
            unsigned char r = data[index];
            unsigned char g = data[index + 1];
            unsigned char b = data[index + 2];
            printf("r:%d, g:%d, b:%d - ", r, g ,b);
            cout << "average color: " << (r+g+b)/3 << endl;

        }
    }

    // Libérer la mémoire allouée pour les données de l'image
    stbi_image_free(data);
    return 0;
}

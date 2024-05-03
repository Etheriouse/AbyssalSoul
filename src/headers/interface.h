#ifndef Interface_h
#define Interface_h

#include <vector>
#include <map>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "rectangle.h"
#include "map.h"

class interface {

    public:
        interface();
        interface(const char* name);
        interface(const char* name, const char* icone_filename);
        interface(const char* name, const char* icone_filename, map* m);

        void run();

    private:
        void clearTextures();
        void loadTextures();
        bool checkColision(int block);
        bool checkColision(int block, rectangle r);
        void moveX(int i);
        void moveY(int i);
        void escapeMenu();

        SDL_Window* window;
        SDL_Renderer* renderer;
        bool windows_on = true;
        std::map<const char*, SDL_Texture*> textures;
        map* m;

};

#endif
#ifndef Interface_h
#define Interface_h

#include <vector>
#include <map>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "map.h"

class interface {

    public:
        interface();
        interface(const char* name);
        interface(const char* name, const char* icone_filename);
        interface(const char* name, const char* icone_filename, map* m);

        void run();

    private:
        void clearTexture();
        bool checkColision(int block);
        int arronditofiveteen(int i);
        void movetoright(int i);
        void movetoleft(int i);
        void movetotop(int i);
        void movetobot(int i);

        SDL_Window* window;
        SDL_Renderer* renderer;
        std::map<const char*, SDL_Texture*> textures;
        map* m;

};

#endif
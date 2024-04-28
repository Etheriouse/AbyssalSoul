#!/bin/bash
g++ src/sources/*.cc src/headers/*.h `sdl2-config --cflags --libs` -lSDL2_image -o DarksoulIV
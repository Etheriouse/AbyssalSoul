#!/bin/bash
g++ src/sources/*.cc src/headers/*.h `sdl2-config --cflags --libs` -o DarksoulIV
#!/bin/bash
cd ./src
gcc -Wall -o "./bin/roguelite" main.c view.c model.c controller.c -lSDL2
cd ..

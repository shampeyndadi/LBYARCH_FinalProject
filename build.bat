@echo off
del *.obj
del a.exe

nasm -f win64 imgCvtGrayFloatToInt.asm -o imgCvtGrayFloatToInt.obj
gcc -c main.c -o main.obj
gcc -c image_helpers.c -o image_helpers.obj
gcc main.obj image_helpers.obj imgCvtGrayFloatToInt.obj -o a.exe

a.exe
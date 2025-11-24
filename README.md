##Grayscale Float → Integer Converter (C + x86-64 Assembly)##

📌 Project Overview

This project implements a grayscale conversion program where C handles the driver logic and I/O, and x86-64 assembly performs the core pixel conversion. The program converts grayscale pixel values from single-precision floating-point (0.0–1.0) into 8-bit unsigned integer grayscale values (0–255) using proportional mapping and scalar SIMD floating-point instructions..

The C program is responsible for:

- Manual or random pixel input
- Output printing (float and integer images)
- Memory allocation
- High-resolution timing using QueryPerformanceCounter()
- A full menu-driven interface.

The assembly routine performs the actual conversion, applying the formula:

        - i = f * 255

It uses scalar SIMD operations such as movss, mulss, roundss, and cvttss2si for accurate rounding and fast per-pixel processing.


i.) Execution Time (Ran 20 times) and analysis
        
For images with a height and width from 1 - 9, the average execution time was from 0.0000000200 seconds up to 0.0000002000 seconds.     
For images with a height and width from 10 - 90, the average execution time was from 0.0000002000 seconds up to 0.0000880000 seconds. 
Further testing shows that a pattern emerges during most of the testing from 3 digits up until 5 digits where the time is just multiplied by 80-100 for each              digit added in the length and the width. Testing also showed that the maximum capacity of our program is to be estimated at around 20000 height and 20000 width.
        
ii.) Program Output with Correctness Check

https://github.com/user-attachments/assets/9dd47157-3f61-46f8-9888-7da9cb3f128c

iii.) Video.


To compile the program, follow the steps below.

### 1. Install Required Tools
Ensure the following tools are installed and added to your system PATH:

- NASM (Netwide Assembler)
- MinGW-w64 GCC (64-bit recommended)

You can verify installation with:

- nasm -v
- gcc --version


### 2. Clone or Download the Repository
Download or clone the project folder to your local machine:

- git clone <your-repo-url>
- cd <project-folder>


### 3. Assemble the x86-64 Assembly File
Use NASM to assemble the conversion routine:

- nasm -f win64 imgCvtGrayFloatToInt.asm -o imgCvtGrayFloatToInt.obj

### 4. Compile the C Source Files
Compile the program logic and helper functions:

- gcc -c main.c -o main.obj
- gcc -c image_helpers.c -o image_helpers.obj
- gcc main.obj image_helpers.obj imgCvtGrayFloatToInt.obj -o a.exe

## Roles
- Stephen Co S17B - Asm Conversion Logic
- Jedidia Julian S19B - C interface 

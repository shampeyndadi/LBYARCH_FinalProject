##Grayscale Float → Integer Converter (C + x86-64 Assembly)##

📌 Project Overview

This project converts a grayscale image represented as floating-point pixel values (0.0–1.0) into 8-bit integer grayscale values (0–255).

The conversion itself is implemented in x86-64 assembly, while the C program handles:

Input (manual or random)

Output printing

Memory allocation

Precision performance timing using QueryPerformanceCounter()

A full menu-driven interface

The goal is to demonstrate C ↔ Assembly interfacing, efficient scalar SIMD instructions, and correct rounding behavior during pixel value conversion.


i.) 
    A. Execution time (Ran 20 times) amd analysis
        For images with a height and width from 1 - 9, the average execution time was from 0.0000000200 seconds up to 0.0000002000 seconds. 
        For images with a height and width from 10 - 90, the average execution time was from 0.0000002000 seconds up to 0.0000880000 seconds. 
        Further testing shows that a pattern emerges during most of the testing from 3 digits up until 5 digits where the time is just multiplied by 80-100 for each              digit added in the length and the width. Testing also showed that the maximum capacity of our program is to be estimated at around 20000 height and 20000 width.
        
ii.) ![alt text]<"https://github.com/user-attachments/assets/9dd47157-3f61-46f8-9888-7da9cb3f128c" />


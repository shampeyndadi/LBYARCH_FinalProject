# Grayscale Float → Integer Converter (C + x86-64 Assembly)

## Project Overview

This project implements a grayscale conversion pipeline where **C** handles the driver logic and I/O, while **x86-64 assembly** performs the core pixel conversion.  

It converts grayscale pixel values from **floating-point (0.0–1.0)** into **8-bit integer grayscale (0–255)** using proportional mapping and accurate scalar SIMD instructions.

## Workflow Summary

- C handles memory allocation, user input (or random generation), image printing, and timing using QueryPerformanceCounter().
- The C program prepares the input float array and passes the parameters (input pointer, output pointer, total pixels) to the assembly function.
- Using the Windows x64 calling convention, the assembly routine receives:
    - RCX → input float array
    - RDX → output int array
    - R8  → total pixel count
- Assembly performs the core conversion:
    - Load float pixel → multiply by 255.0 → round → convert to integer.
    - Uses scalar SIMD instructions for accuracy and speed.
- The converted integer pixels are written directly into the output buffer.
- C reads back the results, prints the converted image, and checks correctness.
- Execution time is measured around the assembly call for performance analysis.

## Responsibilities  
**C Program**
- Manual or random pixel input  
- Output printing (float and integer images)  
- Memory allocation  
- High-resolution timing via `QueryPerformanceCounter()`  
- Menu-driven interface  

**Assembly Routine**
- Performs the actual per-pixel conversion  
- Formula used:  

#### intPixel = floatPixel * 255

- Utilizes scalar SIMD instructions:  
`movss`, `mulss`, `roundss`, `cvttss2si`  


## Execution Time (30 Runs) – Summary & Analysis

- For images with dimensions **1×1 to 9×9**, average runtime ranged  
**0.0000000200 s → 0.0000002000 s**
- For image sizes **10×10 to 90×90**, average runtime ranged  
**0.0000002000 s → 0.0000880000 s**
- A scaling pattern appears: from 3-digit to 5-digit image sizes,  
execution time increases roughly **×80–100** per digit increase.
- Stress testing suggests the maximum stable image size is approximately:  
**20,000 × 20,000 pixels**

## Program Output (Correctness Check)

Demo output images:  
https://github.com/user-attachments/assets/9dd47157-3f61-46f8-9888-7da9cb3f128c

---

## Video Demo
https://drive.google.com/file/d/1IiOSSdvF-_ADjEiDusElCapngBXxhypJ/view?usp=sharing

## Local Testing & Build Guide

Follow these steps to compile and run the project locally.

- Make sure NASM and GCC are installed.
- Open Command Prompt inside the project folder.
- Run:

   build.bat

The script will:
- Clean old build files  
- Assemble the .asm file  
- Compile the C files  
- Link everything  
- Automatically run the program  

## Roles
- Stephen Co S17B - Asm Conversion Logic
- Jedidiah Julian S19B - C interface


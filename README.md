Grayscale Float → Integer Converter (C + x86-64 Assembly)

📌 Project Overview

This project converts a grayscale image represented as floating-point pixel values (0.0–1.0) into 8-bit integer grayscale values (0–255).

The conversion itself is implemented in x86-64 assembly, while the C program handles:

Input (manual or random)

Output printing

Memory allocation

Precision performance timing using QueryPerformanceCounter()

A full menu-driven interface

The goal is to demonstrate C ↔ Assembly interfacing, efficient scalar SIMD instructions, and correct rounding behavior during pixel value conversion.

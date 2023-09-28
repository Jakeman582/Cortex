# Cortex
A workspace containing multiple libraries concerned with mathematics, GPGPU, and machine learning.

I'm developing this software as both a personal project, and as a reflection of what I learn during my studies in my masters degree program in data science.

The current plan is to develop this as a sort of "computation engine" where users can piece together calculations.

I want to write most of the application logic in rust so I can make use of rust's features. Because CUDA and OpenCL are easily interoperable with C++, I want to use C++ to handle any GPGPU tasks.
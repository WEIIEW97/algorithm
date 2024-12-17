#pragma once

#include <chrono>
#include <iostream>

#define TIC(id)                                                                \
  auto start_time_##id = std::chrono::high_resolution_clock::now();
#define TOC(id)                                                                \
  auto end_time_##id = std::chrono::high_resolution_clock::now();              \
  auto time_elapsed_##id = end_time_##id - start_time_##id;                    \
  std::cout                                                                    \
      << "Time elapsed for Tic-Toc " << #id << ": "                            \
      << std::chrono::duration<double, std::milli>(time_elapsed_##id).count()  \
      << " ms" << std::endl;

#pragma once

#define ZFLIU
#ifdef ZFLIU
#include <iostream>
extern void MarkPoint(std::string, std::string, int);
#define Mark(x) MarkPoint(#x,__FILE__,__LINE__)
#else
#define Mark(x)
#endif
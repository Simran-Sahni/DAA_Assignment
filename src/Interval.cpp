//
// Created by Radhesh Sarma on 14-03-2021.
//
#include<algorithm>
#include "../include/Interval.h"
using std :: min;
using std :: max;
Interval ::Interval(int bottom, int top) : bottom(min(bottom, top)),
                                           top(max(bottom, top)) {}

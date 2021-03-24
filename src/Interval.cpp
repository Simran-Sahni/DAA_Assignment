//
// Created by Radhesh Sarma on 14-03-2021.
//
#include "../include/Interval.h"
#include <algorithm>
using std ::max;
using std ::min;
/**
 *
 * @param bottom
 * @param top
 */
Interval ::Interval(int bottom, int top)
    : bottom(min(bottom, top)), top(max(bottom, top)) {}

bool Interval::operator==(const Interval &i) const {
    return this->bottom == i.bottom and this->top == i.top;
}



bool Interval::operator <(const Interval &i) const {
    if (this->bottom == i.bottom)
        return this->top < i.top;
    else
        return this->bottom < i.bottom;
}



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
/**
 *
 * @param i
 * @return
 */
bool Interval::operator==(const Interval &i) {
  return this->bottom == i.bottom and this->top == i.top;
}

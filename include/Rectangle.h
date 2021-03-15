//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_RECTANGLE_H
#define DAA_ASSIGNMENT_RECTANGLE_H
#include "Interval.h"
#include <vector>
using std ::vector;
class Rectangle {
public:
  int x_left;
  int x_right;
  int y_bottom;
  int y_top;
  Rectangle(int x_left, int x_right, int y_bottom, int y_top);
  Rectangle(Interval xInterval, Interval yInterval);
  vector<Interval> getIntervals() const;
};

#endif // DAA_ASSIGNMENT_RECTANGLE_H
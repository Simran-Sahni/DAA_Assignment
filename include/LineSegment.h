//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_LINESEGMENT_H
#define DAA_ASSIGNMENT_LINESEGMENT_H

#include "Interval.h"
class LineSegment {
public:
  Interval line;
  int coordinate;
  LineSegment(Interval line, int coordinate);
};

#endif // DAA_ASSIGNMENT_LINESEGMENT_H

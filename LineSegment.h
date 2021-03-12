#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include "Interval.h"
class LineSegment{
 public:
  Interval line;
  int coordinate;
  LineSegment(Interval line, int coordinate);
};

#endif  // DAA_ASSIGNMENT_LINESEGMENT_H_

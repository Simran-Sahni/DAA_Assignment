//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_INTERVAL_H
#define DAA_ASSIGNMENT_INTERVAL_H

class Interval {
public:
  int bottom;
  int top;
  Interval(int bottom, int top);
  bool operator==(const Interval &i) const;
  bool operator<(const Interval &i) const;
};

#endif // DAA_ASSIGNMENT_INTERVAL_H

//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_STRIPE_H
#define DAA_ASSIGNMENT_STRIPE_H

#include "Interval.h"
#include <vector>
using std ::vector;

class Stripe {
public:
  Interval x_interval;
  Interval y_interval;
  vector<Interval> x_union;
  void setXUnion(const vector<Interval> &xUnion);
  Stripe(Interval x_interval, Interval y_interval, vector<Interval> x_union);
  int measure();
  long double x_measure;
};

#endif // DAA_ASSIGNMENT_STRIPE_H

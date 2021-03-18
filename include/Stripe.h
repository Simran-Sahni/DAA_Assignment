//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_STRIPE_H
#define DAA_ASSIGNMENT_STRIPE_H

#include "Interval.h"
#include "Ctree.h"
#include <vector>
using std ::vector;

class Stripe {
public:
  Interval x_interval;
  Interval y_interval;
  Ctree *tree;
  long double x_measure;
  void setV(vector<long double> &v);
  vector<long double> v;
  Stripe(Interval x_interval, Interval y_interval, long double x_measure);
  Stripe(Interval x_interval, Interval y_interval, long double x_measure, Ctree *tree);
  void setXMeasure(long double xMeasure);

};

#endif // DAA_ASSIGNMENT_STRIPE_H

//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_MEASUREHELPER_H
#define DAA_ASSIGNMENT_MEASUREHELPER_H

#include "Edge.h"
#include "Point.h"
#include "Rectangle.h"
#include "Stripe.h"
#include "StripeOutput.h"
#include <vector>
const int INF = (1LL << 30) - 1;

class MeasureHelper {
public:
  static vector<Point> union_of_rectangle(vector<Rectangle> &r);
  static vector<int> y_set(vector<Rectangle> &r);
  static vector<Interval> partition(vector<int> &coordinates);
  static vector<Stripe> copy(vector<Stripe> S, vector<int> coord_P,
                             Interval x_int);
  static void blacken(vector<Stripe> &S, vector<Edge> &J);
  static vector<Stripe> concat(vector<Stripe> &s1, vector<Stripe> &s2,
                               vector<int> &coord_p, Interval x_int);
  static StripeOutput stripes(vector<Edge> V, Interval x_ext);
  static long double rectangle_dac(vector<Rectangle> r);
};

#endif // DAA_ASSIGNMENT_MEASUREHELPER_H

//
// Created by Radhesh Sarma on 16-03-2021.
//

#ifndef DAA_ASSIGNMENT_CONTOURHELPER_H
#define DAA_ASSIGNMENT_CONTOURHELPER_H
#include "Stripe.h"
#include "Edge.h"
#include "StripeOutput.h"
#include "Rectangle.h"
class ContourHelper {
public:
  static vector<Stripe> copy(vector<Stripe> S, vector<int> coord_P,
                             Interval x_int);
  static void blacken(vector<Stripe> &S, vector<Edge> &J);
  static vector<Stripe> concat(vector<Stripe> &s1, vector<Stripe> &s2,
                               vector<int> &coord_p, Interval x_int);
  static StripeOutput stripes(vector<Edge> V, Interval x_ext);
  static long double rectangle_dac(vector<Rectangle> r);
};

#endif // DAA_ASSIGNMENT_CONTOURHELPER_H

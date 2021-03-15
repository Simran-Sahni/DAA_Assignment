//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_MEASUREHELPER_H
#define DAA_ASSIGNMENT_MEASUREHELPER_H

#include "Point.h"
#include "Rectangle.h"
#include "Stripe.h"
#include "Edge.h"
#include <vector>

class MeasureHelper {
public:
  static vector<Point> union_of_rectangle(vector<Rectangle> &r);
  static vector<int> y_set(vector<Rectangle> &r);
  static vector<Interval> partition(vector<int> &coordinates);
  static vector<Stripe> copy(vector<Stripe> S, vector<int> coord_P, Interval x_int);
  static void blacken(vector<Stripe> &S, vector<Interval> &J);
  static vector<Stripe> concat(vector<Stripe> &s1,vector<Stripe> &s2,vector<int> &coord_p,Interval x_int);
  static void stripes(vector<Edge> V,Interval x_ext,vector<Interval> &L,vector<Interval> &R,vector<int> &coord,vector<Stripe> &S);
};

#endif // DAA_ASSIGNMENT_MEASUREHELPER_H

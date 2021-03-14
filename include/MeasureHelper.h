//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_MEASUREHELPER_H
#define DAA_ASSIGNMENT_MEASUREHELPER_H

#include "Stripe.h"
#include "Point.h"
#include "Rectangle.h"
#include <set>
using std :: set;
auto cmp = [](Point a, Point b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
};

class MeasureHelper {
public:
    int measure(set<Stripe> s);
    set<Point, decltype(cmp)> _union(set<Rectangle> r);
    set<int> y_set(set<Rectangle> r);
};


#endif //DAA_ASSIGNMENT_MEASUREHELPER_H

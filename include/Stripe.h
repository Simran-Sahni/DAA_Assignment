//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_STRIPE_H
#define DAA_ASSIGNMENT_STRIPE_H

#include "Interval.h"
#include <set>
using std :: set;

class Stripe {
 public:
    Interval x_interval;
    Interval y_interval;
    set<Interval> x_union;

    Stripe(Interval x_interval, Interval y_interval, set<Interval> x_union);
    int measure();
};


#endif //DAA_ASSIGNMENT_STRIPE_H

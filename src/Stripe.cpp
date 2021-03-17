//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/Stripe.h"

Stripe ::Stripe(Interval x_interval, Interval y_interval, long double x_measure)
    : x_interval(x_interval), y_interval(y_interval), x_measure(x_measure) {}
Stripe ::Stripe(Interval x_interval, Interval y_interval, long double x_measure,Ctree *tree)
    : x_interval(x_interval), y_interval(y_interval), x_measure(x_measure), tree(tree) {}
void Stripe::setXMeasure(long double xMeasure) { x_measure = xMeasure; }

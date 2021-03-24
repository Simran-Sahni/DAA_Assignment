//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/Stripe.h"
#include <bits/stdc++.h>
using namespace  std;
/**
 *
 * @param x_interval
 * @param y_interval
 * @param x_measure
 */
Stripe ::Stripe(Interval x_interval, Interval y_interval, long double x_measure)
    : x_interval(x_interval), y_interval(y_interval), x_measure(x_measure) {}
/**
 *
 * @param x_interval
 * @param y_interval
 * @param x_measure
 * @param tree
 */
Stripe ::Stripe(Interval x_interval, Interval y_interval, long double x_measure,
                Ctree *tree)
    : x_interval(x_interval), y_interval(y_interval), x_measure(x_measure),
      tree(tree) {}
/**
 *
 * @param xMeasure
 */
void Stripe::setXMeasure(long double xMeasure) { x_measure = xMeasure; }
/**
 *
 * @param v
 */
void Stripe::setV(vector<long double> &v) { Stripe::v = v; }

void Stripe::print() {
    cout<<"X_interval is: "<<x_interval.bottom<<" "<<x_interval.top<<"\n";
    cout<<"Y_interval is: "<<y_interval.bottom<<" "<<y_interval.top<<"\n";
    cout<<"X_measure is "<<x_measure<<"\n";
    if(tree)
    cout<<"Tree is: "<<tree->lru<<" "<<tree->leftson<<" "<<tree->rightson<<" "<<tree->x<<"\n";
    cout<<"\n";
}

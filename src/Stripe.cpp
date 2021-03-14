//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/Stripe.h"

Stripe ::Stripe(Interval x_interval, Interval y_interval,
                vector<Interval> x_union)
    : x_interval(x_interval), y_interval(y_interval), x_union(x_union) {}
int Stripe ::measure() {
  int ans = 0;
  for (auto &interval : x_union)
    ans += (interval.top - interval.bottom);
  return ans * (y_interval.top - y_interval.bottom);
}
void Stripe::setXUnion(const vector<Interval> &xUnion) { x_union = xUnion; }

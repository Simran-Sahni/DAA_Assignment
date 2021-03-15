//
// Created by Radhesh Sarma on 15-03-2021.
//

#ifndef DAA_ASSIGNMENT_STRIPEOUTPUT_H
#define DAA_ASSIGNMENT_STRIPEOUTPUT_H

#include "Interval.h"
#include "Stripe.h"
#include <vector>
using std :: vector;
class StripeOutput {
public:
  vector<Interval> L;

  vector<Interval> R;
  vector<int> coord_p;
  vector<Stripe> S;
  StripeOutput(const vector<Interval> l, const vector<Interval> r,
               const vector<int> coordP, const vector<Stripe> s);
  StripeOutput();
};

#endif // DAA_ASSIGNMENT_STRIPEOUTPUT_H


//
// Created by Radhesh Sarma on 15-03-2021.
//

#include "../include/StripeOutput.h"
StripeOutput::StripeOutput(const vector<Edge> l, const vector<Edge> r,
                           const vector<int> coordP, const vector<Stripe> s)
    : L(l), R(r), coord_p(coordP), S(s) {}
StripeOutput::StripeOutput() {}
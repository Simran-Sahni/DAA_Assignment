#include <iostream>
#include <iomanip>
#include<set>
#include "Stripe.h"
  int Stripe :: measure() {
    int ans = 0;
    for (auto &interval : x_union)
      ans += (interval.top - interval.bottom);
    return ans * (y_interval.top - y_interval.bottom);
  }

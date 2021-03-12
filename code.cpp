#include <bits/stdc++.h>
using std :: cout;
using std :: endl;
#include "Point.h"
#include "Interval.h"
#include "LineSegment.h"
#include "Rectangle.h"
#include "EdgeType.h"
#include "Stripe.h"
#include "MeasureHelper.h"
#define int int64_t
const int INF = (1LL << 62) - 1;

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  Point p1(1, 2);

  Interval i1(1, 2);

  LineSegment l1(i1, 10);

  Rectangle r1(1, 2, 3, 4);

  EdgeType e1("LEFT");

  return 0;
}

#include "MeasureHelper.h"

  int MeasureHelper :: measure(set<Stripe> s) {
    int ans = 0;
    for (auto interval : s)
      ans += interval.measure();
    return ans;
  }

  set<Point, decltype(cmp)> MeasureHelper :: _union(set<Rectangle> r) {
    set<Point, decltype(cmp)> ans(cmp);
    for (auto &rectangle : r) {
      Point p1(rectangle.x_left, rectangle.y_top);
      Point p2(rectangle.x_left, rectangle.y_bottom);
      Point p3(rectangle.x_right, rectangle.y_top);
      Point p4(rectangle.x_right, rectangle.y_bottom);
      ans.insert(p1);
      ans.insert(p2);
      ans.insert(p3);
      ans.insert(p4);
    }
    return ans;
  }

    set<int> MeasureHelper :: y_set(set<Rectangle> r) {
    set<int> ans;
    for (auto &rectangle : r) {
      ans.insert(rectangle.y_top);
      ans.insert(rectangle.y_bottom);
    }
    return ans;
  }

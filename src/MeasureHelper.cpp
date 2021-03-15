//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/MeasureHelper.h"
#include "../include/IntervalHelper.h"
#include <algorithm>
vector<Point> MeasureHelper ::union_of_rectangle(vector<Rectangle> &r) {
  vector<Point> ans;

  for (auto &rectangle : r) {
    Point p1(rectangle.x_left, rectangle.y_top);
    Point p2(rectangle.x_left, rectangle.y_bottom);
    Point p3(rectangle.x_right, rectangle.y_top);
    Point p4(rectangle.x_right, rectangle.y_bottom);
    ans.push_back(p1);
    ans.push_back(p2);
    ans.push_back(p3);
    ans.push_back(p4);
  }
  return ans;
}

vector<int> MeasureHelper ::y_set(vector<Rectangle> &r) {
  vector<int> ans;
  for (auto &rectangle : r) {
    ans.push_back(rectangle.y_top);
    ans.push_back(rectangle.y_bottom);
  }
  return ans;
}

vector<Interval> MeasureHelper ::partition(vector<int> &coordinates) {
  vector<Interval> ans;
  for (int i = 1; i < coordinates.size(); i++) {
    Interval new_interval(coordinates[i], coordinates[i - 1]);
    ans.push_back(new_interval);
  }
  return ans;
}

vector<Stripe> MeasureHelper ::copy(vector<Stripe> S, vector<int> coord_P,
                                    Interval x_interval) {
  vector<Stripe> ans;
  vector<Interval> partition_P = partition(coord_P);

  for (auto &y_interval : partition_P) {
    Stripe new_stripe(x_interval, y_interval, 0);
    ans.push_back(new_stripe);
  }

  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < ans.size(); j++) {
      if (IntervalHelper ::is_subset_of(ans[i].y_interval, S[i].y_interval)) {
        ans[i].setXMeasure(S[i].x_measure);
      }
    }
  }

  return ans;
}

vector<Stripe> MeasureHelper::concat(vector<Stripe> &s1, vector<Stripe> &s2,
                                     vector<int> &coord_P,
                                     Interval x_interval) {
  vector<Stripe> ans;
  vector<Interval> partition_P = partition(coord_P);

  for (auto &y_interval : partition_P) {
    Stripe new_stripe(x_interval, y_interval, 0);
    ans.push_back(new_stripe);
  }

  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      for (int k = 0; k < ans.size(); k++) {
        if (s1[i].y_interval == s2[i].y_interval and
            s2[i].y_interval == ans[i].y_interval) {
          ans[i].setXMeasure(s1[i].x_measure + s2[i].x_measure);
        }
      }
    }
  }
  return ans;
}

void MeasureHelper::blacken(vector<Stripe> &S, vector<Interval> &J) {

  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < J.size(); j++) {
      if (IntervalHelper ::is_subset_of(S[i].y_interval, J[j])) {
        S[i].setXMeasure(S[i].x_interval.top - S[i].x_interval.bottom);
      }
    }
  }
}
StripeOutput MeasureHelper::stripes(vector<Edge> V, Interval x_ext) {
  vector<Interval> L;
  vector<Interval> R;
  vector<int> coord_P;
  vector<Stripe> S;

  if (V.size() == 1) {
    Edge v = V[0];
    if (v.type == LEFT) {
      L = {v.interval};
      R = {};
    } else {
      L = {};
      R = {v.interval};
    }

    coord_P = {-INF, v.interval.bottom, v.interval.top, INF};
    vector<Interval> partition_P = partition(coord_P);
    S.clear();
    for (auto &interval : partition_P) {
      Stripe new_stripe(x_ext, interval, 0);

      S.push_back(new_stripe);
    }
    for (auto &stripe : S) {
      if (v.type == LEFT) {
        stripe.setXMeasure(x_ext.top - v.coord);
      } else {
        stripe.setXMeasure(v.coord - x_ext.bottom);
      }
    }

  } else {
    vector<Edge> V1;
    vector<Edge> V2;
    sort(V.begin(), V.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.coord < rhs.coord;
    });
    int m = V.size() / 2;
    for (int i = 0; i < V.size(); i++) {
      if (i <= m)
        V1.push_back(V[i]);
      else
        V2.push_back(V[i]);
    }
    int xm = V[m].coord;
    Interval left_interval(x_ext.bottom, xm);
    Interval right_interval(xm, x_ext.top);

    StripeOutput left = stripes(V1, left_interval);
    StripeOutput right = stripes(V2, right_interval);

    vector<Interval> LR = IntervalHelper ::find_intersection(left.L, right.R);

    StripeOutput ans;
    vector<Interval> L1_compliment_LR = IntervalHelper ::compliment(left.L, LR);
    ans.L = IntervalHelper::find_union(L1_compliment_LR, right.L);

    vector<Interval> R2_compliment_LR =
        IntervalHelper ::compliment(right.R, LR);
    ans.R = IntervalHelper ::find_union(left.R, R2_compliment_LR);

    ans.coord_p = IntervalHelper ::find_union(left.coord_p, right.coord_p);

    vector<Stripe> S_left = copy(left.S, ans.coord_p, left_interval);
    vector<Stripe> S_right = copy(right.S, ans.coord_p, right_interval);

    blacken(S_left, R2_compliment_LR);
    blacken(S_right, L1_compliment_LR);

    ans.S = concat(S_left, S_right, ans.coord_p, x_ext);

    return ans;
  }
}
long double MeasureHelper::rectangle_dac(vector<Rectangle> r) {
  vector<Edge> vrx;
  for (auto &rectangle : r) {
    for (auto &edge : rectangle.getVerticalEdges()) {
      vrx.push_back(edge);
    }
  }
  StripeOutput ans = stripes(vrx, Interval(-INF, INF));

  long double measure = 0;

  for (auto &stripe : ans.S) {
    measure +=
        stripe.x_measure * (stripe.y_interval.top - stripe.y_interval.bottom);
  }
  return measure;
}

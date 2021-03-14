//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/MeasureHelper.h"
#include "../include/IntervalHelper.h"
int MeasureHelper ::measure(vector<Stripe> &s) {
  int ans = 0;
  for (auto &interval : s)
    ans += interval.measure();
  return ans;
}
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
    Stripe new_stripe(x_interval, y_interval, vector<Interval>());
    ans.push_back(new_stripe);
  }

  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < ans.size(); j++) {
      if (IntervalHelper ::is_subset_of(ans[i].y_interval, S[i].y_interval)) {
        ans[i].setXUnion(S[i].x_union);
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
    Stripe new_stripe(x_interval, y_interval, vector<Interval>());
    ans.push_back(new_stripe);
  }

  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      for (int k = 0; k < ans.size(); k++) {
        if (s1[i].y_interval == s2[i].y_interval and
            s2[i].y_interval == ans[i].y_interval) {
          ans[i].setXUnion(
              IntervalHelper ::find_union(s1[i].x_union, s2[i].x_union));
        }
      }
    }
  }
  return ans;
}

void MeasureHelper::blacken(vector<Stripe> &S, vector<Interval> &J) {

  for(int i = 0; i < S.size(); i++){
    for(int j = 0; j < J.size(); j++){
      if(IntervalHelper :: is_subset_of(S[i].y_interval,J[j])){
        S[i].setXUnion(vector<Interval> ({S[i].x_interval}));
      }
    }
  }
}

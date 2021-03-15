//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/IntervalHelper.h"
bool IntervalHelper ::is_subset_of(Interval i1, Interval i2) {
  return i1.bottom >= i2.bottom and i1.top <= i2.top;
}
vector<Interval> IntervalHelper::find_union(vector<Interval> &i1,
                                            vector<Interval> &i2) {
  return vector<Interval>();
}
vector<Interval> IntervalHelper::find_intersection(vector<Interval> &i1,
                                                   vector<Interval> &i2) {
  return vector<Interval>();
}
bool IntervalHelper::do_they_intersect(Interval i1, Interval i2) {
  return false;
}
vector<Interval> IntervalHelper::compliment(vector<Interval> i1,
                                            vector<Interval> i2) {
  return vector<Interval>();
}
Interval IntervalHelper::compliment(Interval i1, Interval i2) {
  return Interval(0, 0);
}

//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/IntervalHelper.h"
#include <bits/stdc++.h>
using namespace std;

const int INF = (1LL << 30) - 1;

/**
 * Returns whether one interval is subset of another
 * @param i1 First interval
 * @param i2 Second interval
 * @return boolean value
 */
bool IntervalHelper ::is_subset_of(Interval i1, Interval i2) {
  return i1.bottom >= i2.bottom and i1.top <= i2.top;
}

/**
 * Finds union of 2 vectors of intervals
 * @param i1 First set of intervals
 * @param i2 Second set of intervals
 * @return vector(mathematical set) of Intervals
 */
vector<Interval> IntervalHelper::find_union(vector<Interval> i1,
                                            vector<Interval> i2) {

  i1.insert(i1.end(), i2.begin(), i2.end());
  vector<pair<int, int>> v;
  for (auto ind : i1)
    v.push_back({ind.bottom, 0});
  for (auto ind : i1)
    v.push_back({ind.top, 1});
  int in = 0; // keeps count of open intervals 'in' consideration
  vector<Interval> ans;
  int ind = 0; // index/time stamp with which to push in answer array
  sort(v.begin(), v.end());
  for (auto pos : v) {
    if (pos.second == 1) // 1 denotes, closing of an interval,so count of the
                         // ones inside our open list has to be decreased by 1
    {
      in--;
    } else {
      if (in == 0)
        ind = pos.first;
      in++;
    }
    if (in == 0) {
      // if no more intervals open or in => its a closed interval, so push in
      // the answer!
      ans.push_back(Interval(ind, pos.first));
    }
  }
  return ans;
}

/**
 * Returns a set of intervals that is intersection of the two
 * An essential mathematical function in Divide & conquer
 * @param i1 First set of intervals
 * @param i2 Second set of intervals
 * @return set of intervals
 */
vector<Interval> IntervalHelper::find_intersection(vector<Interval> i1,
                                                   vector<Interval> i2) {
  vector<Interval> ans;
  i1.insert(i1.end(), i2.begin(), i2.end());
  Interval prev = i1[0];
  for (int i = 1; i < i1.size(); i++) {

    bool are_intersecting = do_they_intersect(i1[i], prev);
    if (are_intersecting) {
      prev = find_intersection(prev, i1[i]);
    } else {
      ans.push_back(prev);
      ans.push_back(i1[i]);
      prev = i1[i + 1];
      i++;
    }
  }

  return ans;
}


/**
 * Should return set of intervals that form compliment of the two
 * @param i1
 * @param i2
 * @return vector of intervals
 */
vector<Interval> IntervalHelper::compliment(vector<Interval> i1,
                                            vector<Interval> i2) {
  return vector<Interval>();
}


/**
 * Checks if the two intervals intersect
 * @param i1 First Interval
 * @param i2 Second interval
 * @return Boolean value: intersection
 */
bool IntervalHelper::do_they_intersect(Interval i1, Interval i2) {
  int a = i1.bottom, b = i1.top, c = i2.bottom, d = i2.top;
  bool intersect = false;
  if (a >= c && a <= d)
    intersect = true;
  else if (c >= a && c <= b)
    intersect = true;

  return intersect;
}


/**
 * Overloaded function to return the union of the two intervals
 * @param i1 First interval
 * @param i2 Second interval
 * @return Another interval, union of the two
 */
Interval IntervalHelper::find_union(Interval i1, Interval i2) {
  int first = min(i1.bottom, i2.bottom);
  int second = max(i1.top, i2.top);
  Interval united(first, second);

  return united;
}

/**
 * Overloaded function to return the intersection of 2 intervals
 * @param i1 First interval
 * @param i2 Second interval
 * @return Interval that is intersection of the two
 */
Interval IntervalHelper::find_intersection(Interval i1, Interval i2) {
  int a, b, c, d;
  if (i1.bottom > i2.bottom) {
    a = i2.bottom;
    b = i2.top;
    c = i1.bottom;
    d = i1.top;
  } else {
    a = i1.bottom;
    b = i1.top;
    c = i2.bottom;
    d = i2.top;
  }
  int first = min(b, c);
  int second = max(a, d);
  Interval intersection(first, second);
  return intersection;
}

/**
 * Function to return the compliment of 2 intervals
 * @param i1 First interval
 * @param i2 Second interval
 * @return Another interval, i.e compliment of the two
 */
Interval IntervalHelper::compliment(Interval i1, Interval i2) {
  Interval united = find_union(i1, i2);
  Interval intersection = find_intersection(i1, i2);
  int a = united.bottom, b = united.top;
  int c = intersection.bottom, d = intersection.top;
  int first = min(a, c);
  int second = min(b, d);
  return Interval(first, second);
}

/**
 * A helper function to return the union of 2 vectors of integers
 * @param v1 first integer vector
 * @param v2 second integer vector
 * @return Merged integer vector
 */
vector<int> IntervalHelper::find_union(vector<int> v1, vector<int> v2) {
  set<int> s(v1.begin(),v1.end());
  for(auto &i : v2)s.insert(i);
  vector<int> ans(s.begin(),s.end());
  return ans;
}
// to make L
 // put L2 in L
// then iteratate L1
// take edge in L1 which does not have partner in R2

// to Make R
 // put R1
 // then iterate R2
// take edge in R2 which does not have partner in L1


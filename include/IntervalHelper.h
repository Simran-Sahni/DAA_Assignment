//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_INTERVALHELPER_H
#define DAA_ASSIGNMENT_INTERVALHELPER_H
#include "vector"
using std::vector;
#include "Interval.h"
class IntervalHelper {
public:
  static vector<Interval>
  find_union(vector<Interval> &i1,
             vector<Interval> &i2); // find union of i1 and i2
  static vector<Interval>
  find_intersection(vector<Interval> &i1,
                    vector<Interval> &i2); // finds intersection of i1 and i2
  static bool is_subset_of(Interval i1,
                           Interval i2); // checks if i1 is a subset of i2
  static bool do_they_intersect(Interval i1, Interval i2);
  static vector<Interval> compliment(vector<Interval> i1,vector<Interval> i2);
  static Interval compliment(Interval i1,Interval i2);
};

#endif // DAA_ASSIGNMENT_INTERVALHELPER_H

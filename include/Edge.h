//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_EDGE_H
#define DAA_ASSIGNMENT_EDGE_H

#include "Interval.h"
#include <iostream>
using std ::string;
static const char LEFT[] = "LEFT";
static const char RIGHT[] = "RIGHT";
static const char UP[] = "UP";
static const char BOTTOM[] = "BOTTOM";

class Edge {
public:
  string type;
  Interval interval;
  int coord;
  Edge(string &type, Interval &interval, int coord);
};

#endif // DAA_ASSIGNMENT_EDGE_H

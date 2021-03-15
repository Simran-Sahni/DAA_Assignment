//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/Edge.h"
#include <iostream>
using std::runtime_error;
Edge::Edge(string &type, Interval &interval, int coord)
    : type(type), interval(interval), coord(coord) {
  if (type == LEFT || type == RIGHT || type == UP || type == BOTTOM)
    this->type = type;
  else
    throw runtime_error("Not a valid edge type!");
}

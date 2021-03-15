//
// Created by Radhesh Sarma on 14-03-2021.
//
#include "../include/EdgeType.h"
#include <iostream>
using std::runtime_error;

EdgeType ::EdgeType(const string type) {
  if (type == LEFT || type == RIGHT || type == UP || type == BOTTOM)
    this->type = type;
  else
    throw runtime_error("Not a valid edge type!");
}

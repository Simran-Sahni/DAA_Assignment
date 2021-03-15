//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/Rectangle.h"
using std ::vector;
Rectangle ::Rectangle(int x_left, int x_right, int y_bottom, int y_top)
    : x_left(x_left), x_right(x_right), y_bottom(y_bottom), y_top(y_top) {}

Rectangle ::Rectangle(Interval xInterval, Interval yInterval)
    : x_right(xInterval.top), y_bottom(yInterval.bottom), y_top(yInterval.top) {
}

vector<Edge> Rectangle ::getVerticalEdges() const {
  return vector<Edge>{Edge(LEFT,Interval(y_bottom,y_top),x_left),Edge(LEFT,Interval(y_bottom,y_top),x_right)};
}
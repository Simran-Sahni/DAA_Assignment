//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/Rectangle.h"
using std ::vector;
/**
 *
 * @param x_left
 * @param x_right
 * @param y_bottom
 * @param y_top
 */
Rectangle ::Rectangle(int x_left, int x_right, int y_bottom, int y_top)
    : x_left(x_left), x_right(x_right), y_bottom(y_bottom), y_top(y_top) {}

/**
 *
 * @param xInterval
 * @param yInterval
 */
Rectangle ::Rectangle(Interval xInterval, Interval yInterval)
    : x_right(xInterval.top), y_bottom(yInterval.bottom), y_top(yInterval.top) {
}
/**
 *
 * @return
 */
vector<Edge> Rectangle ::getVerticalEdges() const {
  return vector<Edge>{Edge(LEFT, Interval(y_bottom, y_top), x_left, x_right),
                      Edge(RIGHT, Interval(y_bottom, y_top), x_right, x_left)};
}
/**
 *
 * @return
 */
vector<Edge> Rectangle::getHorizontalEdges() const {
  return vector<Edge>{Edge(BOTTOM, Interval(x_left, x_right), y_bottom, y_top),
                      Edge(UP, Interval(x_left, x_right), y_top, y_bottom)};
}

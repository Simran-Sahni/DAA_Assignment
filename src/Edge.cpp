//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/Edge.h"
#include <iostream>
using namespace std;
using std::runtime_error;
/**
 *
 * @param type
 * @param interval
 * @param coord
 */
Edge::Edge(string type, Interval interval, int coord)
    : type(type), interval(interval), coord(coord) {}
/**
 *
 * @param type
 * @param interval
 * @param coord
 * @param partner_coordinate
 */
Edge::Edge(string type, Interval interval, int coord,int partner_coordinate)
    : type(type), interval(interval), coord(coord),partner_coordinate(partner_coordinate) {}

void Edge::print() {
    cout << type << " Interval(" << interval.bottom << " " << interval.top << ") following are coord & partner coord"
         << coord <<" "<<partner_coordinate<<"\n";
}

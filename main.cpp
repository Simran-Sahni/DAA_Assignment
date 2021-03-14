#include <iostream>
#include "include/Point.h"
#include "include/Interval.h"
#include "include/LineSegment.h"
#include "include/Rectangle.h"
#include "include/EdgeType.h"
using std:: cout;
int main() {

    Point p1(1, 2);

    Interval i1(1, 2);

    LineSegment l1(i1, 10);

    Rectangle r1(1, 2, 3, 4);

    EdgeType e1("LEFT");

    cout << "DAA";



    return 0;
}

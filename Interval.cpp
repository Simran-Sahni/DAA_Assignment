#include <iostream>
#include <iomanip>
#include<algorithm>
#include "Interval.h"
using std :: min;
using std :: max;
Interval ::Interval(int bottom, int top) : bottom(min(bottom, top)),
                                           top(max(bottom, top)) {}

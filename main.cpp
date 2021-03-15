#include <iostream>
#include "include/Point.h"
#include "include/Interval.h"
#include "include/IntervalHelper.h"
#include "include/LineSegment.h"
#include "include/Rectangle.h"
using std:: cout;
int main() {

    Point p1(1, 2);

    Interval i1(2, 5);
    Interval i2(3,6);
    Interval i3(8,9);
    vector<Interval> A;
    A.push_back(i1);
    A.push_back(i2);
    A.push_back(i3);

    Interval i4(1, 4);
    Interval i5(12,15);
    Interval i6(7,9);
    vector<Interval> B;
    B.push_back(i4);
    B.push_back(i5);
    B.push_back(i6);

    vector<Interval> united = IntervalHelper::find_union(A,B);
    vector<Interval> inter = IntervalHelper::find_intersection(A,B);

    cout<<"Union of interval sets is: \n";
    for(auto x:united)
        cout<<x.bottom<<" "<<x.top<<"\n";

    cout<<"Intersection of interval sets is: \n";
    for(auto x:inter)
        cout<<x.bottom<<" "<<x.top<<"\n";
    /*cout<<IntervalHelper::do_they_intersect(i2,i1);
    Interval ans =IntervalHelper::find_union(i1,i2);
    cout<<ans.bottom<<" "<<ans.top<<"\n";*/

    LineSegment l1(i1, 10);

    Rectangle r1(1, 2, 3, 4);



    cout << "DAA";



    return 0;
}

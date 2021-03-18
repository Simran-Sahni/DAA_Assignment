#include <iostream>
#include <iomanip>
#include "include/Point.h"
#include "include/Interval.h"
#include "include/IntervalHelper.h"
#include "include/Rectangle.h"
#include "include/MeasureHelper.h"
using std:: cout;
using std :: endl;
using std :: cin;
using std :: swap;

int main() {


  vector<Rectangle> v;


  int n;
  cin >> n;


  for(int i = 0; i < n; i++)
  {
    int x,y,z,w;
    cin >> x >> y >> z >> w;
    if(x > y)swap(x,y);
    if(z > w)swap(z,w);

     v.push_back(Rectangle(x,y,z,w));


  }

  long double ans = MeasureHelper :: rectangle_dac(v);

  cout << "Measure is " << std :: setprecision(15) << ans << endl;

    return 0;
}

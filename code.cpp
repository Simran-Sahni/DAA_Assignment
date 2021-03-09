#include <bits/stdc++.h>
using namespace std;
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define int long long
#define endl "\n"
#define double long double
#define trace1(x) cerr << #x << ": " << x << endl
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
const int N = 200005;
const int INF = (1LL << 62) - 1;
static const string LEFT = "left";
static const string RIGHT = "right";
static const string UP = "up";
static const string BOTTOM = "bottom";

class Point
{
public:
  int x;
  int y;
  Point(int x, int y) : x(x),
                        y(y){};
};

class Interval
{
public:
  int bottom;
  int top;
  Interval(int bottom, int top) : bottom(min(bottom,top)),
                                  top(max(bottom,top)){};
};

class LineSegment
{
public:
  Interval line;
  int coordinate;
  LineSegment(Interval line, int coordinate) : line(line),
                                               coordinate(coordinate){};
};

class Rectangle
{
public:
  int x_left;
  int x_right;
  int y_bottom;
  int y_top;
  Rectangle(int x_left, int x_right, int y_bottom, int y_top) : x_left(x_left),
                                                                x_right(x_right),
                                                                y_bottom(y_bottom),
                                                                y_top(y_top){};

  Rectangle(Interval xInterval, Interval yInterval) : x_left(xInterval.bottom),
                                                      x_right(xInterval.top),
                                                      y_bottom(yInterval.bottom),
                                                      y_top(yInterval.top){};

  vector<Interval> getIntervals() { return vector<Interval>{Interval(x_left, x_right),
                                                            Interval(y_bottom, y_top)}; }
};

class EdgeType
{
public:
  string type;

  EdgeType(string type)
  {
    if (type == LEFT or type == RIGHT or type == UP or type == BOTTOM)
      this->type = type;
    else
      throw runtime_error("Not a valid edge type!");
  }
};

class Edge
{
public:
  Interval interval;
  int coord;
  EdgeType sideType;
  Edge(Interval interval, int coord, EdgeType sideType) : interval(interval),
                                                          coord(coord),
                                                          sideType(sideType){};
};

class Stripe
{
public:
  Interval x_interval;
  Interval y_interval;
  set<Interval> x_union;

  Stripe(Interval x_interval, Interval y_interval, set<Interval> x_union) : x_interval(x_interval),
                                                                            y_interval(y_interval),
                                                                            x_union(x_union){};
  int measure()
  {
    int ans = 0;
    for(auto &interval : x_union)ans += (interval.top - interval.bottom);
    return ans * (y_interval.top - y_interval.bottom);
  }


};

class MeasureHelper
{

int measure(set<Stripe> s)
{
  int ans = 0;
  for(auto interval : s)ans += interval.measure();
  return ans;
}

set<Point> _union(set<Rectangle> r)
{
  set<Point> ans;
  for(auto &rectangle : r)
  {
    Point p1(rectangle.x_left,rectangle.y_top);
    Point p2(rectangle.x_left,rectangle.y_bottom);
    Point p3(rectangle.x_right,rectangle.y_top);
    Point p4(rectangle.x_right,rectangle.y_bottom);
    ans.insert(p1);
    ans.insert(p2);
    ans.insert(p3);
    ans.insert(p4);
  }
  return ans;
}

set<int> y_set(set<Rectangle> r)
{
  set<int> ans;
  for(auto &rectangle : r)
  {
    ans.insert(rectangle.y_top);
    ans.insert(rectangle.y_bottom);
  }
  return ans;
}

};

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  IOS

      Point p1(1, 2);
  cout << p1.x << endl;

  return 0;
}

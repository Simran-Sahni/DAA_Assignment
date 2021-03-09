#include <bits/stdc++.h>
using namespace std;
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
#define double long double
#define trace1(x) cerr << #x << ": " << x << endl
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
const int N = 200005;

class Point
{
public:
  int x, y;


  Point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
};

class Interval
{
public:
  int bottom, top;

  Interval(int bottom, int top)
  {
    this->bottom = min(bottom, top);
    this->top = max(bottom, top);
  }
};

class LineSegment
{
public:
  Interval line;
  int coord;
};

class Rectangle
{
public:
  int x_left, x_right, y_bottom, y_top;

  Rectangle(int x_left, int x_right, int y_bottom, int y_top)
  {
    this->x_left = min(x_left, x_right);
    this->x_right = max(x_left, x_right);
    this->y_bottom = min(y_bottom, y_top);
    this->y_top = max(y_bottom, y_top);
  }

  Rectange(Interval xInterval, Interval yInterval)
  {
    this->x_left = xInterval.bottom;
    this->x_right = xInterval.top;
    this->y_bottom = yInterval.bottom;
    this->y_top = yInterval.top;
  }

  vector<Interval> getIntervals()
  {
    return vector<Interval>{Interval(x_left, x_right), Interval(y_bottom, y_top)};
  }
};

static const string LEFT = "left";
static const string RIGHT = "right";
static const string UP = "up";
static const string BOTTOM = "bottom";

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
  EdgeType side;
  Edge(Interval interval,int coord,EdgeType side)
  {
    this->interval = interval;
    this->coord = coord;
    this->side = side;
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

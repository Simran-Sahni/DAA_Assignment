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
private:
  int x;
  int y;

public:
  int getX() { return this->x; }
  void setX(int x) { this->x = x; }
  int getY() { return this->y; }
  void setY(int y) { this->y = y; }

  Point(int x, int y) : x(x),
                        y(y){};
};

class Interval
{
private:
  int bottom;
  int top;

public:
  int getBottom() { return this->bottom; }
  void setBottom(int bottom) { this->bottom = bottom; }
  int getTop() { return this->top; }
  void setTop(int top) { this->top = top; }

  Interval(int bottom, int top) : bottom(bottom),
                                  top(top){};
};

class LineSegment
{
private:
  Interval line;
  int coordinate;

public:
  Interval getLine() { return this->line; }
  void setLine(Interval line) { this->line = line; }
  int getCoordinate() { return this->coordinate; }
  void setCoordinate(int coordinate) { this->coordinate = coordinate; }
  LineSegment(Interval line, int coordinate) : line(line),
                                               coordinate(coordinate){};
};

class Rectangle
{
private:
  int x_left;
  int x_right;
  int y_bottom;
  int y_top;

  int getX_left() { return this->x_left; }
  void setX_left(int x_left) { this->x_left = x_left; }
  int getX_right() { return this->x_right; }
  void setX_right(int x_right) { this->x_right = x_right; }
  int getY_bottom() { return this->y_bottom; }
  void setY_bottom(int y_bottom) { this->y_bottom = y_bottom; }
  int getY_top() { return this->y_top; }
  void setY_top(int y_top) { this->y_top = y_top; }

public:
  Rectangle(int x_left, int x_right, int y_bottom, int y_top) : x_left(x_left),
                                                                x_right(x_right),
                                                                y_bottom(y_bottom),
                                                                y_top(y_top){};

  Rectangle(Interval xInterval, Interval yInterval) : x_left(xInterval.getBottom()),
                                                      x_right(xInterval.getTop()),
                                                      y_bottom(yInterval.getBottom()),
                                                      y_top(yInterval.getTop()){};

  vector<Interval> getIntervals(){return vector<Interval>{Interval(x_left, x_right), 
  Interval(y_bottom, y_top)};}
};

static const string LEFT = "left";
static const string RIGHT = "right";
static const string UP = "up";
static const string BOTTOM = "bottom";

class EdgeType
{
public:
  string type;

  string getType() { return this->type; }
  void setType(string type) { this->type = type; }

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

  Interval getInterval() { return this->interval; }
  void setInterval(Interval interval) { this->interval = interval; }
  int getCoord() { return this->coord; }
  void setCoord(int coord) { this->coord = coord; }
  EdgeType getSideType() { return this->sideType; }
  void setSideType(EdgeType sideType) { this->sideType = sideType; }

  Edge(Interval interval, int coord, EdgeType sideType) : interval(interval),
                                                          coord(coord),
                                                          sideType(sideType){};
};

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  IOS

      Point p1(1, 2);
  cout << p1.getX() << endl;

  return 0;
}

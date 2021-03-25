//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/MeasureHelper.h"
#include "../include/IntervalHelper.h"
#include <algorithm>
#include <map>
#include <fstream>
using std ::map;
using std ::max;
using std ::min;
using std:: ofstream;
using namespace std;
#include <bits/stdc++.h>

/**
 *
 * @param coordinates
 * @return
 */
vector<Interval> MeasureHelper ::partition(vector<int> &coordinates) {
  vector<Interval> ans;
  for (int i = 1; i < coordinates.size(); i++) {
    Interval new_interval(coordinates[i], coordinates[i - 1]);
    ans.push_back(new_interval);
  }
  return ans;
}

/**
 * Returns the extended set of stripes from both sides
 * @param S set of Stripes
 * @param coord_P y-projections of all segments in V
 * @param x_interval
 * @return set of stripes extended
 */
vector<Stripe> MeasureHelper ::copy(vector<Stripe> S, vector<int> coord_P,
                                    Interval x_interval) {
  vector<Stripe> ans;
  vector<Interval> partition_P = partition(coord_P);

  for (auto y_interval : partition_P) {
    Stripe new_stripe(x_interval, y_interval, 0);
    ans.push_back(new_stripe);
  }

  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < ans.size(); j++) {
      if (IntervalHelper ::is_subset_of(ans[j].y_interval, S[i].y_interval)) {
        ans[j].setXMeasure(S[i].x_measure);
        ans[j].tree = S[i].tree;
      }
    }
  }

  return ans;
}

/**
 * Every two adjacent stripes in S-left and S-right, with the same y-interval
 * are concatenated
 * @param s1 Left set of stripes
 * @param s2 Right set of stripes
 * @param coord_P y-projections of all segments in V
 * @param x_interval
 * @return set of concatenated stripes
 */
vector<Stripe> MeasureHelper::concat(vector<Stripe> &s1, vector<Stripe> &s2,
                                     vector<int> &coord_P,
                                     Interval x_interval) {
  vector<Stripe> ans;
  vector<Interval> partition_P = partition(coord_P);

  for (auto &y_interval : partition_P) {
    Stripe new_stripe(x_interval, y_interval, 0);
    ans.push_back(new_stripe);
  }
  for (int i = 0; i < s1.size(); i++) {
    ans[i].setXMeasure(s1[i].x_measure + s2[i].x_measure);
    if (s1[i].tree != s2[i].tree and s1[i].tree != nullptr) {
      ans[i].tree =
          new Ctree(s1[i].x_interval.top, UNDEFINED, s1[i].tree, s2[i].tree);
      ans[i].tree->leftson = s1[i].tree;
      ans[i].tree->rightson = s2[i].tree;
    } else if (s2[i].tree == nullptr) {
      ans[i].tree = s1[i].tree;
    } else if (s1[i].tree == nullptr) {
      ans[i].tree = s2[i].tree;
    } else {
      ans[i].tree = nullptr;
    }
  }
  return ans;
}

/**
 * Update the x_union coverage of the set of stripes who have y_interval covered
 * in set of intervals
 * @param S set of stripes
 * @param J set of Y_intervals/edges
 */
void MeasureHelper::blacken(vector<Stripe> &S, vector<Edge> &J) {

  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < J.size(); j++) {
      if (IntervalHelper ::is_subset_of(S[i].y_interval, J[j].interval)) {
        S[i].setXMeasure(S[i].x_interval.top - S[i].x_interval.bottom);
        S[i].tree = nullptr;
      }
    }
  }
}

/**
 * function to return the Stripes in the format expected by STRIPES algorithm
 * @param V vector of edges
 * @param x_ext set of x intervals
 * @return StripeOutput object
 */
StripeOutput MeasureHelper::stripes(vector<Edge> V, Interval x_ext) {
//    cout<<"Call to stripes with params "<<x_ext.bottom<<" "<<x_ext.top<<" size of V as "<<V.size()<<"\n";
  vector<Edge> L;
  vector<Edge> R;
  vector<int> coord_P;
  vector<Stripe> S;
  if (V.size() == 1) {
    Edge v = V[0];
    if (v.type == LEFT) {

      L.push_back(v);
      R.clear();
    } else {
      L.clear();
      R.push_back(v);
    }
    coord_P = {-INF, v.interval.bottom, v.interval.top, INF};
    vector<Interval> partition_P = partition(coord_P);
    for (auto &interval : partition_P) {
      Stripe new_stripe(x_ext, interval, 0, nullptr);
      S.push_back(new_stripe);
    }

    for (auto &stripe : S) {
      if (v.interval == stripe.y_interval) {
        if (v.type == LEFT) {
          stripe.setXMeasure(x_ext.top - v.coord);
          stripe.tree = new Ctree(v.coord, LEFT);
        } else {
          stripe.setXMeasure(v.coord - x_ext.bottom);
          stripe.tree = new Ctree(v.coord, RIGHT);
        }
      }
    }
    StripeOutput ans;
    ans.S = S;
    ans.L = L;
    ans.R = R;
    ans.coord_p = coord_P;
//    ans.print();
    //cout<<"Size of returned StripeOutput L and R is "<<ans.L.size()<<" "<<ans.R.size()<<"\n";
    return ans;

  } else {
    vector<Edge> V1;
    vector<Edge> V2;
    sort(V.begin(), V.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.coord < rhs.coord;
    });
    int m = V.size() / 2;
    for (int i = 0; i < V.size(); i++) {
      if (i < m)
        V1.push_back(V[i]);
      else
        V2.push_back(V[i]);
    }

    double xm = (V1.back().coord + V2.front().coord) / 2.0;
    Interval left_interval(x_ext.bottom, xm);
    Interval right_interval(xm, x_ext.top);

    StripeOutput left = stripes(V1, left_interval);

    StripeOutput right = stripes(V2, right_interval);

    vector<Edge> L1_compliment_LR;
    for (Edge e : left.L) {
      if (e.partner_coordinate > x_ext.top) {
        L1_compliment_LR.push_back(e);
      }
    }
    vector<Edge> R2_compliment_LR;
    for (Edge e : right.R) {
      if (e.partner_coordinate <= x_ext.bottom) {
        R2_compliment_LR.push_back(e);
      }
    }
    vector<Edge> L(L1_compliment_LR.begin(), L1_compliment_LR.end());
    vector<Edge> R(left.R.begin(), left.R.end());
    for (auto e : right.L) {
      L.push_back(e);
    }
    for (auto e : R2_compliment_LR) {
      R.push_back(e);
    }
    StripeOutput ans;
    ans.L = L;
    ans.R = R;
    ans.coord_p = IntervalHelper ::find_union(left.coord_p, right.coord_p);
    vector<Stripe> S_left = copy(left.S, ans.coord_p, left_interval);
    vector<Stripe> S_right = copy(right.S, ans.coord_p, right_interval);
    blacken(S_left, R2_compliment_LR);
    blacken(S_right, L1_compliment_LR);
    ans.S = concat(S_left, S_right, ans.coord_p, x_ext);
    return ans;
  }
}

/**
 * Most important RECTANGLE_DAC subroutine, crux of the algorithm
 * @param r set of Rectangles
 * @return double value: measure, that is the extent of union of these
 * rectangles
 */
long double MeasureHelper::rectangle_dac(vector<Rectangle> r,ofstream &text,ofstream &image,ofstream &image_input) {

  vector<Edge> vrx, hrx;
  //cerr << r.size() << endl;

  for (auto &rectangle : r) {
    for (auto edge : rectangle.getVerticalEdges()) {
      vrx.push_back(edge);
    }
    for (auto edge : rectangle.getHorizontalEdges()) {
      hrx.push_back(edge);
    }
  }
  sort(vrx.begin(), vrx.end(),
       [](const auto &lhs, const auto &rhs) { return lhs.coord < rhs.coord; });
  sort(hrx.begin(), hrx.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.coord == rhs.coord) {
      if (lhs.interval.bottom != rhs.interval.bottom)
        return lhs.interval.bottom < rhs.interval.bottom;
      if (lhs.interval.top != rhs.interval.top)
        return lhs.interval.top < rhs.interval.top;
      if (lhs.type == BOTTOM)
        return false;
      if (rhs.type == BOTTOM)
        return false;
      return true;
    }

    return lhs.coord < rhs.coord;
  });

  //Printing horizontal & vertical intervals after sorting

  cout << "Edges in the Rectangle are" << endl;
  text << "Edges in the Rectangle are" << endl;
  for (auto &i : hrx) {
    cout << i.interval.bottom << " " << i.coord << " " << i.interval.top << " "
         << i.coord << " " << 0 << endl;
    text << i.interval.bottom << " " << i.coord << " " << i.interval.top << " "
          << i.coord << " " << endl;
    image_input << i.interval.bottom << " " << i.coord << " " << i.interval.top << " "
         << i.coord << " " << 0 << endl;
  }

  for (auto &i : vrx) {
    cout << i.coord << " " << i.interval.bottom << " " << i.coord << " "
         << i.interval.top << " " << 0 << endl;
    text << i.coord << " " << i.interval.bottom << " " << i.coord << " "
          << i.interval.top << " " << endl;
    image_input << i.coord << " " << i.interval.bottom << " " << i.coord << " "
         << i.interval.top << " " << 0 << endl;
  }

  if (vrx.empty())
    return 0.0;
  StripeOutput ans = stripes(vrx, Interval(-INF, INF));
  long double measure = 0;

  for (auto &stripe : ans.S) {
    vector<long double> v;
    v.push_back(-INF);
    //need for inorder here?
    inorder(stripe.tree, v);
    v.push_back(INF);
    stripe.setV(v);
    measure +=
        stripe.x_measure * (stripe.y_interval.top - stripe.y_interval.bottom);
  }
  text << endl;
  int perimeter = 0;

  vector<vector<int>> contour = getContourEdges(ans.S, hrx,perimeter);




  text << "Measure is " << setprecision(15) << measure << endl;
  image << "Measure is " << setprecision(15) << measure << endl;
  text << "Perimeter is " << perimeter << endl;
  image << "Perimeter is " << perimeter << endl;




  for (auto &i : hrx) {
    image << i.interval.bottom << " " << i.coord << " " << i.interval.top << " "
                << i.coord << " " << 0 << endl;
  }

  for (auto &i : vrx) {
    image << i.coord << " " << i.interval.bottom << " " << i.coord << " "
                << i.interval.top << " " << 0 << endl;
  }

  cout << "Contour Edges are " << endl;
  text << endl;

  text << "Contour Edges are " << endl;
  for (auto &i : contour) {
    for (auto &j : i) {
      cout << j << " ";
      text << j << " ";
      image << j << " ";
    }
    cout << 1 << endl;
    image << 1 << endl;
    text << endl;
  }

  text << endl;

  return measure;
}
/**
 *
 * @param root
 * @param v1
 */
void MeasureHelper::inorder(Ctree *root, vector<long double> &v1) {
  if (!root)
    return;
  inorder(root->leftson, v1);
  if (!root->leftson and !root->rightson)
    v1.push_back(root->x);
  inorder(root->rightson, v1);
}
/**
 *
 * @param leaf
 * @param hrx
 * @param ycoord
 * @param flag
 * @param ans
 * @return
 */
vector<vector<int>> MeasureHelper::freeIntervalQuery(vector<long double> leaf,
                                                     Interval hrx, int ycoord,
                                                     bool flag,
                                                     vector<vector<int>> &ans) {

  int idx = lower_bound(leaf.begin(), leaf.end(), hrx.bottom) - leaf.begin();
  if (idx % 2 == 1)
    idx--;

  for (int i = idx; i < leaf.size(); i += 2) {
    long double &curr = leaf[i];
    long double &nxt = leaf[i + 1];
    if (i % 2 == 0 and curr >= hrx.top)
      break;
    if (curr < nxt) {
      if (nxt < hrx.bottom or curr > hrx.top)
        continue;
      ans.push_back(
          {ycoord, max((int)curr, hrx.bottom), min((int)nxt, hrx.top), flag});
//      cerr << endl;
    }
  }
  return ans;
}
/**
 *
 * @param S
 * @param hrx
 * @return
 */
vector<vector<int>> MeasureHelper::getContourEdges(vector<Stripe> &S,
                                                   vector<Edge> &hrx,int &perimeter) {
    vector<vector<int>> contour;
    vector<vector<int>> ans;


//    for (auto s: S) {
//        s.print();
//    }

//    for (auto h: hrx)
//        h.print();
    for (auto &it : hrx) {
        for (auto &jt : S) {
            if (it.type == BOTTOM and jt.y_interval.top == it.coord) {
                freeIntervalQuery(jt.v, it.interval, it.coord, 0, ans);
            } else if (it.type == UP and jt.y_interval.bottom == it.coord) {
                freeIntervalQuery(jt.v, it.interval, it.coord, 1, ans);
            }
        }
    }

//    for (auto x: ans)
//    {       for (auto y: x)
//            cout << y << " ";
//    cout << "\n";
//   }


  map<int, vector<Interval>> mp;

  for (auto &v : ans) {
    mp[v[0]].push_back(Interval(v[1], v[2]));
  }

  for (auto &v : mp) {
    vector<Interval> v1;
    v.second = IntervalHelper ::find_union(v.second, v1);
    for (int i = 0; i < v.second.size(); i++) {
      contour.push_back(
          {v.second[i].bottom, v.first, v.second[i].top, v.first});
      perimeter += v.second[i].top - v.second[i].bottom;
    }
  }
  vector<vector<int>> ep;
  for (auto &v : mp) {
    for (auto &j : v.second) {
      ep.push_back({j.bottom, v.first});
      ep.push_back({j.top, v.first});
    }
  }

  sort(ep.begin(), ep.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs[0] == rhs[0])
      return lhs[1] < rhs[1];
    return lhs[0] < rhs[0];
  });

  for (int i = 0; i < ep.size() - 1; i++) {
    int cx = ep[i][0], cy = ep[i][1];
    int nx = ep[i + 1][0], ny = ep[i + 1][1];
    if (cx == nx) {
      if (cy != ny) {
        perimeter += ny - cy;
        contour.push_back({nx, cy, nx, ny});
        i++;
      }
    }
  }

  cout << "Perimeter is " << perimeter << endl;



  return contour;
}

//
// Created by Radhesh Sarma on 14-03-2021.
//

#include "../include/MeasureHelper.h"
#include "../include/IntervalHelper.h"
#include <algorithm>
using namespace std;


/**
 * Unites and returns set of all points in the set of rectangles
 * @param r set of rectangles
 * @return set of points
 */
vector<Point> MeasureHelper ::union_of_rectangle(vector<Rectangle> &r) {
  vector<Point> ans;

  for (auto &rectangle : r) {
    Point p1(rectangle.x_left, rectangle.y_top);
    Point p2(rectangle.x_left, rectangle.y_bottom);
    Point p3(rectangle.x_right, rectangle.y_top);
    Point p4(rectangle.x_right, rectangle.y_bottom);
    ans.push_back(p1);
    ans.push_back(p2);
    ans.push_back(p3);
    ans.push_back(p4);
  }
  return ans;
}

/**
 * Returns a set containing the y_co-ordinates of the set of rectangles
 * @param r Set of rectangles
 * @return vector of integer y-coordinates
 */
vector<int> MeasureHelper ::y_set(vector<Rectangle> &r) {
  vector<int> ans;
  for (auto &rectangle : r) {
    ans.push_back(rectangle.y_top);
    ans.push_back(rectangle.y_bottom);
  }
  return ans;
}


/**
 * returns a set of distinct Y-intervals from the set of Y_co-ordinates
 * @param coordinates set of Y-coordinates
 * @return set of Y-intervals
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

//  cerr << x_interval.bottom << " " << x_interval.top << endl;
//    for(auto &e: coord_P){
//      cerr << e << endl;
//    }


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
 * Every two adjacent stripes in S-left and S-right, with the same y-interval are concatenated
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
  for(int i = 0; i < s1.size(); i++){
    ans[i].setXMeasure(s1[i].x_measure + s2[i].x_measure);
    if(s1[i].tree != s2[i].tree and s1[i].tree != nullptr){
      ans[i].tree = new Ctree(s1[i].x_interval.top,UNDEFINED,s1[i].tree,s2[i].tree);
    }
    else if(s2[i].tree == nullptr){
      ans[i].tree = s1[i].tree;
    }
    else if(s1[i].tree == nullptr){
      ans[i].tree = s2[i].tree;
    }
    else{
      ans[i].tree = nullptr;
    }

  }
  return ans;
}


/**
 * Update the x_union coverage of the set of stripes who have y_interval covered in set of intervals
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
//
//    for(auto e : L){
//      cerr << e.coord << endl;
//    }
//    for(auto e : R){
//      cerr << e.coord << endl;
//    }
//    cerr << v.coord << " " << L.size() << " " << v.type << endl;

    coord_P = {-INF, v.interval.bottom, v.interval.top, INF};


    vector<Interval> partition_P = partition(coord_P);

//    for(auto e : partition_P){
//      cerr << e.bottom << " " << e.top << endl;
//    }


    for (auto &interval : partition_P) {
      Stripe new_stripe(x_ext, interval, 0,nullptr);
//      cerr << x_ext.bottom << " " << x_ext.top << " " << interval.bottom << " " << interval.top << endl;
      S.push_back(new_stripe);
    }



    for (auto &stripe : S) {
      if(v.interval == stripe.y_interval){
        if (v.type == LEFT) {
          stripe.setXMeasure(x_ext.top - v.coord);
          stripe.tree = new Ctree(v.coord,LEFT,nullptr,nullptr);
        } else {
          stripe.setXMeasure(v.coord - x_ext.bottom);
          stripe.tree = new Ctree(v.coord,RIGHT, nullptr, nullptr);
        }
      }

    }

    StripeOutput ans;
    ans.S = S;
    ans.L = L;
    ans.R = R;
    ans.coord_p = coord_P;
//    for(auto &stripe : S){
//      cerr <<  stripe.y_interval.bottom << " " << stripe.y_interval.top << " " << stripe.x_measure << endl;
//    }
  return ans;
//    cerr << endl;
//


  } else {
    vector<Edge> V1;
    vector<Edge> V2;
    sort(V.begin(), V.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.coord < rhs.coord;
    });
    int m = V.size() / 2;
//    cerr << "m is " << m << endl;
    for (int i = 0; i < V.size(); i++) {
      if (i < m)
        V1.push_back(V[i]);
      else
        V2.push_back(V[i]);
    }
//    for(auto e : V1){
//      cerr << e.coord << endl;
//    }
//    for(auto e : V2){
//      cerr << e.coord << endl;
//    }

//    int xm = V[xm];

    double xm = (V1.back().coord + V2.front().coord) /2.0;
    Interval left_interval(x_ext.bottom, xm);
    Interval right_interval(xm, x_ext.top);

//    cerr << left_interval.top << " " << left_interval.bottom << endl;
//    cerr << right_interval.top << " " << right_interval.bottom << endl;

//  cerr << V1.size() << endl;

    StripeOutput left = stripes(V1, left_interval);

    StripeOutput right = stripes(V2, right_interval);

//    StripeOutput ans1;
//    return ans1;


    vector<Edge> L1_compliment_LR;
    for(Edge e : left.L){
      if(e.partner_coordinate > x_ext.top){
        L1_compliment_LR.push_back(e);
      }
    }



    vector<Edge> R2_compliment_LR;
    for(Edge e: right.R){
      if(e.partner_coordinate <= x_ext.bottom){
        R2_compliment_LR.push_back(e);
      }
    }

    vector<Edge> L(L1_compliment_LR.begin(),L1_compliment_LR.end());
    vector<Edge> R(left.R.begin(),left.R.end());

    for(auto e : right.L){
      L.push_back(e);
    }

    for(auto e : R2_compliment_LR){
      R.push_back(e);
    }


    StripeOutput ans;
    ans.L = L;
    ans.R = R;


    ans.coord_p = IntervalHelper ::find_union(left.coord_p, right.coord_p);

//    for(auto e : ans.L){
//      cerr << e.coord << endl;
//    }
//    cerr << right.L.size() << endl;

//    for(auto e : ans.R){
//      cerr << e.coord << endl;
//    }



//    cerr << x_ext.bottom << " " << x_ext.top << " " << xm << endl;
//
//    cerr << R2_compliment_LR.size() << " " << L1_compliment_LR.size() << endl;
//    for(auto &e : R2_compliment_LR){
//      cerr  << e.coord << endl;
//    }
//    for (auto &stripe : left.S) {
//      cerr <<  stripe.x_interval.bottom << " " << stripe.x_interval.top << " " << stripe.y_interval.bottom << " " << stripe.y_interval.top << " " << stripe.x_measure << endl;
//    }
//    cerr << endl << endl;
//    for (auto &stripe : right.S) {
//      cerr <<  stripe.x_interval.bottom << " " << stripe.x_interval.top << " " << stripe.y_interval.bottom << " " << stripe.y_interval.top << " " << stripe.x_measure << endl;
//    }
//
//    cerr << "Before Copy" << endl;

    vector<Stripe> S_left = copy(left.S, ans.coord_p, left_interval);


//    cerr << endl << endl;
    vector<Stripe> S_right = copy(right.S, ans.coord_p, right_interval);
//
//    cerr << "After Copy" << endl;
//    for (auto &stripe : S_left) {
//      cerr <<  stripe.x_interval.bottom << " " << stripe.x_interval.top << " " << stripe.y_interval.bottom << " " << stripe.y_interval.top << " " << stripe.x_measure << endl;
//    }
//    cerr << endl << endl;
//    for (auto &stripe : S_right) {
//      cerr <<  stripe.x_interval.bottom << " " << stripe.x_interval.top << " " << stripe.y_interval.bottom << " " << stripe.y_interval.top << " " << stripe.x_measure << endl;
//    }
//    cerr << endl << endl;
    blacken(S_left, R2_compliment_LR);
    blacken(S_right, L1_compliment_LR);
    ans.S = concat(S_left, S_right, ans.coord_p, x_ext);
//    cerr << endl;
//    cerr << "Radhesh" << " " << ans.S.size() << endl;
//    for (auto &stripe : ans.S) {
//      cerr <<  stripe.y_interval.bottom << " " << stripe.y_interval.top << " " << stripe.x_measure << endl;
//    }
//    cerr << endl;
    return ans;
  }
}

/**
 * Most important RECTANGLE_DAC subroutine, crux of the algorithm
 * @param r set of Rectangles
 * @return double value: measure, that is the extent of union of these rectangles
 */
long double MeasureHelper::rectangle_dac(vector<Rectangle> r) {
  vector<Edge> vrx;
  for (auto &rectangle : r) {
    for (auto &edge : rectangle.getVerticalEdges()) {
      vrx.push_back(edge);
    }
  }
  if(vrx.empty())return 0.0;

//  for(auto e : vrx){
//    cerr << e.coord << endl;
//    cerr << e.type << endl;
//  }

  StripeOutput ans = stripes(vrx, Interval(-INF, INF));
//  StripeOutput ans;
  long double measure = 0;

  for (auto &stripe : ans.S) {
  //  cerr <<  stripe.x_interval.top << " " << stripe.x_interval.bottom << " " <<  stripe.y_interval.bottom << " " << stripe.y_interval.top << " " << stripe.x_measure << endl;

    measure +=
        stripe.x_measure * (stripe.y_interval.top - stripe.y_interval.bottom);
  }
  return measure;
}

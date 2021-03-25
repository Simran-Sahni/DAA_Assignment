#include <bits/stdc++.h>
#include "include/Rectangle.h"
#include "include/MeasureHelper.h"
#include <fstream>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif



  int testcases;
  cin >> testcases;

  cout << testcases << endl;;


  int tc = 1;

  while(testcases--)
  {


    vector<Rectangle> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int x, y, z, w;
      cin >> x >> y >> z >> w;
      if (x > y)
        swap(x, y);
      if (z > w)
        swap(z, w);
      v.push_back(Rectangle(x, y, z, w));
    }
    cout << "TestCase " << tc << endl;

    string text_output_file = "output" + to_string(tc) + ".txt";


    string plotting_input_file = "input-plot" + to_string(tc) + ".txt";
    string plotting_output_file = "output-plot" + to_string(tc) + ".txt";
    ofstream text(text_output_file);
    ofstream image(plotting_output_file);
    ofstream image_input(plotting_input_file);


  long double ans = MeasureHelper ::rectangle_dac(v,text,image,image_input);

    cout << "Measure is " << std ::setprecision(15) << ans << endl;

    text.close();
    image.close();

    cout << endl;
    tc++;

  }


    return 0;
}

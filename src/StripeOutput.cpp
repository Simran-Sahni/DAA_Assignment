//
// Created by Radhesh Sarma on 15-03-2021.
//

#include "../include/StripeOutput.h"
#include<bits/stdc++.h>
using namespace std;
/**
 *
 */
StripeOutput::StripeOutput() {}

void StripeOutput::print() {
    cout << "L: " << L.size() << "\n";
    for (auto i: L)
        cout << "Interval is: " << i.interval.bottom << " " << i.interval.top << " " << i.type << " co-ord: " << i.coord
             << " " << i.partner_coordinate << "\n";
    cout << "R: " << R.size() << "\n";
    for (auto i: R)
        cout << "Interval is: " << i.interval.bottom << " " << i.interval.top << " " << i.type << " co-ord: " << i.coord
             << " " << i.partner_coordinate << "\n";
    cout << "coord_P: " << coord_p.size()<<"\n";
    for (auto i: coord_p)
        cout << i << " ";
    cout << "\n";
    cout << "Size of Set of stripes S :"<<S.size()<<"\n";
    for (auto str:S)
        str.print();
}


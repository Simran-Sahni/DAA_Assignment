//
// Created by Radhesh Sarma on 16-03-2021.
//

#include "../include/Ctree.h"
Ctree::Ctree(long double x, const string &lru, Ctree *leftson, Ctree *rightson)
    : x(x), lru(lru), leftson(leftson), rightson(rightson) {}
Ctree::Ctree() {}
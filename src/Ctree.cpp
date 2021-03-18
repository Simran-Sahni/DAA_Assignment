//
// Created by Radhesh Sarma on 16-03-2021.
//

#include "../include/Ctree.h"
/**
 *
 * @param x
 * @param lru
 * @param leftson
 * @param rightson
 */
Ctree::Ctree(long double x, string lru, Ctree *leftson, Ctree *rightson)
    : x(x), lru(lru), leftson(leftson), rightson(rightson) {}
/**
 *
 * @param x
 * @param lru
 */
Ctree::Ctree(long double x, string lru)
    : x(x), lru(lru), leftson(nullptr), rightson(nullptr) {}
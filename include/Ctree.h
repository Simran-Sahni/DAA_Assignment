//
// Created by Radhesh Sarma on 16-03-2021.
//

#ifndef DAA_ASSIGNMENT_CTREE_H
#define DAA_ASSIGNMENT_CTREE_H
#include <string>
using std :: string;

//static const char LEFT[] = "LEFT";
//static const char RIGHT[] = "RIGHT";
//static const char UNDEFINED[] = "UNDEFINED";
class Ctree {
public:
  long double x{};
  string lru;
 Ctree *leftson{};
 Ctree *rightson{};
 Ctree();
 Ctree(long double x, const string &lru, Ctree *leftson, Ctree *rightson);
};

#endif // DAA_ASSIGNMENT_CTREE_H

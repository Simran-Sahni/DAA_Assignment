//
// Created by Radhesh Sarma on 14-03-2021.
//

#ifndef DAA_ASSIGNMENT_EDGETYPE_H
#define DAA_ASSIGNMENT_EDGETYPE_H

#include <string>
using std ::string;
static const char LEFT[] = "LEFT";
static const char RIGHT[] = "RIGHT";
static const char UP[] = "UP";
static const char BOTTOM[] = "BOTTOM";
class EdgeType {
public:
  string type;

  explicit EdgeType(string type);
};

#endif // DAA_ASSIGNMENT_EDGETYPE_H

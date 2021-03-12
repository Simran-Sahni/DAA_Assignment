#include <iostream>
#include <iomanip>
#include "EdgeType.h"
using std:: runtime_error;

  EdgeType :: EdgeType(string type) {
    if (type == LEFT || type == RIGHT || type == UP || type == BOTTOM)
      this->type = type;
    else
      throw runtime_error("Not a valid edge type!");
  }

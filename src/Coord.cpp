#include "Coord.h"

#include <iostream>

bool operator==(Coord a, Coord b) {
  return a.row == b.row && a.col == b.col;
}

std::ostream &operator<<(std::ostream &os, Coord c) {
  return os << "(" << c.row << "," << c.col << ")";
}

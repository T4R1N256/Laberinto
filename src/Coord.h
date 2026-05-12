#ifndef COORD_H
#define COORD_H

#include <ostream>

struct Coord {
  int row;
  int col;
};

inline bool operator==(Coord a, Coord b) {
  return a.row == b.row && a.col == b.col;
}

inline std::ostream &operator<<(std::ostream &os, Coord c) {
  return os << "(" << c.row << "," << c.col << ")";
}

#endif

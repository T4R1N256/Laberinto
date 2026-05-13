#ifndef COORD_H
#define COORD_H

#include <iostream>

struct Coord {
  int row;
  int col;
};

bool operator==(Coord a, Coord b);
std::ostream &operator<<(std::ostream &os, Coord c);

#endif
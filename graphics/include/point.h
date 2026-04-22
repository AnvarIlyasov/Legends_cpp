#pragma once

struct Point {
  double x, y;
  Point(double x = 0, double y = 0);

  bool operator<(const Point& other) const;
  bool operator>(const Point& other) const;
};
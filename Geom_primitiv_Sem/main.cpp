#include <cmath>
#include <iostream>
#include <tuple>
class Point {
private:
  int x;

  int y;

public:
  Point(int x_value, int y_value) {
    x = x_value;
    y = y_value;
  }

  int getX() { return x; }

  int getY() { return y; }

  double distanceToOrigin() { return std::sqrt(x * x + y * y); }

  Point() {
    x = 0;
    y = 0;
  }

  bool operator<(const Point &value) {
    return std::tie(x, y) < std::tie(value.x, value.y);
  }
};

class SafeVector {
private:
  Point *data;
  int size;
  int capacity;

public:
  SafeVector() {
    size = 0;
    capacity = 2;
    data = new Point[capacity];
  }

  ~SafeVector() { delete[] data; }

  void push_back(Point value) {
    if (size == capacity) {
      capacity = capacity * 2;
      Point *newData = new Point[capacity];

      for (int i = 0; i < size; i++) {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
    }
    data[size] = value;
    size++;
  }
  Point &operator[](int index) { return data[index]; }

  void sort() {
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - 1 - i; j++) {
        if (data[j + 1] < data[j]) {
          Point temp = data[j];
          data[j] = data[j + 1];
          data[j + 1] = temp;
        }
      }
    }
  }
};
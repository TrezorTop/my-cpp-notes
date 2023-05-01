#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H

namespace point {

  class Point {
    public:
      double getX() const;
      double getY() const;
      void setX(double x);
      void setY(double y);

    private:
      double x;
      double y;
  };

}  // namespace point

#endif  // UNTITLED_POINT_H

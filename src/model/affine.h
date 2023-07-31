#ifndef SRC_MODEL_AFFINE_H_
#define SRC_MODEL_AFFINE_H_

#include "../helpers/data_objects.h"

namespace s21 {

class BaseMovement {
 public:
  virtual BaseMovement() = default;
  virtual ~BaseMovement() = default;
  virtual void Execute(const TransformParams &tp, const GLObject object) = 0;

};

class Move : public BaseMovement {
 public:
  void Execute(const TransformParams &tp, const GLObject object) override {

    }
  }
  ~Move() override {};
};

class Rotate : public BaseMovement {
 public:
  void Execute(const TransformParams &tp, const GLObject &object) override {
    size_t i_def{}, incr_1{}, incr_2{};
    if (tp.axis == 'x') {
      i_def = 0, incr_1 = 1, incr_2 = 2;
    } else if (tp.axis == 'y') {
      i_def = 1, incr_1 = -1, incr_2 = 1;
    } else if (tp.axis == 'z') {
      i_def = 2, incr_1 = -2, incr_2 = -1;
    }

    size_t max_size = object.vetices.size() + i_def - 2;
    size_t i = i_def, axis_1{}, axis_2{};
    double vert_1{}, vert_2{};
    for (size_t i = i_def; i < max_size; i += 3) {
      axis_1 = i + incr_1;
      axis_2 = i + incr_2;
      vert_1 = object.vertices[axis_1];
      vert_2 = object.vertices[axis_2];
      
      object.vertices[axis_1] = cos(tp.value) * vert_1 - sin(tp.value) * vert_2;
      object.vertices[axis_2] = cos(tp.value) * vert_2 + sin(tp.value) * vert_1;
    }
  ~Rotate() override {};
};

class Scale : public BaseMovement {
 public:
  void Execute(const TransformParams &tp, const GLObject object) override {

  }
  ~Scale() override {};
};

class AffineTransforms {
 public:
  Strategy() : current(new Move) {};
  void SetStrategy(BaseMovement *c) {
    delete current;
    current = c;
  }
  ~Strategy() {
    delete current;
  }

  void Execute(float x, float y, float z) {
    current->Execute(x, y, z);
  }
 private:
  BaseMovement *current = nullptr;
};

int main() {
  Strategy s;
  s.Execute(0, 0, 0);
  s.SetStrategy(new Scale);
  s.Execute(0, 0, 0);
  s.SetStrategy(new Rotate);
  s.Execute(0, 0, 0);
}

} // namespace s21


#endif  // SRC_MODEL_AFFINE_H_
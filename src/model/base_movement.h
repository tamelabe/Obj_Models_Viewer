#ifndef SRC_MODEL_BASE_MOVEMENT_H_
#define SRC_MODEL_BASE_MOVEMENT_H_

#include "../helpers/data_objects.h"
#include <cmath>
#include <iostream>

namespace s21 {

class BaseMovement {
 public:
  BaseMovement() = default;
  virtual ~BaseMovement() = default;
  virtual void Execute(const TransformParams &tp, GLObject &object) = 0;
};

class Move : public BaseMovement {
 public:
  ~Move() override {};

  void Execute(const TransformParams &tp, GLObject &object) override {
    size_t i_def{};
    if (tp.axis == 'x') {
      i_def = 0;
    } else if (tp.axis == 'y') {
      i_def = 1;
    } else if (tp.axis == 'z') {
      i_def = 2;
    }
    size_t max_size = object.vertices.size() - 2 + i_def;
    double value = tp.value / 50.0;
    for (size_t i = i_def; i < max_size; i += 3) {
      object.vertices[i] += value;
    }
  }
};

class Rotate : public BaseMovement {
 public:
  ~Rotate() override{};

  void Execute(const TransformParams &tp, GLObject &object) override {
    size_t i_def{}, incr_1{}, incr_2{};
    if (tp.axis == 'x') {
      i_def = 0, incr_1 = 1, incr_2 = 2;
    } else if (tp.axis == 'y') {
      i_def = 1, incr_1 = -1, incr_2 = 1;
    } else if (tp.axis == 'z') {
      i_def = 2, incr_1 = -2, incr_2 = -1;
    }

    size_t max_size = object.vertices.size() + i_def - 2;
    size_t axis_1{}, axis_2{};
    double value  = tp.value * 3.141592653589 / 180;
    double vert_1{}, vert_2{};
    for (size_t i = i_def; i < max_size; i += 3) {
      axis_1 = i + incr_1;
      axis_2 = i + incr_2;
      vert_1 = object.vertices[axis_1];
      vert_2 = object.vertices[axis_2];

      object.vertices[axis_1] = std::cos(value) * vert_1 - std::sin(value) * vert_2;
      object.vertices[axis_2] = std::cos(value) * vert_2 + std::sin(value) * vert_1;
    }
  }
};

class Scale : public BaseMovement {
 public:
  ~Scale() override {};

  void Execute(const TransformParams &tp, GLObject &object) override {
    double scale = 1.0 + tp.value / 100.0;
    std::cout << "BEFORE:" << object.vertices[0] << '\n';
    for (size_t i = 0; i < object.vertices.size(); ++i) {
      object.vertices[i] *= scale;
    }
  }
};

} // namespace s21


#endif // SRC_MODEL_BASE_MOVEMENT_H_

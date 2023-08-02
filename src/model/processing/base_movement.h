#ifndef SRC_MODEL_BASE_MOVEMENT_H_
#define SRC_MODEL_BASE_MOVEMENT_H_

#include "../../helpers/data_objects.h"
#include <cmath>

namespace s21 {

class BaseMovement {
 public:
  BaseMovement() = default;
  virtual ~BaseMovement() = default;
  virtual void execute(const TransformParams &tp, GLObject &object) = 0;
};

class Move : public BaseMovement {
 public:
  Move() = default;
  ~Move() override {};
  void execute(const TransformParams &tp, GLObject &object) override;
};

class Rotate : public BaseMovement {
 public:
  Rotate() = default;
  ~Rotate() override{};
  void execute(const TransformParams &tp, GLObject &object) override;
};

class Scale : public BaseMovement {
 public:
  Scale() = default;
  ~Scale() override {};
  void execute(const TransformParams &tp, GLObject &object) override;
};

} // namespace s21


#endif // SRC_MODEL_BASE_MOVEMENT_H_

#ifndef SRC_MODEL_AFFINE_H_
#define SRC_MODEL_AFFINE_H_

#include "base_movement.h"
//#include "../helpers/data_objects.h"

namespace s21 {

class AffineTransforms {
 public:
  AffineTransforms() : current(new Move) {};
  void setStrategy(BaseMovement *c) {
    delete current;
    current = c;
  }
  ~AffineTransforms() { delete current; }

  void Execute(const TransformParams &tp, GLObject &object) {
    current->Execute(tp, object);
  }

 private:
  BaseMovement *current = nullptr;
};

} // namespace s21


#endif  // SRC_MODEL_AFFINE_H_
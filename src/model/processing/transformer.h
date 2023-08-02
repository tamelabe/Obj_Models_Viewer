#ifndef SRC_MODEL_TRANSFORMER_H_
#define SRC_MODEL_TRANSFORMER_H_

#include "base_movement.h"

namespace s21 {

class Transformer {
 public:
  Transformer() : current(new Move) {};
  void setStrategy(BaseMovement *c) {
    delete current;
    current = c;
  }
  ~Transformer() { delete current; }

  void Execute(const TransformParams &tp, GLObject &object) {
    current->Execute(tp, object);
  }

 private:
  BaseMovement *current = nullptr;
};

} // namespace s21

#endif  // SRC_MODEL_TRANSFORMER_H_
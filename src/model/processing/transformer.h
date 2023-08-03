#ifndef SRC_MODEL_TRANSFORMER_H_
#define SRC_MODEL_TRANSFORMER_H_

#include "base_movement.h"

namespace s21 {

class Transformer {
 public:
  Transformer() : current_(new Move) {};
  void setStrategy(BaseMovement *c) {
    delete current_;
    current_ = c;
  }
  ~Transformer() { delete current_; }
  Transformer(const Transformer&) = delete;
  Transformer(Transformer&&) = delete;
  Transformer& operator=(const Transformer&) = delete;
  Transformer& operator=(Transformer&&) = delete;

  void execute(const TransformParams &tp, GLObject &object) {
    current_->execute(tp, object);
  }

 private:
  BaseMovement *current_ = nullptr;
};

} // namespace s21

#endif  // SRC_MODEL_TRANSFORMER_H_
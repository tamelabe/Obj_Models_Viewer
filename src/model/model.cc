#include "model.h"

namespace s21 {

Model &Model::getInstance() {
  static Model model;
  return model;
}

void Model::setFilepath(const std::string &filepath) {
  object_.filepath = filepath;
  parser_.setObjectRef(object_);
  parser_.parseFile();
  normalizer_.setObjectRef(object_);
  normalizer_.normalize();
}

void Model::changeObjState(const TransformParams &tp) {
  if (tp.pos_type == 'm') {
    transform_.setStrategy(new Move);
  } else if (tp.pos_type == 'r') {
    transform_.setStrategy(new Rotate);
  } else if (tp.pos_type == 's') {
    transform_.setStrategy(new Scale);
  }
  transform_.execute(tp, object_);
}

}  // namespace s21

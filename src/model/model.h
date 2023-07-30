#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include "parser.h"
#include "../helpers/data_objects.h"

namespace s21 {

class Model {
 public:

  static Model& getInstance() {
    static Model model;
    return model;
  }

  void setFilepath(const std::string& filepath) {
    parser_.setFilepath(filepath);
    parser_.parseFile();
    object_.vertices = parser_.getVertices();
    object_.facets = parser_.getFacets();
  }

  GLObject getObject() { return object_; }

 private:
  Model() = default;
  Model(const Model&) = delete;
  Model(Model&&) = delete;
  ~Model() = default;
  Model& operator=(const Model&) = delete;
  Model& operator=(Model&&) = delete;

  Parser& parser_ = Parser::getInstance();
  GLObject object_{};
};

} // namespace s21

#endif //  SRC_MODEL_MODEL_H_

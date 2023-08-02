#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include "parser.h"
#include "affine.h"
//#include "../helpers/data_objects.h"


namespace s21 {

class Model {
 public:

  static Model& getInstance() {
    static Model model;
    return model;
  }

  GLObject getObject() {
    std::cout << "AFTER:" << object_.vertices[0] << '\n';
    return object_; }

  void setFilepath(const std::string& filepath) {
    parser_.setFilepath(filepath);
    parser_.parseFile();
    object_.vertices = parser_.getVertices();
    object_.facets = parser_.getFacets();
    normalizer_.setObject(object_);
    normalizer_.normalize();
    object_ = normalizer_.getObject();
  }

  void changeObjState(const TransformParams &tp) {
    AffineTransforms transform;
    if (tp.pos_type == 'm') {
      transform.setStrategy(new Move);
    } else if (tp.pos_type == 'r') {
      transform.setStrategy(new Rotate);
    } else if (tp.pos_type == 's') {
      transform.setStrategy(new Scale);
    }
    transform.Execute(tp, object_);
  }

 private:
  Model() = default;
  Model(const Model&) = delete;
  Model(Model&&) = delete;
  ~Model() = default;
  Model& operator=(const Model&) = delete;
  Model& operator=(Model&&) = delete;

  Parser& parser_ = Parser::getInstance();
  Normalizer& normalizer_ = Normalizer::getInstance();
  GLObject object_{};
};

} // namespace s21

#endif //  SRC_MODEL_MODEL_H_

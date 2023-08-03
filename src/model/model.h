#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include "./opening/normalizer.h"
#include "./opening/parser.h"
#include "./processing/transformer.h"

namespace s21 {

class Model {
 public:
  static Model& getInstance();

  const GLObject& getObject() const { return object_; }
  void setFilepath(const std::string& filepath);
  void changeObjState(const TransformParams& tp);

 private:
  Model() = default;
  Model(const Model&) = delete;
  Model(Model&&) = delete;
  ~Model() = default;
  Model& operator=(const Model&) = delete;
  Model& operator=(Model&&) = delete;

  Parser parser_{};
  Normalizer normalizer_{};
  GLObject object_{};
  Transformer transform_;
};

}  // namespace s21

#endif  //  SRC_MODEL_MODEL_H_

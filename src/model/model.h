#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include "parser.h"

namespace s21 {

class Model {
 public:
  static Model& getInstance() {
    static Model Model;
    return Model;
  }

  void setFilepath(const std::string& filepath) {
    parser_.removeData();
    parser_.setFilepath(filepath);
    parser_.parseFile();
  }

  std::list<double> getVertices() { return parser_.getVertices(); }
  std::list<int> getFacets() { return parser_.getFacets(); }

 private:
  Model() = default;
  Model(const Model&) = delete;
  Model(Model&&) = delete;
  ~Model() = default;
  Model& operator=(const Model&) = delete;
  Model& operator=(Model&&) = delete;

  Parser& parser_ = Parser::getInstance();



};

} // namespace s21

#endif //  SRC_MODEL_MODEL_H_
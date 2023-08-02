#ifndef SRC_MODEL_PARSER_H_
#define SRC_MODEL_PARSER_H_

#include <vector>
#include <fstream>
#include <string>
#include "../../helpers/data_objects.h"

namespace s21 {
class Parser {
 public:
  static Parser& getInstance();
  void setFilepath(const std::string& filepath) { filepath_ = filepath; }
  void setObjectRef(GLObject &object) {
    vertices_ = &object.vertices;
    facets_ = &object.facets;
  }
  void parseFile();
  
 private:
  Parser() = default;
  Parser(const Parser&) = delete;
  Parser(Parser&&) = delete;
  ~Parser() = default;
  Parser& operator=(const Parser&) = delete;
  Parser& operator=(Parser&&) = delete;

  int counter_{};
  std::string filepath_;
  std::vector<float>* vertices_ = nullptr;
  std::vector<unsigned>* facets_ = nullptr;
  void removeData();
  void parseVertices(const std::string& line);
  void parseFacets(const std::string& line);
  void createSurface(const std::vector<int> &raw);
  void reserveCapacity();
};

} // namespace s21


#endif //  SRC_MODEL_PARSER_H_

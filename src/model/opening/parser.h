#ifndef SRC_MODEL_PARSER_H_
#define SRC_MODEL_PARSER_H_

#include <fstream>
#include <string>
#include <vector>

#include "../../helpers/data_objects.h"

namespace s21 {
class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  Parser(const Parser&) = delete;
  Parser(Parser&&) = delete;
  Parser& operator=(const Parser&) = delete;
  Parser& operator=(Parser&&) = delete;

  void setObjectRef(GLObject& object);
  void parseFile();

 private:
  int counter_{};
  std::string filepath_;
  std::vector<float>* vertices_ = nullptr;
  std::vector<unsigned>* facets_ = nullptr;
  void removeData();
  void parseVertices(const std::string& line);
  void parseFacets(const std::string& line);
  void createSurface(const std::vector<int>& raw);
  void reserveCapacity();
};

}  // namespace s21

#endif  //  SRC_MODEL_PARSER_H_

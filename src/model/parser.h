#ifndef SRC_MODEL_PARSER_H_
#define SRC_MODEL_PARSER_H_

#include <list>
#include <fstream>
#include <string>

namespace s21 {

class Parser {
 public:
  static Parser& getInstance() {
    static Parser parser;
    return parser;
  }
  std::list<double> getVertices() { return vertices_; }
  std::list<int> getFacets() { return facets_; }
  void setFilepath(const std::string& filepath) { filepath_ = filepath; }
  void parseFile() {
    std::ifstream f_stream(filepath_);
    std::string line;
    while (std::getline(f_stream, line)) {
      if (line[0] == 'v' && line[1] == ' ') {
        parseVertices(line);
      } else if  (line[0] == 'f' && line[1] == ' ') {
        parseFacets(line);
      }
    }
    f_stream.close();
  }

  void removeData() {
    filepath_.clear();
    vertices_.clear();
    facets_.clear();
  }

 private:
  Parser() = default;
  Parser(const Parser&) = delete;
  Parser(Parser&&) = delete;
  ~Parser() = default;
  Parser& operator=(const Parser&) = delete;
  Parser& operator=(Parser&&) = delete;

  std::string filepath_;
  std::list<double> vertices_{};
  std::list<int> facets_{};

  void parseVertices(const std::string& line) {
    size_t size = line.size();
    for (size_t i = 2; i < size; ++i) {
      if (line[i - 1] == ' ' && (std::isdigit(line[i]) || line[i] == '-'))
        vertices_.push_back(std::stod(line.substr(i - 1)));
    }
  }

  void parseFacets(const std::string& line) {
    size_t size = line.size();
    for (size_t i = 2; i < size; ++i) {
      if (line[i - 1] == ' ' && std::isdigit(line[i]))
        facets_.push_back(std::stoi(line.substr(i - 1)) - 1);
    }
  }
};



} // namespace s21


#endif //  SRC_MODEL_PARSER_H_
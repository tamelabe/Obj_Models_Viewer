#ifndef SRC_MODEL_PARSER_H_
#define SRC_MODEL_PARSER_H_

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

namespace s21 {

class Parser {
 public:
  static Parser& getInstance() {
    static Parser parser;
    return parser;
  }
  std::vector<double> getVertices() { return vertices_; }
  std::vector<unsigned> getFacets() { return facets_; }
  void setFilepath(const std::string& filepath) {
    filepath_ = filepath;
  }
  void parseFile() {
    removeData();
    std::ifstream f_stream(filepath_);
    std::string line;
    reserveCapacity();
    while (std::getline(f_stream, line)) {
      if (line[0] == 'v' && line[1] == ' ') {
        parseVertices(line);
      } else if  (line[0] == 'f' && line[1] == ' ') {
        parseFacets(line);
      }
    }
    f_stream.close();
  }

 private:
  Parser() = default;
  Parser(const Parser&) = delete;
  Parser(Parser&&) = delete;
  ~Parser() = default;
  Parser& operator=(const Parser&) = delete;
  Parser& operator=(Parser&&) = delete;

  std::string filepath_;
  std::vector<double> vertices_{};
  std::vector<unsigned> facets_{};

  void removeData() {
    vertices_.clear();
    facets_.clear();
  }

  void parseVertices(const std::string& line) {
    size_t size = line.size();
    for (size_t i = 2; i < size; ++i) {
      if (line[i - 1] == ' ' && (std::isdigit(line[i]) || line[i] == '-'))
        vertices_.push_back(std::stod(line.substr(i - 1)));
    }
  }

  void parseFacets(const std::string& line) {
    size_t size = line.size();
    std::vector<int> raw_surface(3);
    for (size_t i = 2; i < size; ++i) {
      if (line[i - 1] == ' ' && std::isdigit(line[i]))
        raw_surface.push_back(std::stoi(line.substr(i - 1)) - 1);
    }
    createSurface(raw_surface);
  }

  void createSurface(const std::vector<int> &raw) {
    size_t size = raw.size() - 1;
    for (size_t i = 0; i < size; ++i) {
      facets_.push_back(raw[i]);
      facets_.push_back(raw[i + 1]);
    }
    facets_.push_back(raw[size]);
    facets_.push_back(raw[0]);
  }

  void reserveCapacity() {
    std::string line;
    size_t v_count = 0, f_count = 0;
    std::ifstream stream(filepath_);
    while (std::getline(stream, line)) {
      if (line[0] == 'v' && line[1] == ' ') {
        ++v_count;
      } else if (line[0] == 'f' && line[1] == ' ') {
        ++f_count;
      }
    }
    vertices_.reserve(v_count);
    facets_.reserve(f_count * 2);
    stream.close();
  }
};

} // namespace s21


#endif //  SRC_MODEL_PARSER_H_

#ifndef SRC_MODEL_PARSER_H_
#define SRC_MODEL_PARSER_H_

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "../helpers/data_objects.h"

namespace s21 {
class Parser {
 public:
  static Parser& getInstance();
  std::vector<double> getVertices() { return vertices_; }
  std::vector<unsigned> getFacets() { return facets_; }
  void setFilepath(const std::string& filepath) { filepath_ = filepath; }
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
  std::vector<double> vertices_{};
  std::vector<unsigned> facets_{};
  void removeData();
  void parseVertices(const std::string& line);
  void parseFacets(const std::string& line);
  void createSurface(const std::vector<int> &raw);
  void reserveCapacity();
};

class Normalizer {
 public:
  static Normalizer& getInstance() {
    static Normalizer normalizer;
    return normalizer;
  }
  
  void setObject(const GLObject &object) {
    object_ = object;
  }
  
  void normalize() {
    findEdges();
    std::vector<double> center{ findCenter('x'), findCenter('y'), findCenter('z') };
    for (size_t i = 0; i < object_.vertices.size(); i += 3) {
      object_.vertices[i] -= center[i % 3];
    }
  }

  GLObject getObject() {
    return object_;
  }

 private:
  Normalizer() = default;
  Normalizer(const Normalizer&) = delete;
  Normalizer(Normalizer&&) = delete;
  ~Normalizer() = default;
  Normalizer& operator=(const Normalizer&) = delete;
  Normalizer& operator=(Normalizer&&) = delete;

  Edges edges_;
  double scale_{};
  GLObject object_;

  void findEdges() {
    size_t i = 0;
    while (i < object_.vertices.size() - 2) {
      if (edges_.x_min > object_.vertices[i]) edges_.x_min = object_.vertices[i];
      if (edges_.x_max < object_.vertices[i]) edges_.x_max = object_.vertices[i];
      ++i;
      if (edges_.y_min > object_.vertices[i]) edges_.y_min = object_.vertices[i];
      if (edges_.y_max < object_.vertices[i]) edges_.y_max = object_.vertices[i];
      ++i;
      if (edges_.z_min > object_.vertices[i]) edges_.z_min = object_.vertices[i];
      if (edges_.z_max < object_.vertices[i]) edges_.z_max = object_.vertices[i];
      ++i;
    }
  }

  double findCenter(char axis) {
    double min{}, max{};
    if (axis == 'x') {
      min = edges_.x_min;
      max = edges_.x_max;
    } else if (axis == 'y') {
      min = edges_.y_min;
      max = edges_.y_max;
    } else if (axis == 'z') {
      min = edges_.z_min;
      max = edges_.z_max;
    }
    return min + (max - min) / 2;
  }
};



} // namespace s21


#endif //  SRC_MODEL_PARSER_H_

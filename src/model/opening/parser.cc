#include "parser.h"

namespace s21 {

Parser& Parser::getInstance() {
  static Parser parser;
  return parser;
}

void Parser::parseFile() {
  removeData();
  std::ifstream f_stream(filepath_);
  std::string line;
  reserveCapacity();
  while (std::getline(f_stream, line)) {
    if (line[0] == 'v' && line[1] == ' ') {
      parseVertices(line);
      ++counter_;
    } else if (line[0] == 'f' && line[1] == ' ') {
      parseFacets(line);
    }
  }
  f_stream.close();
}

void Parser::removeData() {
  vertices_->clear();
  facets_->clear();
}

void Parser::parseVertices(const std::string& line) {
  size_t size = line.size();
  for (size_t i = 2; i < size; ++i) {
    if (line[i - 1] == ' ' && (std::isdigit(line[i]) || line[i] == '-'))
      vertices_->push_back(std::stod(line.substr(i - 1)));
  }
}

void Parser::parseFacets(const std::string& line) {
  size_t size = line.size();
  std::vector<int> raw_surface;
  raw_surface.reserve(3);
  int value = 0;
  for (size_t i = 2; i < size; ++i) {
    if (line[i - 1] == ' ' && (std::isdigit(line[i]) || line[i] == '-')) {
      value = std::stoi(line.substr(i - 1)) - 1;
      if (value < 0) value += counter_ + 1;
      raw_surface.push_back(value);
    }
  }
  createSurface(raw_surface);
}

void Parser::createSurface(const std::vector<int> &raw) {
  size_t size = raw.size() - 1;
  for (size_t i = 0; i < size; ++i) {
    facets_->push_back(raw[i]);
    facets_->push_back(raw[i + 1]);
  }
  facets_->push_back(raw[size]);
  facets_->push_back(raw[0]);
}

void Parser::reserveCapacity() {
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
  vertices_->reserve(v_count);
  facets_->reserve(f_count * 2);
  stream.close();
}

} // namespace s21

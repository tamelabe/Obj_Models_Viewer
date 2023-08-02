#include "normalizer.h"

namespace s21 {

Normalizer& Normalizer::getInstance() {
  static Normalizer normalizer;
  return normalizer;
}

void Normalizer::normalize() {
  findEdges();
  std::vector<float> center{ findCenter('x'), findCenter('y'), findCenter('z') };
  size_t max_size = object_->vertices.size();
  for (size_t i = 0; i < max_size; i += 3)
    object_->vertices[i] -= center[i % 3];
}

void Normalizer::findEdges() {
  size_t i = 0;
  while (i < object_->vertices.size() - 2) {
    if (edges_.x_min > object_->vertices[i]) edges_.x_min = object_->vertices[i];
    if (edges_.x_max < object_->vertices[i]) edges_.x_max = object_->vertices[i];
    ++i;
    if (edges_.y_min > object_->vertices[i]) edges_.y_min = object_->vertices[i];
    if (edges_.y_max < object_->vertices[i]) edges_.y_max = object_->vertices[i];
    ++i;
    if (edges_.z_min > object_->vertices[i]) edges_.z_min = object_->vertices[i];
    if (edges_.z_max < object_->vertices[i]) edges_.z_max = object_->vertices[i];
    ++i;
  }
}

float Normalizer::findCenter(char axis) {
  float min{}, max{};
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

} // namespace s21
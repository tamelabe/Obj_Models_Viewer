#include "normalizer.h"

namespace s21 {

void Normalizer::setObjectRef(GLObject &object) {
  object_ = &object;
  clearEdges();
}

void Normalizer::normalize() {
  if (object_->facets.empty() || object_->vertices.empty()) return;
  findEdges();
  std::vector<float> center{findCenter('x'), findCenter('y'), findCenter('z')};
  size_t max_size = object_->vertices.size();
  findScale(findMaxDistance());
  for (size_t i = 0; i < max_size; ++i) {
    object_->vertices[i] -= center[i % 3];
    object_->vertices[i] *= scale_;
  }
}

void Normalizer::clearEdges() {
  edges_.x_max = edges_.x_min = 0;
  edges_.y_max = edges_.y_min = 0;
  edges_.z_max = edges_.z_min = 0;
  scale_ = 0;
}

void Normalizer::findEdges() {
  size_t i = 0;
  while (i < object_->vertices.size() - 2) {
    if (edges_.x_min > object_->vertices[i])
      edges_.x_min = object_->vertices[i];
    if (edges_.x_max < object_->vertices[i])
      edges_.x_max = object_->vertices[i];
    ++i;
    if (edges_.y_min > object_->vertices[i])
      edges_.y_min = object_->vertices[i];
    if (edges_.y_max < object_->vertices[i])
      edges_.y_max = object_->vertices[i];
    ++i;
    if (edges_.z_min > object_->vertices[i])
      edges_.z_min = object_->vertices[i];
    if (edges_.z_max < object_->vertices[i])
      edges_.z_max = object_->vertices[i];
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

float Normalizer::findMaxDistance() {
  float avg_x = edges_.x_max - edges_.x_min;
  float avg_y = edges_.y_max - edges_.y_min;
  float avg_z = edges_.z_max - edges_.z_min;
  if (avg_x > avg_y && avg_x > avg_z) {
    return avg_x;
  } else if (avg_y > avg_x && avg_y > avg_z) {
    return avg_y;
  } else {
    return avg_z;
  }
}

void Normalizer::findScale(float max_dist) { scale_ = (4 / max_dist); }

}  // namespace s21

#ifndef SRC_DATA_OBJECTS_H_
#define SRC_DATA_OBJECTS_H_

#include <string>
#include <vector>

namespace s21 {

struct GLObject {
 public:
  std::vector<float> vertices{};
  std::vector<unsigned> facets{};
};

struct TransformParams {
 public:
  /**
   * 'm' - move
   * 'r' - rotate
   * 's' - scale
   */
  char pos_type{};
  /**
   * x, y, z
   */
  char axis{};
  float value{};
};

struct BaseData {
 public:
  int x{};
  int y{};
  int z{};
};

struct ModelStateData {
 public:
  BaseData move;
  BaseData rotate;
  int scale{};
};

struct Edges {
 public:
  float x_min{};
  float y_min{};
  float z_min{};
  float x_max{};
  float y_max{};
  float z_max{};
};




}  // namespace s21

#endif  // SRC_DATA_OBJECTS_H_

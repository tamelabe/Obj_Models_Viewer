#ifndef SRC_DATA_OBJECTS_H_
#define SRC_DATA_OBJECTS_H_

#include <filesystem>
#include <string>
#include <vector>

namespace s21 {

class GLObject {
 public:
  GLObject() = default;
  ~GLObject() = default;
  int getVertices() const { return vertices.size() / 3; }
  int getEdges() const { return (facets.size() / 2) - (vertices.size() / 3) + 2; }
  std::string getFile() const {
    std::filesystem::path filePath(filepath);
    return filePath.filename().string();
  }
  std::vector<float> vertices{};
  std::vector<unsigned> facets{};
  std::string filepath{};
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

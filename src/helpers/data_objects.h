#ifndef SRC_DATA_OBJECTS_H_
#define SRC_DATA_OBJECTS_H_

#include <string>
#include <vector>

namespace s21 {

struct GLObject {
 public:
  std::vector<double> vertices{};
  std::vector<unsigned> facets{};
};



}  // namespace s21

#endif  // SRC_DATA_OBJECTS_H_

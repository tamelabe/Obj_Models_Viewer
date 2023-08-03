#ifndef SRC_MODEL_NORMALIZER_H_
#define SRC_MODEL_NORMALIZER_H_

#include <vector>

#include "../../helpers/data_objects.h"

namespace s21 {
class Normalizer {
 public:
  Normalizer() = default;
  ~Normalizer() = default;
  Normalizer(const Normalizer&) = delete;
  Normalizer(Normalizer&&) = delete;
  Normalizer& operator=(const Normalizer&) = delete;
  Normalizer& operator=(Normalizer&&) = delete;

  void setObjectRef(GLObject& object);
  void normalize();
  void clearEdges();

 private:
  Edges edges_;
  float scale_{};
  //  std::vector<float> center_{};
  GLObject* object_ = nullptr;

  void findEdges();
  float findCenter(char axis);
  float findMaxDistance();
  void findScale(float max_dist);
};

}  // namespace s21

#endif  //  SRC_MODEL_NORMALIZER_H_

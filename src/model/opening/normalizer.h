#ifndef SRC_MODEL_NORMALIZER_H_
#define SRC_MODEL_NORMALIZER_H_

#include <vector>
#include "../../helpers/data_objects.h"

namespace s21 {
class Normalizer {
 public:
  static Normalizer& getInstance();

  void setObjectRef(GLObject &object) { object_ = &object; }
  void normalize();

 private:
  Normalizer() = default;
  Normalizer(const Normalizer&) = delete;
  Normalizer(Normalizer&&) = delete;
  ~Normalizer() = default;
  Normalizer& operator=(const Normalizer&) = delete;
  Normalizer& operator=(Normalizer&&) = delete;

  Edges edges_;
  float scale_{};
  GLObject* object_ = nullptr;

  void findEdges();
  float findCenter(char axis);
};

} // namespace s21


#endif //  SRC_MODEL_NORMALIZER_H_
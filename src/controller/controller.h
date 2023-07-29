#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

#include "../Model/model.h"

namespace s21 {

class Controller {
 public:
  static Controller& getInstance() {
    if (!controller_) controller_ = new Controller();
    return controller_;
  }

  void setFilepath(const std::string& filepath) { model_.setFilepath(filepath); }
  std::list<double> getVertices() { return model_.getVertices(); }
  std::list<int> getFacets() { return model_.getFacets(); }

 private:
  Controller() { Model& model_ = Model::getInstance(); }
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  ~Controller() = default;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;

  static Controller* controller_;
};

} // namespace s21

#endif //  SRC_CONTROLLER_CONTROLLER_H_
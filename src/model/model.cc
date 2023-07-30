#include <iostream>

class BaseMovement {
 public:
    virtual BaseMovement() = default;
    virtual ~BaseMovement() = default;
    virtual void Execute(float x, float y, float z) = 0;

};

class Move : public BaseMovement {
 public:
  void Execute(float x, float y, float z) override {
    std::cout << "Move";
  }
  ~Move() override {};
};

class Rotate : public BaseMovement {
 public:
  void Execute(float x, float y, float z) override {
    std::cout << "Rotate";
  }
  ~Rotate() override {};
};

class Scale : public BaseMovement {
 public:
  void Execute(float x, float y, float z) override {
    std::cout << "Scale";
  }
  ~Scale() override {};
};

class Strategy {
 public:
  Strategy() : current(new Move) {};
  void SetStrategy(BaseMovement *c)
  {
    delete current;
    current = c;
  }
  ~Strategy() {
    delete current;
  }

  void Execute(float x, float y, float z) {
    current->Execute(x, y, z);
  }
 private:
  BaseMovement *current = nullptr;
};

int main() {
  Strategy s;
  s.Execute(0, 0, 0);
  s.SetStrategy(new Scale);
  s.Execute(0, 0, 0);
  s.SetStrategy(new Rotate);
  s.Execute(0, 0, 0);
}


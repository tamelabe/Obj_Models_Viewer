#include <gtest/gtest.h>

#include "../model/parser.h"

#include <iostream>

using namespace s21;

class ParserTest : public testing::Test {
 protected:
  Parser& parser = Parser::getInstance();
};

TEST_F(ParserTest, VerticesTest) {
  parser.setFilepath("/Volumes/89823065724/Projects/3D_obj_Viewer/src/obj/cube.obj");
  parser.parseFile();
  std::list<double> vert = parser.getVertices();
  std::list<int> fac = parser.getFacets();
  for (auto i = vert.begin(); i != vert.end(); ++i) {
    std::cout << *i << '\n';
  }
  std::cout << "FACETS:\n";
  for (auto i = fac.begin(); i != fac.end(); ++i) {
    std::cout << *i << '\n';
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
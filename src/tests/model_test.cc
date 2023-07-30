#include <gtest/gtest.h>

#include "../model/parser.h"

#include <iostream>

using namespace s21;

class ParserTest : public testing::Test {
 protected:
  Parser& parser = Parser::getInstance();
};

TEST_F(ParserTest, VerticesTest) {
  std::string file_path = "/Volumes/89823065724/Projects/3D_obj_Viewer/src/obj/cube.obj";
  parser.setFilepath(file_path);
  parser.parseFile();
  std::vector<double> vert = parser.getVertices();
  std::vector<unsigned> fac = parser.getFacets();
  for (size_t i = 0; i < vert.size(); ++i) {
    std::cout << vert[i] << '\n';
  }
  std::cout << "FACETS:\n";
  for (size_t i = 0; i < fac.size(); ++i) {
    std::cout << fac[i] << '\n';
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
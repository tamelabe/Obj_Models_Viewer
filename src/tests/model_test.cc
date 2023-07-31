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
  for (size_t i = 2; i < vert.size(); i += 3) {
    std::cout << vert[i - 2] << ' ' << vert[i - 1] << ' ' << vert[i] << '\n';
  }
  std::cout << "FACETS:\n";
  for (size_t i = 5; i < fac.size(); i += 6) {
    std::cout << fac[i - 5] << ' ' << fac[i - 4] << ' ' << fac[i-3] << ' ';
    std::cout << fac[i - 2] << ' ' << fac[i - 1] << ' ' << fac[i] << '\n';
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
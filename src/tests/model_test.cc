#include "../model/model.h"

#include <gtest/gtest.h>

#include <iostream>

#include "../model/opening/normalizer.h"
#include "../model/opening/parser.h"
#include "../model/processing/base_movement.h"
#include "../model/processing/transformer.h"

using namespace s21;

class ParserTest : public testing::Test {
 protected:
  Model& model_ = Model::getInstance();
  const GLObject* object_;
  TransformParams tp_;
  std::string cube_path_ =
      "/Volumes/89823065724/Projects/3D_obj_Viewer/src/obj/cube.obj";
  std::string skull_path_ =
      "/Volumes/89823065724/Projects/3D_obj_Viewer/src/obj/skull.obj";
  std::string cow_path_ =
      "/Volumes/89823065724/Projects/3D_obj_Viewer/src/obj/Cow.obj";
};

TEST_F(ParserTest, DataTest) {
  model_.setFilepath(cube_path_);
  object_ = &model_.getObject();
  EXPECT_EQ(object_->getFile(), "cube.obj");
  EXPECT_EQ(object_->getVertices(), 8);
  EXPECT_EQ(object_->getEdges(), 30);
}

TEST_F(ParserTest, MoveTest) {
  model_.setFilepath(skull_path_);
  object_ = &model_.getObject();
  float prev = object_->vertices[0];
  tp_.value = 180;
  tp_.pos_type = 'm';
  tp_.axis = 'x';
  model_.changeObjState(tp_);
  tp_.axis = 'y';
  model_.changeObjState(tp_);
  tp_.axis = 'z';
  model_.changeObjState(tp_);
  tp_.value = -180;
  model_.changeObjState(tp_);
  tp_.axis = 'x';
  model_.changeObjState(tp_);
  tp_.axis = 'y';
  model_.changeObjState(tp_);
  EXPECT_NEAR(prev, object_->vertices[0], 1e-5);
}

TEST_F(ParserTest, RotateTest) {
  model_.setFilepath(skull_path_);
  object_ = &model_.getObject();
  float prev = object_->vertices[0];
  tp_.value = 180;
  tp_.pos_type = 'r';
  tp_.axis = 'x';
  model_.changeObjState(tp_);
  tp_.axis = 'y';
  model_.changeObjState(tp_);
  tp_.axis = 'z';
  model_.changeObjState(tp_);
  EXPECT_NEAR(prev, object_->vertices[0], 1e-5);
}

TEST_F(ParserTest, ScaleTest) {
  model_.setFilepath(cow_path_);
  object_ = &model_.getObject();
  float prev = object_->vertices[0];
  tp_.value = 200;
  tp_.pos_type = 's';
  tp_.axis = 'x';
  model_.changeObjState(tp_);
  tp_.axis = 'y';
  model_.changeObjState(tp_);
  tp_.axis = 'z';
  model_.changeObjState(tp_);
  tp_.value = -200;
  model_.changeObjState(tp_);
  tp_.axis = 'x';
  model_.changeObjState(tp_);
  tp_.axis = 'y';
  model_.changeObjState(tp_);
  EXPECT_NEAR(prev, object_->vertices[0], 1e-5);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
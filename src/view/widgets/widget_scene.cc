#include "widget_scene.h"
#include "./ui_widget_scene.h"

Scene::Scene(QWidget *parent)
    : QWidget(parent),
      ui_(new Ui::Scene)
{
    ui_->setupUi(this);
}

Scene::~Scene()
{
    delete ui_;
}

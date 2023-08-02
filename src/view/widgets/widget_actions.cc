#include "widget_actions.h"
#include "ui_widget_actions.h"

#include <iostream>


Actions::Actions(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Actions)
{
    ui_->setupUi(this);
    connectButtons();
}

Actions::~Actions()
{
    delete ui_;
}

void Actions::connectButtons() {
    connect(ui_->bt_load_file, &QPushButton::clicked, this, [=](){ loadFile(); });
    connect(ui_->bt_save_bmp, &QPushButton::clicked, this, [=](){ savePic('b'); });
    connect(ui_->bt_save_jpeg, &QPushButton::clicked, this, [=](){ savePic('j'); });
    connect(ui_->bt_rec, &QPushButton::clicked, this, [=](){ loadFile(); });
}

void Actions::loadFile() {
//    QString fileQS = QFileDialog::getOpenFileName(this, tr("Load Model"),
//                                                       QDir::homePath(), tr("*.obj"));
//    if (fileQS.isEmpty()) return;
//    filepath_ = fileQS.toStdString();
//    std::cout << filepath_ << '\n';
    filepath_ = "/Volumes/89823065724/Projects/3D_obj_Viewer/src/obj/skull.obj";
//    filepath_ = "/Volumes/89823065724/Downloads/bugatti/bugatti.obj";
    controller_.setFilepath(filepath_);
    emit fileLoaded();
}

void Actions::savePic(char type) {
    if (type == 'b') {

    } else if (type == 'j') {

    }
}

void Actions::rec() {

}

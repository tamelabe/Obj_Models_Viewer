#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1680, 1070);
    connect(ui->w_actions, &Actions::fileLoaded, this, &MainWindow::updateView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateView()
{
    ui->w_scene->updateObject();
}

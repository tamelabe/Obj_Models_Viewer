#include <QApplication>

#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setOrganizationName("TamelabeYonnargeLTD");
  QCoreApplication::setOrganizationDomain("fakedomain.com");
  QCoreApplication::setApplicationName("3DViewer");
  QApplication a(argc, argv);
  s21::MainWindow w;
  w.show();
  return a.exec();
}

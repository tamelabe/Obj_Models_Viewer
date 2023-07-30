#ifndef WIDGET_SCENE_H
#define WIDGET_SCENE_H

#include <QWidget>


#include <QOpenGLBuffer>


#include "../../helpers/data_objects.h"
#include "../../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Scene; }
QT_END_NAMESPACE

class Scene : public QOpenGLWidget
{
    Q_OBJECT

public:
    Scene(QWidget *parent = nullptr);
    ~Scene();

    void setObject(s21::GLObject);
    void drawObject();

private:
    Ui::Scene *ui_;
    s21::GLObject object_;
    s21::Controller& controller_ = s21::Controller::getInstance();
    QOpenGLBuffer vertex_buffer_;
    QOpenGLBuffer facets_buffer_;

    void updateView();
};
#endif // WIDGET_SCENE_H

#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QGLWidget>
#include <QGLFunctions>
#include <GL/gl.h>
#include <GL/glu.h>

class OpenGLWidget : public QGLWidget, protected QGLFunctions
{
public:
    OpenGLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent(QKeyEvent *event);

private:
    GLfloat m_xRot;                                 //x旋转角度
    GLfloat m_yRot;                                 //y旋转角度
    GLfloat m_xSpeed;                               //x旋转速度
    GLfloat m_ySpeed;                               //y旋转速度
    GLfloat m_Deep;                                 //深入屏幕的距离
    bool m_Light;                                   //光源的开/关

    bool m_Fullscreen;                                //是否全屏显示
};

#endif // OPENGLWIDGET_H

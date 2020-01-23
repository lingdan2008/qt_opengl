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
    
private:
    GLfloat m_rtri;
    GLfloat m_rquad;
};

#endif // OPENGLWIDGET_H

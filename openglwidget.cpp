#include "openglwidget.h"
#include <QDebug>

OpenGLWidget::OpenGLWidget()
{
    qDebug() << __FUNCTION__;
    m_rtri = 0.0f;
    m_rquad = 0.0f;
}

void OpenGLWidget::initializeGL()
{
    qDebug() << __FUNCTION__;
    initializeGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void OpenGLWidget::paintGL()
{
    qDebug() << __FUNCTION__;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-1.5f, 0.0f, -6.0f);
    glRotatef(m_rtri, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    glLoadIdentity();

    glTranslatef(1.5f, 0.0f, -6.0f);
    //glTranslatef(3.0f, 0.0f, 0.0f);
    glRotatef(m_rquad, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();

    m_rtri += 0.5f;
    m_rquad -= 0.5f;
}

void OpenGLWidget::resizeGL(int w, int h)
{
    qDebug() << __FUNCTION__;

    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

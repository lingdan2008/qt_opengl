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
    glColor3f(1.0f, 0.0f, 0.0f);                    //红色
    glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(前侧面)
    glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
    glVertex3f(-1.0f, -1.0f, 1.0f);                 //左下(前侧面)
    glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
    glVertex3f(1.0f, -1.0f, 1.0f);                  //右下(前侧面)

    glColor3f(1.0f, 0.0f, 0.0f);                    //红色
    glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(右侧面)
    glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
    glVertex3f(1.0f, -1.0f, 1.0f);                  //左下(右侧面)
    glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
    glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(右侧面)

    glColor3f(1.0f, 0.0f, 0.0f);                    //红色
    glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(后侧面)
    glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
    glVertex3f(1.0f, -1.0f, -1.0f);                 //左下(后侧面)
    glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
    glVertex3f(-1.0f, -1.0f, -1.0f);                //右下(后侧面)

    glColor3f(1.0f, 0.0f, 0.0f);                    //红色
    glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(左侧面)
    glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
    glVertex3f(-1.0f, -1.0f, -1.0f);                //左下(左侧面)
    glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
    glVertex3f(-1.0f, -1.0f, 1.0f);                 //右下(左侧面)
    glEnd();

    glLoadIdentity();

    glTranslatef(1.5f, 0.0f, -6.0f);
    //glTranslatef(3.0f, 0.0f, 0.0f);
    glRotatef(m_rquad, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
    glVertex3f(1.0f, 1.0f, -1.0f);                  //右上(顶面)
    glVertex3f(-1.0f, 1.0f, -1.0f);                 //左上(顶面)
    glVertex3f(-1.0f, 1.0f, 1.0f);                  //左下(顶面)
    glVertex3f(1.0f, 1.0f, 1.0f);                   //右下(顶面)

    glColor3f(1.0f, 0.5f, 0.0f);                    //橙色
    glVertex3f(1.0f, -1.0f, 1.0f);                  //右上(底面)
    glVertex3f(-1.0f, -1.0f, 1.0f);                 //左上(底面)
    glVertex3f(-1.0f, -1.0f, -1.0f);                //左下(底面)
    glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(底面)

    glColor3f(1.0f, 0.0f, 0.0f);                    //红色
    glVertex3f(1.0f, 1.0f, 1.0f);                   //右上(前面)
    glVertex3f(-1.0f, 1.0f, 1.0f);                  //左上(前面)
    glVertex3f(-1.0f, -1.0f, 1.0f);                 //左下(前面)
    glVertex3f(1.0f, -1.0f, 1.0f);                  //右下(前面)

    glColor3f(1.0f, 1.0f, 0.0f);                    //黄色
    glVertex3f(1.0f, -1.0f, -1.0f);                 //右上(后面)
    glVertex3f(-1.0f, -1.0f, -1.0f);                //左上(后面)
    glVertex3f(-1.0f, 1.0f, -1.0f);                 //左下(后面)
    glVertex3f(1.0f, 1.0f, -1.0f);                  //右下(后面)

    glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
    glVertex3f(-1.0f, 1.0f, 1.0f);                  //右上(左面)
    glVertex3f(-1.0f, 1.0f, -1.0f);                 //左上(左面)
    glVertex3f(-1.0f, -1.0f, -1.0f);                //左下(左面)
    glVertex3f(-1.0f, -1.0f, 1.0f);                 //右下(左面)

    glColor3f(1.0f, 0.0f, 1.0f);                    //紫色
    glVertex3f(1.0f, 1.0f, -1.0f);                  //右上(右面)
    glVertex3f(1.0f, 1.0f, 1.0f);                   //左上(右面)
    glVertex3f(1.0f, -1.0f, 1.0f);                  //左下(右面)
    glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(右面)
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

#include "openglwidget.h"
#include <QDebug>

OpenGLWidget::OpenGLWidget()
{
    qDebug() << __FUNCTION__;

    setFocusPolicy(Qt::StrongFocus);

    m_xRot = 0.0f;
    m_yRot = 0.0f;
    m_xSpeed = 0.0f;
    m_ySpeed = 0.0f;
    m_Deep = -5.0f;
    m_Light = false;
    m_Fullscreen = false;
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

    GLfloat LightAmbient[] = {0.5f, 0.5f, 0.5f, 1.0f};  //环境光参数
    GLfloat LightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};  //漫散光参数
    GLfloat LightPosition[] = {0.0f, 0.0f, 2.0f, 1.0f}; //光源位置
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);     //设置环境光
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);     //设置漫射光
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);   //设置光源位置
    glEnable(GL_LIGHT1);                                //启动一号光源
}

void OpenGLWidget::paintGL()
{
    qDebug() << __FUNCTION__;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, m_Deep);                   //移入屏幕
    glRotatef(m_xRot, 1.0f, 0.0f, 0.0f);                //绕x轴旋转
    glRotatef(m_yRot, 0.0f, 1.0f, 0.0f);                //绕y轴旋转

    glTranslatef(-1.5f, 0.0f, -6.0f);

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
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
    glVertex3f(1.0f, 1.0f, -1.0f);                  //右上(顶面)
    glVertex3f(-1.0f, 1.0f, -1.0f);                 //左上(顶面)
    glVertex3f(-1.0f, 1.0f, 1.0f);                  //左下(顶面)
    glVertex3f(1.0f, 1.0f, 1.0f);                   //右下(顶面)

    glNormal3f(0.0f, -1.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);                    //橙色
    glVertex3f(1.0f, -1.0f, 1.0f);                  //右上(底面)
    glVertex3f(-1.0f, -1.0f, 1.0f);                 //左上(底面)
    glVertex3f(-1.0f, -1.0f, -1.0f);                //左下(底面)
    glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(底面)

    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);                    //红色
    glVertex3f(1.0f, 1.0f, 1.0f);                   //右上(前面)
    glVertex3f(-1.0f, 1.0f, 1.0f);                  //左上(前面)
    glVertex3f(-1.0f, -1.0f, 1.0f);                 //左下(前面)
    glVertex3f(1.0f, -1.0f, 1.0f);                  //右下(前面)

    glNormal3f(0.0f, 0.0f, -1.0f);
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

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f);                    //紫色
    glVertex3f(1.0f, 1.0f, -1.0f);                  //右上(右面)
    glVertex3f(1.0f, 1.0f, 1.0f);                   //左上(右面)
    glVertex3f(1.0f, -1.0f, 1.0f);                  //左下(右面)
    glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(右面)
    glEnd();

    m_xRot += m_xSpeed;                                 //x轴旋转
    m_yRot += m_ySpeed;                                 //y轴旋转

    qDebug() << m_xRot << m_yRot;
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

void OpenGLWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << __FUNCTION__ << event->key();

    switch (event->key()) {
    case Qt::Key_F1:
        m_Fullscreen = !m_Fullscreen;
        if(m_Fullscreen) showFullScreen();
        else showNormal();
        break;
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_L:
        m_Light = !m_Light;
        if(m_Light) glEnable(GL_LIGHTING);
        else glDisable(GL_LIGHTING);
        break;
    case Qt::Key_Left:
        m_Deep -= 0.1f;
        break;
    case Qt::Key_Right:
        m_Deep += 0.1f;
        break;
    case Qt::Key_Up:
        m_xSpeed += 0.1f;
        break;
    case Qt::Key_Down:
        m_xSpeed -= 0.1f;
        break;
    default:
        break;
    }

    this->repaint();
}

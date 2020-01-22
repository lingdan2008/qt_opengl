#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    OpenGLWidget* pWidget = new OpenGLWidget();
    QVBoxLayout* pLayout = new QVBoxLayout();

    pLayout->addWidget(pWidget);
    this->ui->centralWidget->setLayout(pLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

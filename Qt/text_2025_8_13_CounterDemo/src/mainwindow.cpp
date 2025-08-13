#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , count(0) // Initialize the counter to zero
{
    ui->setupUi(this);
    // Connect the button click signals to the respective slots
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::onBtnAddClicked);
    connect(ui->btnReset, &QPushButton::clicked, this, &MainWindow::onBtnResetClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnAddClicked()
{
    count++;
    ui->lblCount->setText(QString::number(count));
}

void MainWindow::onBtnResetClicked()
{
    count = 0;
    ui->lblCount->setText(QString::number(count));
}
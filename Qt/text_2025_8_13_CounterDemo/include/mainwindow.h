#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slot for button click
    void onBtnAddClicked();
    // Slot for reset button click
    void onBtnResetClicked();

private:
    Ui::MainWindow *ui;
    int count; // Counter to keep track of button clicks
};
#endif // MAINWINDOW_H

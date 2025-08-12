#include "sidepanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SidePanel w;  // 实例化UI对应的类
    w.show();
    return a.exec();
}
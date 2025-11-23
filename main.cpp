#include "loginpage.h"
#include <QFile>
#include <QApplication>
using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginpage w;
    w.show();
    return a.exec();
}

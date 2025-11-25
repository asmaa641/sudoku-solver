#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Node.h"
#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //   void onCellClicked(int row, int col);

    void on_Sign_Out_clicked();

private:
    Ui::MainWindow *ui;
    Node * n;
};
#endif // MAINWINDOW_H

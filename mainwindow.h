#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Node.h"
#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLabel>
#include <QGraphicsTextItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString na,int l,QWidget *parent = nullptr);
    ~MainWindow();
private slots:
     void onCellClicked(int row, int col);

    void on_signOut_clicked();

    void on_ClearCell_clicked();
private:
    Ui::MainWindow *ui;
    Node * n;
    QTableWidget* table;
    int tries;
    QString name;
    int level;
    QLabel * info;

    struct Move {
        int row;
        int col;
        int oldVal;
        int newVal;
    };

    QVector<Move> undoStack;
    QVector<Move> redoStack;

    int selectedRow = -1;
    int selectedCol = -1;
};
#endif // MAINWINDOW_H

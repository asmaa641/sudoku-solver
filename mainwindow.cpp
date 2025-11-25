#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/qheaderview.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    n = new Node();
    n->board.generatePuzzle(1);

    QTableWidget* table = new QTableWidget(9, 9, this);
    setCentralWidget(table);

    // Ensure table is 9×9
    table->setRowCount(9);
    table->setColumnCount(9);
    table->setFixedSize(600, 600);
    int cellSize = 60;
    table->horizontalHeader()->setDefaultSectionSize(cellSize);//set the table size
    table->verticalHeader()->setDefaultSectionSize(cellSize);//set the table size
    table->horizontalHeader()->setVisible(false);//turns off scrolling
    table->verticalHeader()->setVisible(false);//turns off scrolling
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);


    // Create all items
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            QTableWidgetItem* item = new QTableWidgetItem("");
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(r, c, item);
        }
    }

    // Fill puzzle into the table
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            int val = n->board.getCell(r,c);
            if (val != 0) {
                QTableWidgetItem* item = table->item(r,c);
                item->setText(QString::number(val));
                item->setFlags(Qt::NoItemFlags); // make the cell readonly
                item->setBackground(Qt::lightGray);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::onCellClicked(int row, int col)
//{
//    bool ok;
//  int num = QInputDialog::getInt(
//    this,
//  "Place number",
//   "Enter a value (1–9):",
//   1, 1, 9, 1, &ok
//   );//this is like a message box but you can write in it

//if (!ok) return; // user canceled

// check if valid move in your Matrix
//  if (n->board.validCellPlacement(row, col, num)) {
//    n->board.setCell(row, col, num);
//  table->item(row, col)->setText(QString::number(num));
//  } else {
//    QMessageBox::warning(this, "Invalid", "Invalid Sudoku move!");
// }
//}



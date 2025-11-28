#include "solutiondialog.h"
#include <QtWidgets/QHeaderView>
#include "Matrix.h"

SolutionDialog::SolutionDialog( Matrix &board, QWidget *parent)
    : QDialog(parent)
{
    this->setWindowTitle("Sudoku Solution");
    this->setFixedSize(375, 375);

    table = new QTableWidget(9, 9, this);
    table->setGeometry(10, 10, 380, 380);
    table->horizontalHeader()->setVisible(false);
    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int cellSize = 40;
    table->horizontalHeader()->setDefaultSectionSize(cellSize);
    table->verticalHeader()->setDefaultSectionSize(cellSize);

    // Fill solution
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            int val = board.getCell(r, c);
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(val));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(Qt::NoItemFlags);
            table->setItem(r, c, item);
        }
    }
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            bool isDark = ((r / 3) + (c / 3)) % 2 == 0;

            if (isDark)
                table->item(r, c)->setBackground(QColor(230, 230, 230));
            else
                table->item(r, c)->setBackground(QColor(255, 255, 255));
        }

    }
}

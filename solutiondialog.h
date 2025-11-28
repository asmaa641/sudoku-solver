#ifndef SOLUTIONDIALOG_H
#define SOLUTIONDIALOG_H

#include <QDialog>
#include <QTableWidget>

#include "Matrix.h"

class SolutionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SolutionDialog( Matrix &board, QWidget *parent = nullptr);

private:
    QTableWidget *table;
};

#endif // SOLUTIONDIALOG_H

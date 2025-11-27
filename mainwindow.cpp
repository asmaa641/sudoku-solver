#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/qheaderview.h>
#include "loginpage.h"
#include <qdir.h>
#include <QVector>


static QString usersFilePath()
{
    // Directory where the .exe / .app binary lives
    QString baseDir = QCoreApplication::applicationDirPath();
    QString dir = baseDir + "/new/prefix1";

    QDir qdir;
    if (!qdir.mkpath(dir)) {
        qDebug() << "ERROR: Could not create directory" << dir;
    }

    QString path = dir + "/users.txt";
    qDebug() << "usersFilePath =" << path;
    return path;
}
void updateUserLevelInFile(const QString& username, int newLevel)
{
    QFile file(usersFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading";
        return;
    }

    QStringList lines;
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(':');
        if (parts.size() == 3 && parts[0] == username) {
            parts[2] = QString::number(newLevel);  // Update level
            line = parts.join(":");
        }
        lines << line;
    }

    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Could not open file for writing";
        return;
    }

    QTextStream out(&file);
    for (auto& l : lines)
        out << l << "\n";

    file.close();
}


MainWindow::MainWindow(QString na,int l,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 700);
    tries=3;
    name=na;
    level=l;
    qDebug()<<"This users level: "<<level;

    n = new Node();
    if(level<10){
        qDebug()<<"Less than 10 called";
        n->board.generatePuzzle(1);}
    else if(level<30){
        qDebug()<<"Less than 30 called";
        n->board.generatePuzzle(2);
    }
    else if(level<50){
        qDebug()<<"Less than 50 called";
        n->board.generatePuzzle(3);
    }
    else{n->board.generatePuzzle(4);}//to create a game with different levels of difficulty

    table = new QTableWidget(9, 9, this);
   // setCentralWidget(table);

    // Ensure table is 9×9
    table->setRowCount(9);
    table->setColumnCount(9);
    //table->setFixedSize(600, 600);
    table->setGeometry(150, 70, 542, 542);

    info = new QLabel(this);
    info->setText("         Welcome " + name +
                  " \n  Life remaining: " + QString::number(tries) +
                  "  Level: " + QString::number(level));

    info->move(300, 2);
    info->resize(300, 40);
    info->setStyleSheet("font-size: 18px; font-weight: bold;");

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
    //this makes the 3x3 line to be bolded so that it is easier to see the divisions easier
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            bool isDark = ((r / 3) + (c / 3)) % 2 == 0;

            if (isDark)
                table->item(r, c)->setBackground(QColor(230, 230, 230));
            else
                table->item(r, c)->setBackground(QColor(255, 255, 255));
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
    connect(table, &QTableWidget::cellClicked,
            this, &MainWindow::onCellClicked);


    QPushButton *clearButton = new QPushButton("Clear Cell", this);
    // clearButton->setFlat(true);                 // removes raised frame
    // clearButton->setText("");
    // clearButton->setIcon(QIcon(":/new/prefix1/clearcell.png"));
    // clearButton->setIconSize(QSize(56, 56));
    QPushButton *signOutButton = new QPushButton("Sign out", this);
    // signOutButton->setFlat(true);                 // removes raised frame
    // signOutButton->setText("");
    // signOutButton->setIcon(QIcon(":/new/prefix1/signout.png"));
    // signOutButton->setIconSize(QSize(56, 56));

    int buttonsTop = 70 + 542 + 10; // 10 pixels undr the table
    int buttonsLeft = 150; // where the table is left wise


    clearButton->setGeometry(buttonsLeft + 240, buttonsTop, 100, 30);
    signOutButton->setGeometry(buttonsLeft + 360, buttonsTop, 100, 30);


    connect(clearButton, &QPushButton::clicked,
            this, &MainWindow::on_ClearCell_clicked);
    connect(signOutButton, &QPushButton::clicked,
            this, &MainWindow::on_signOut_clicked);



}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCellClicked(int row, int col)
{
    selectedRow = row;
    selectedCol = col;

    bool ok;
    QString currentText = table->item(row, col)->text();

    QTableWidgetItem* item = table->item(row, col);
    QColor bgColor = item->background().color();

    if (!currentText.isEmpty() &&  bgColor==Qt::lightGray)
    {
        QMessageBox::information(this, "Not allowed",
                                 "This cell is part of the original puzzle!");
        return;
    }//this is to make sure he cannot press an already given spot

    int num = QInputDialog::getInt(this,"Place number","Enter a value (1–9):", 1, 1, 9, 1, &ok);//this is like a message box but you can write in it

    if (!ok) return; // canceled input

  if (n->board.validCellPlacement(row, col, num)) {//if valid add the number

        n->board.setCell(row, col, num);
        table->item(row, col)->setText(QString::number(num));

     }



   else {
      tries--;
      info->setText("         Welcome " + name +
                    " \n  Life remaining: " + QString::number(tries) +
                    "  Level: " + QString::number(level));
    QMessageBox::warning(this, "Invalid", "Invalid Sudoku move!");
   }

  if(tries==0){
     QMessageBox::critical(this, "Game Failed", "You have finished all your tries \n better luck next time!!");
      close();
   }

  if(n->board.isComplete()){
      level++;
      updateUserLevelInFile(name, level);
     QMessageBox::information(this,"Game Finished Successfully","Congratulations \n You have aced this game!!");
      close();
   }
}



void MainWindow::on_ClearCell_clicked()
{
    if (selectedRow < 0 || selectedCol < 0)
        return;

    QTableWidgetItem *item = table->item(selectedRow, selectedCol);
    if (!item) return;

    if (item->background().color() == Qt::lightGray) {
        QMessageBox::information(this, "Not allowed",
                                 "This cell is part of the original puzzle!");
        return;
    }

    int oldVal = n->board.getCell(selectedRow, selectedCol);
    if (oldVal == 0)
        return;

    Move m;
    m.row = selectedRow;
    m.col = selectedCol;
    m.oldVal = oldVal;
    m.newVal = 0;

    undoStack.push_back(m);
    redoStack.clear();

    n->board.setCell(selectedRow, selectedCol, 0);
    item->setText("");
}



void MainWindow::on_signOut_clicked(){
    loginpage *login = new loginpage(this);
    this->hide();
    login->show();

}


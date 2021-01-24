#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    ui->textEdit->zoomOut();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionWord_Wrap_triggered()
{
    ui->textEdit->wordWrapMode();
}

void MainWindow::on_actionNew_File_triggered()
{
  mFilename = "";
  ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open a file");
    if(!file.isEmpty()){
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
            mFilename = file;
            QTextStream in (&sFile);
            QString text = in.readAll();
            sFile.close();
            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_File_triggered()
{
    QFile sFile(mFilename);
    if(mFilename.isEmpty()){ on_actionSave_As_File_triggered(); }
    else{
    if(sFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&sFile);
        out<<ui->textEdit->toPlainText();
        sFile.close();
    } }
}

void MainWindow::on_actionSave_As_File_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Save a file");
    if(!file.isEmpty()){
        mFilename = file;
        on_actionSave_File_triggered();
    }
}

void MainWindow::on_actionBold_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.bold() ? font.setBold(false) : font.setBold(true);
    ui->textEdit->setCurrentFont(font);
    changed_font = true;
}


void MainWindow::on_actionItalic_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.italic() ? font.setItalic(false) : font.setItalic(true);
    ui->textEdit->setCurrentFont(font);
    changed_font = true;
}

void MainWindow::on_actionUnderline_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.underline() ? font.setUnderline(false) : font.setUnderline(true);
    ui->textEdit->setCurrentFont(font);
    changed_font = true;
}

void MainWindow::on_actionColor_triggered()
{
    QColor current_color = ui->textEdit->currentCharFormat().foreground().color();
    QColor color = QColorDialog::getColor(current_color,this,"Select any color");
    ui->textEdit->setTextColor(color);
    changed_font = true;
}

void MainWindow::on_actionAbout_us_triggered()
{
    mDialog = new Dialog(this);
    mDialog->show();
}

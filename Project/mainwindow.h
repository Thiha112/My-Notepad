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
    void on_actionSelect_All_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionExit_triggered();

    void on_actionWord_Wrap_triggered();

    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_File_triggered();

    void on_actionSave_As_File_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_actionColor_triggered();

    void on_actionAbout_us_triggered();

private:
    Ui::MainWindow *ui;
    QString mFilename;
    bool changed_font;
    QDialog *mDialog;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui {
class app;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     int n;
     int m;
     std::vector<int> tm;
     std::vector<std::vector<int>> c;
     std::vector<std::vector<int>> p;
     QString allText;

private:
    Ui::app *ui;

private slots:
    void on_run_clicked();
    void on_fill_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};


#endif // MAINWINDOW_H

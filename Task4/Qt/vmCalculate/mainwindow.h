#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bijection.h"
#include "newton.h"
#include "func.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double left;
    double right, epsilon=2, solve;
    double a;
    Bijection* b;
    Newton* n;
    // solve = b.solve();
       // std::cout<<std::setprecision(25)<<b.solve();;

private slots:
    void on_left_2_editingFinished();

    void on_right_2_editingFinished();

    void on_argument_2_editingFinished();

    void on_epsilon_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Func* funcShow;
};

#endif // MAINWINDOW_H

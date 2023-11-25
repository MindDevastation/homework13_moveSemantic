#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "realstate.h"
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
    buildings build1;
    buildings build2;
    buildings build3;
    buildings build4;
    owners own1;
    owners own2;
    owners own3;
    int ind = 0;
    int own = 0;

private slots:
    void on_trade_clicked();

    void on_pushButton_2_clicked();

    void on_owner_activated(int index);

    void on_building_activated(int index);

    void on_onw1Ch_activated(int index);

    void on_own2Ch_activated(int index);

    void on_bldCh_activated(int index);

    void myMove(owners& inp, owners& outp, int k);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

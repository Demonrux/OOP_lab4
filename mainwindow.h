#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onFileButtonClicked();
    void onLoadButtonClicked();
    void onExitButtonClicked();
    void onRotateXPlusClicked();
    void onRotateXMinusClicked();
    void onRotateYPlusClicked();
    void onRotateYMinusClicked();
    void onRotateZPlusClicked();
    void onRotateZMinusClicked();
    void onTranslateXPlusClicked();
    void onTranslateXMinusClicked();
    void onTranslateYPlusClicked();
    void onTranslateYMinusClicked();
    void onTranslateZPlusClicked();
    void onTranslateZMinusClicked();
    void onZoomInClicked();
    void onZoomOutClicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* graphicsScene;
    std::unique_ptr<Facade> facade;

    void setupConnections();
    void drawScene();
    void DrawAxes();
    void clearScene();
};

#endif // MAINWINDOW_H

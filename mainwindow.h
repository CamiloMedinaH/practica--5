#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "miesfera.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();
    void aumentarPuntos();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;
    QGraphicsRectItem* bordeI;
    QGraphicsRectItem* bordeD;
    QGraphicsRectItem* bordeS;
    QGraphicsRectItem* bordeIn;
    QGraphicsRectItem* borde1;
    QGraphicsRectItem* borde2;
    QGraphicsRectItem* borde3;
    QGraphicsRectItem* borde4;
    QGraphicsRectItem* borde5;
    QGraphicsRectItem* borde6;
    QGraphicsRectItem* pac;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    miesfera* bola1;
    miesfera* bola2;
    miesfera* bola3;
    miesfera* bola4;
    miesfera* bola5;
    miesfera* bola6;
    miesfera* bola7;
    miesfera* bola8;
    miesfera* bola9;
    miesfera* bola10;
    QTimer *timer;

    int puntuacion;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

};
#endif // MAINWINDOW_H

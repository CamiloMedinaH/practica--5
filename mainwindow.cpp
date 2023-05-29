#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena=new QGraphicsScene(0,0,400,300);
    ui->graphicsView->setScene(escena);

    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;

    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPuntos()));

    timer->start(33);

    bordeI=new QGraphicsRectItem(0,0,20,280);
    escena->addItem(bordeI);
    bordeI->setBrush(Qt::lightGray);

    bordeD=new QGraphicsRectItem(380,0,20,300);
    escena->addItem(bordeD);
    bordeD->setBrush(Qt::lightGray);

    bordeD=new QGraphicsRectItem(300,40,20,180);
    escena->addItem(bordeD);
    bordeD->setBrush(Qt::lightGray);

    bordeS=new QGraphicsRectItem(0,0,380,20);
    escena->addItem(bordeS);
    bordeS->setBrush(Qt::lightGray);

    bordeIn=new QGraphicsRectItem(0,280,380,20);
    escena->addItem(bordeIn);
    bordeIn->setBrush(Qt::lightGray);

    borde1=new QGraphicsRectItem(40,0,20,140);
    escena->addItem(borde1);
    borde1->setBrush(Qt::lightGray);

    borde1=new QGraphicsRectItem(340,0,20,140);
    escena->addItem(borde1);
    borde1->setBrush(Qt::lightGray);

    borde2=new QGraphicsRectItem(40,160,20,120);
    escena->addItem(borde2);
    borde2->setBrush(Qt::lightGray);

    borde2=new QGraphicsRectItem(340,160,20,120);
    escena->addItem(borde2);
    borde2->setBrush(Qt::lightGray);

    borde3=new QGraphicsRectItem(80,160,100,20);
    escena->addItem(borde3);
    borde3->setBrush(Qt::lightGray);

    borde3=new QGraphicsRectItem(200,160,80,20);
    escena->addItem(borde3);
    borde3->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(80,40,20,140);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(80,160,20,80);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(80,260,20,20);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(120,80,20,60);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(260,80,20,60);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(120,240,200,20);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(120,200,200,20);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde5=new QGraphicsRectItem(100,40,100,20);
    escena->addItem(borde5);
    borde5->setBrush(Qt::lightGray);

    borde5=new QGraphicsRectItem(220,40,100,20);
    escena->addItem(borde5);
    borde5->setBrush(Qt::lightGray);


    pac=new QGraphicsRectItem(-10,-10,20,20);
    escena->addItem(pac);
    pac->setBrush(Qt::yellow);
    pac->setPos(200,100);

    l1=new QGraphicsLineItem(0,0,400,0);
    l2=new QGraphicsLineItem(0,0,0,300);
    l3=new QGraphicsLineItem(400,0,400,300);
    l4=new QGraphicsLineItem(0,300,400,300);
    escena->addItem(l1);
    escena->addItem(l2);
    escena->addItem(l3);
    escena->addItem(l4);

    bola1 = new miesfera();
    escena->addItem(bola1);
    bola1->setPos(35,35);

    bola5 = new miesfera();
    escena->addItem(bola5);
    bola5->setPos(80,35);

    bola6 = new miesfera();
    escena->addItem(bola6);
    bola6->setPos(150,35);

    bola7 = new miesfera();
    escena->addItem(bola7);
    bola7->setPos(250,35);

    bola8 = new miesfera();
    escena->addItem(bola8);
    bola8->setPos(330,35);

    bola2 = new miesfera();
    escena->addItem(bola2);
    bola2->setPos(35,100);

    bola3 = new miesfera();
    escena->addItem(bola3);
    bola3->setPos(35,150);

    bola4 = new miesfera();
    escena->addItem(bola4);
    bola4->setPos(35,250);

}

MainWindow::~MainWindow()
{
    delete escena;
    delete ui;
}

void MainWindow::animar(){

    if(moverIx1 && pac->x()>30 ){
        //pac->setPos(pac->x()-2,pac->y());
        if(moverIx1 && (pac->x()>70 || pac->y()>145) && (pac->x()>70 || pac->y()<150)){
            //if(  ){
                pac->setPos(pac->x()-2,pac->y());
            //}
            //else {

            //}
        }
    }
    if(moverDx1 && pac->x()<370){
        pac->setPos(pac->x()+2,pac->y());
    }
    if(moverUy1 && pac->y()>30){
        pac->setPos(pac->x(),pac->y()-2);
    }
    if(moverDy1 && pac->y()<270){
        pac->setPos(pac->x(),pac->y()+2);
    }
    if(pac->collidesWithItem(l2) || pac->collidesWithItem(l3)){
        moverIx1=false;
        /*if(bola->isVisible()){
            bola->hide();
            //delete bola;
        }*/
    }
    if(pac->collidesWithItem(bola1)){
        if(bola1->isVisible()){
            bola1->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola2)){
        if(bola2->isVisible()){
            bola2->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola3)){
        if(bola3->isVisible()){
            bola3->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola4)){
        if(bola4->isVisible()){
            bola4->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola5)){
        if(bola5->isVisible()){
            bola5->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola6)){
        if(bola6->isVisible()){
            bola6->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola7)){
        if(bola7->isVisible()){
            bola7->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola8)){
        if(bola8->isVisible()){
            bola8->hide();
            emit aviso(9);
            //delete bola;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev){

    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev){

    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=false;
    }
}

void MainWindow::aumentarPuntos(){
    puntuacion += 10;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}










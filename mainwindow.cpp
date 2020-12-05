#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QString val;

    val += "\n\nBienvenido, Presentamos la practica de labortario numero";
    val += "\ncinco (5), como estudiantes del curso de informatica II";
    val += "\nsomos:";
    val += "\n\n Andres Felipe Giraldo Yusti";
    val += "\n\n Juan Alejandro Gualteros Fonseca";
    val += "\n\n\nGracias por Jugar :D";
    val += "\n\n\n\nSi tienes dudas de los controles o demas, puesde dirigirte a la";
    val += "\nla basrra de herrameintas, en el apartado de Acerca de";
    QMessageBox::about (this,"Welcome to GAME :D" , val);

    timerE = new QTimer();



}

void MainWindow::keyPressEvent(QKeyEvent *evento){

    if(evento->key() == Qt::Key_A || evento->key() == Qt::Key_J){
        personaje->left();
        for (int i = 0;i < monedas.size();i++) {
                    if(personaje->collidesWithItem(monedas.at(i))){
                        scene->removeItem(monedas.at(i));
                        monedas.removeAt(i);
                        puntajes = puntajes+50;
                        ui->puntaje->setText((QString::number(puntajes)));
                    }
                }
        for (int i = 0;i < muros.size();i++) {
                    if(personaje->collidesWithItem(muros.at(i))){
                        personaje->right();
                    }
        }
        if (num == 1 && puntajes == 5750){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L2_clicked();
        }
        else if (num == 2 && puntajes == 5600){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L3_clicked();
        }
        else if (num == 3 && puntajes == 5350){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L1_clicked();
        }
    }

    if(evento->key() == Qt::Key_D || evento->key() == Qt::Key_L){
        personaje->right();
        for (int i = 0;i < monedas.size();i++) {
                    if(personaje->collidesWithItem(monedas.at(i))){
                        scene->removeItem(monedas.at(i));
                        monedas.removeAt(i);
                        puntajes=puntajes+50;
                        ui->puntaje->setText((QString::number(puntajes)));
                    }
                }
        for (int i = 0;i < muros.size();i++){
            if(personaje->collidesWithItem(muros.at(i))){
                personaje->left();
            }
        }
        if (num == 1 && puntajes == 5750){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L2_clicked();
        }
        else if (num == 2 && puntajes == 5750){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L3_clicked();
        }
        else if (num == 3 && puntajes == 5350){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L1_clicked();
        }
    }

    if(evento->key() == Qt::Key_W || evento->key() == Qt::Key_I){
        personaje->up();
        for (int i = 0;i < monedas.size();i++) {
                   if(personaje->collidesWithItem(monedas.at(i))){
                       scene->removeItem(monedas.at(i));
                       monedas.removeAt(i);
                       puntajes=puntajes+50;
                       ui->puntaje->setText((QString::number(puntajes)));
                   }
               }
        for (int i = 0;i < muros.size();i++){
            if(personaje->collidesWithItem(muros.at(i))){
                personaje->down();
            }
        }
        if (num == 1 && puntajes == 5750){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L2_clicked();
        }
        else if (num == 2 && puntajes == 5750){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L3_clicked();
        }
        else if (num == 3 && puntajes == 5350){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L1_clicked();
        }
    }

    if(evento->key() == Qt::Key_S || evento->key() == Qt::Key_K){
        personaje->down();
        for (int i = 0;i < monedas.size();i++) {
                   if(personaje->collidesWithItem(monedas.at(i))){
                       scene->removeItem(monedas.at(i));
                       monedas.removeAt(i);
                       puntajes=puntajes+50;
                       ui->puntaje->setText((QString::number(puntajes)));
                   }
               }
        for (int i = 0;i < muros.size();i++){
            if(personaje->collidesWithItem(muros.at(i))){
                personaje->up();
            }
        }
        if (num == 1 && puntajes == 5750){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L2_clicked();
        }
        else if (num == 2 && puntajes == 5750){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L3_clicked();
        }
        else if (num == 3 && puntajes == 5350){
            timerE->stop();
            QMessageBox::about (this,"PACMAN" , "\n\n GANASTE :D");
            on_L1_clicked();
        }
    }
}

//Movimiento enemigo
void MainWindow::movimiento_enemigo(){

    if (malos->x() < personaje->x()){
        malos->right();
        for (int i = 0;i < muros.size();i++) {
            if(malos->collidesWithItem(muros.at(i))){
                malos->left();
            }
        }
        if (malos->collidesWithItem(personaje)){
            QMessageBox::about (this,"PACMAN" , "\n\n HAS PERDIDO  :'(");
            if (num == 1){
                on_L1_clicked();
            }
            else if (num == 2){
                on_L2_clicked();
            }
            else if (num == 3){
                on_L3_clicked();
            }
        }
    }
    else if (malos->x() > personaje->x()){
        malos->left();
        for (int i = 0;i < muros.size();i++) {
            if(malos->collidesWithItem(muros.at(i))){
                malos->right();
            }
        }
        if (malos->collidesWithItem(personaje)){
            QMessageBox::about (this,"PACMAN" , "\n\n HAS PERDIDO  :'(");
            if (num == 1){
                on_L1_clicked();
            }
            else if (num == 2){
                on_L2_clicked();
            }
            else if (num == 3){
                on_L3_clicked();
            }
        }
    }
    if (malos->y() < personaje->y()){
        malos->down();
        for (int i = 0;i < muros.size();i++) {
            if(malos->collidesWithItem(muros.at(i))){
                malos->up();
            }
        }
        if (malos->collidesWithItem(personaje)){
            QMessageBox::about (this,"PACMAN" , "\n\n HAS PERDIDO  :'(");
            if (num == 1){
                on_L1_clicked();
            }
            else if (num == 2){
                on_L2_clicked();
            }
            else if (num == 3){
                on_L3_clicked();
            }
        }
    }
    else if (malos->y() > personaje->y()){
        malos->up();
        for (int i = 0;i < muros.size();i++) {
            if(malos->collidesWithItem(muros.at(i))){
                malos->down();
            }
        }
        if (malos->collidesWithItem(personaje)){
            QMessageBox::about (this,"Welcome to GAME :D" , "\n\n HAS PERDIDO  :'(");
            if (num == 1){
                on_L1_clicked();
            }
            else if (num == 2){
                on_L2_clicked();
            }
            else if (num == 3){
                on_L3_clicked();
            }
        }
    }
//    malos->setPos(malos->posx,malos->posy);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_L1_clicked()
{
    timerE->deleteLater();
    muros.clear();
    monedas.clear();
    puntajes = 0;
    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho = 1100; //desktop.width();
    alto = 550; //desktop.height();

    scene = new QGraphicsScene(x, y, ancho, alto);

    //scene->setBackgroundBrush(QPixmap(":/imagenes/mapa pacman prueba.png"));
    ui->graphicsView->setScene(scene);
    ui->puntaje->setText(QString::number(puntajes));

    //Creacion de monedadas
    for (int i = 125; i < 1100 ; i+= 50){
        monedas.push_back(new moneda(10,i,75));scene->addItem(monedas.back());
    }

    for (int a = 125; a < 550 ; a+= 50){

        for (int i = 25; i < 1100 ; i+= 50){
            monedas.push_back(new moneda(10,i,a));scene->addItem(monedas.back());
        }
    }

    //definicion de muros del mapa
    //Esterior
    // (ancho,largo) (x,y)
    muros.push_back(new pared(50, 550, 0, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 550, 1050, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(1000, 50, 50, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(1000, 50, 50, 500)); scene->addItem(muros.back());

    //interior
    muros.push_back(new pared(50, 150, 100, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 150, 100, 300)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 50, 150, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 150, 400)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 100, 250, 50)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 250, 400)); scene->addItem(muros.back());

    muros.push_back(new pared(100, 50, 200, 200)); scene->addItem(muros.back());
    muros.push_back(new pared(100, 50, 200, 300)); scene->addItem(muros.back());

    muros.push_back(new pared(400, 50, 350, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(400, 50, 350, 400)); scene->addItem(muros.back());

    muros.push_back(new pared(250, 50, 400, 300)); scene->addItem(muros.back());
    muros.push_back(new pared(250, 50, 450, 200)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 150, 350, 200)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 150, 700, 200)); scene->addItem(muros.back());

    //__________________________________________________________________________

    muros.push_back(new pared(50, 150, 950, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 150, 950, 300)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 50, 900, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 900, 400)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 100, 800, 50)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 800, 400)); scene->addItem(muros.back());

    muros.push_back(new pared(100, 50, 800, 200)); scene->addItem(muros.back());
    muros.push_back(new pared(100, 50, 800, 300)); scene->addItem(muros.back());

    personaje = new sprites();

    scene->addItem(personaje);

    personaje->velocidad = ui->nivel->value();

    personaje->setPos(75, 75);

    malos = new enemigo();

    malos->posx = 475;
    malos->posy = 275;

    scene->addItem(malos);

    malos->setPos(475, 275);

    timerE = new QTimer();
    num = 1;
    connect(timerE, SIGNAL(timeout()), this, SLOT(movimiento_enemigo()));
    timerE->start(100);

}

void MainWindow::on_L2_clicked()
{
    timerE->deleteLater();
    muros.clear();
    monedas.clear();
    puntajes = 0;
    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho = 1100; //desktop.width();
    alto = 550; //desktop.height();

    scene = new QGraphicsScene(x, y, ancho, alto);

    //scene->setBackgroundBrush(QPixmap(":/imagenes/mapa pacman prueba.png"));
    ui->graphicsView->setScene(scene);
    ui->puntaje->setText(QString::number(puntajes));

    //Creacion de monedadas
    for (int i = 125; i < 1100 ; i+= 50){
        monedas.push_back(new moneda(10,i,75));scene->addItem(monedas.back());
    }

    for (int a = 125; a < 550 ; a+= 50){

        for (int i = 25; i < 1100 ; i+= 50){
            monedas.push_back(new moneda(10,i,a));scene->addItem(monedas.back());
        }
    }

    //definicion de muros del mapa
    //Esterior
    // (ancho,largo) (x,y)
    muros.push_back(new pared(50, 550, 0, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 550, 1050, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(1000, 50, 50, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(1000, 50, 50, 500)); scene->addItem(muros.back());

    //interior

    muros.push_back(new pared(50, 50, 100, 50)); scene->addItem(muros.back());
    muros.push_back(new pared(100, 50, 100, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(100, 100, 100, 200)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 100, 100, 350)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 150, 400)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 200, 400)); scene->addItem(muros.back());

    muros.push_back(new pared(200, 50, 250, 300)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 300, 400)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 400, 400)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 200, 250, 50)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 300, 50)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 300, 150)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 50, 400, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 500, 50)); scene->addItem(muros.back());
    muros.push_back(new pared(150, 50, 400, 150)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 250, 500, 250)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 50, 600, 50)); scene->addItem(muros.back());
    muros.push_back(new pared(250, 50, 600, 100)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 50, 600, 450)); scene->addItem(muros.back());
    muros.push_back(new pared(250, 50, 600, 400)); scene->addItem(muros.back());

    muros.push_back(new pared(200, 50, 650, 200)); scene->addItem(muros.back());
    muros.push_back(new pared(200, 50, 650, 300)); scene->addItem(muros.back());

    muros.push_back(new pared(50, 350, 950, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 900, 150)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 900, 250)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 50, 900, 350)); scene->addItem(muros.back());


    //__________________________________________________________________________



    personaje = new sprites();

    scene->addItem(personaje);

    personaje->velocidad = ui->nivel->value();

    personaje->setPos(75, 75);

    malos = new enemigo();

    malos->posx = 725;
    malos->posy = 275;

    scene->addItem(malos);

    malos->setPos(725, 275);

    timerE = new QTimer();
    num = 2;
    connect(timerE, SIGNAL(timeout()), this, SLOT(movimiento_enemigo()));
    timerE->start(100);
}

void MainWindow::on_L3_clicked()
{
    timerE->deleteLater();
    muros.clear();
    monedas.clear();
    puntajes = 0;
    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho = 1100; //desktop.width();
    alto = 550; //desktop.height();

    scene = new QGraphicsScene(x, y, ancho, alto);

    //scene->setBackgroundBrush(QPixmap(":/imagenes/mapa pacman prueba.png"));
    ui->graphicsView->setScene(scene);
    ui->puntaje->setText(QString::number(puntajes));

    //Creacion de monedadas
    for (int i = 125; i < 1100 ; i+= 50){
        monedas.push_back(new moneda(10,i,75));scene->addItem(monedas.back());
    }

    for (int a = 125; a < 550 ; a+= 50){

        for (int i = 25; i < 1100 ; i+= 50){
            monedas.push_back(new moneda(10,i,a));scene->addItem(monedas.back());
        }
    }

    //definicion de muros del mapa
    //Esterior
    // (ancho,largo) (x,y)
    muros.push_back(new pared(50, 550, 0, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(50, 550, 1050, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(1000, 50, 50, 0)); scene->addItem(muros.back());
    muros.push_back(new pared(1000, 50, 50, 500)); scene->addItem(muros.back());

    //interior

    muros.push_back(new pared(100, 150, 100, 100 )); scene->addItem(muros.back());
    muros.push_back(new pared(100, 150, 100, 300 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 250, 50 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 150, 250, 200 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 250, 400 )); scene->addItem(muros.back());
    muros.push_back(new pared(400, 50, 350, 100 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 150, 350, 200 )); scene->addItem(muros.back());
    muros.push_back(new pared(400, 50, 350, 400 )); scene->addItem(muros.back());
    muros.push_back(new pared(200, 150, 450, 200 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 150, 700, 200 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 800, 50 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 150, 800, 200 )); scene->addItem(muros.back());
    muros.push_back(new pared(50, 100, 800, 400 )); scene->addItem(muros.back());
    muros.push_back(new pared(100, 150, 900, 100 )); scene->addItem(muros.back());
    muros.push_back(new pared(100, 150, 900, 300 )); scene->addItem(muros.back());


    //__________________________________________________________________________


    personaje = new sprites();

    scene->addItem(personaje);

    personaje->velocidad = ui->nivel->value();

    personaje->setPos(75, 75);

    malos = new enemigo();

    malos->posx = 525;
    malos->posy = 175;

    scene->addItem(malos);

    malos->setPos(525, 175);

    timerE = new QTimer();
    num = 3;
    connect(timerE, SIGNAL(timeout()), this, SLOT(movimiento_enemigo()));
    timerE->start(100);
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QString val;

    val += "\nLos controles del juego son:";
    val += "\n\n           W                  I\n";
    val += "\n      A   S   D           J   K   L\n";
    QMessageBox::about (this,"Acerca de" , val);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    msg.setWindowTitle("Matrices");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//Crear
{
    int filas = ui->txtfila->text().toInt();
    int columnas = ui->txtcolumna->text().toInt();
    if(filas>0 && columnas>0){
        matrices.push_back(Matriz(filas, columnas));
        ui->cmbmatriz->addItem("Matriz ");
        ui->cmbmatriz2->addItem("Matriz ");
        matrices[matrices.size()-1].imprimir();
    }
}

void MainWindow::on_pushButton_2_clicked()//Asignar
{
    int filas = ui->txtfila->text().toInt();
    int columnas = ui->txtcolumna->text().toInt();
    QString valor = ui->txtvalor->text();
    if(filas>=0 && columnas>=0 && valor != ""){
        matrices[ui->cmbmatriz->currentIndex()].asignar(filas, columnas, valor.toInt());
    }
}

void MainWindow::on_pushButton_3_clicked()//Obtener
{
    int filas = ui->txtfila->text().toInt();
    int columnas = ui->txtcolumna->text().toInt();
    if(filas>=0 && columnas>=0){
        Elemento* valor = ((matrices[ui->cmbmatriz->currentIndex()]).obtenerElemento(filas, columnas));
        msg.setText(QString::number(valor->valor));
        msg.exec();
    }
}

void MainWindow::on_pushButton_6_clicked()//Imprimir
{
    matrices[ui->cmbmatriz->currentIndex()].imprimir();
}

void MainWindow::on_pushButton_4_clicked()//SUMAR
{
    matrices[ui->cmbmatriz->currentIndex()].sumar(&matrices[ui->cmbmatriz2->currentIndex()]);
    matrices[ui->cmbmatriz->currentIndex()].imprimir();
}

void MainWindow::on_pushButton_5_clicked()//Producto Scalar
{
    QString valor = ui->txtvalor->text();
    if(valor != ""){
        matrices[ui->cmbmatriz->currentIndex()].productoEscalar(valor.toInt());
    }
}

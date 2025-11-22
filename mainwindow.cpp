#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#define PY_SSIZE_T_CLEAN
#undef slots
#include <pybind11/stl.h>
#include <pybind11/embed.h>
#include <vector>
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <QDir>
#include <QCoreApplication>
#include <string>
#include <sstream>
#include <filesystem>


namespace py = pybind11;

std::vector<std::vector<int>> affictation ;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::app)
{
    ui->setupUi(this);
    connect(ui->run, &QPushButton::clicked, this, &MainWindow::on_run_clicked);
    ui->text->setReadOnly(true);
    this->setCentralWidget(ui->centralwidget);
    ui->stackedWidget->setCurrentIndex(0);
    ui->text->setPlaceholderText("Result will be printed here");
    ui->csv->setPlaceholderText("data imported from csv will be visualled here \n you can edit the data before using it");
    ui->input->setPlaceholderText("the data should be divided to : \n 3,<--clinets number\n2,<--machines number\n1,2<--time limits per machine\n1,3,4\n2,5,6<--tax matrix per client per machine\n1,3,4\n 2,5,6<--time matrix per client per machine");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_run_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    if (MainWindow::p.size() !=0 && MainWindow::c.size() !=0){
        //std::string cpp_path = __FILE__;
        QString exeDir = QCoreApplication::applicationDirPath();
        std::filesystem::path file_path = exeDir.toStdString();

        file_path /= "python";


        py::scoped_interpreter guard{};

        py::module sys = py::module::import("sys");
        sys.attr("path").attr("append")(file_path.string());
        std::cout << "Python path: " << file_path.string() << std::endl;

        py::module H1 = py::module::import("H1");

        if(ui->hur->currentText() == "Huristic 1"){
            H1 = py::module::import("H1");
        }
        else if(ui->hur->currentText() == "Huristic 2"){
            H1 = py::module::import("H2");
        }
        else if(ui->hur->currentText() == "Huristic 3"){
            H1 = py::module::import("H3");

        }
        else if(ui->hur->currentText() == "Huristic 4"){
            H1 = py::module::import("H4");
        }

        affictation=H1.attr("main")(MainWindow::tm,MainWindow::p,MainWindow::c,MainWindow::m,MainWindow::n).cast<std::vector<std::vector<int>>>();
        if (affictation == std::vector<std::vector<int>>{{0, 0},{0, 0}}){
            ui->text->setText("No Result");
        }
        else{
            QString st = ui->hur->currentText();
            ui->text->setText("Result from algorithme "+st+ " :");
            for (auto x : affictation) {
                std::cout << x[0] << " , " <<x[1] << " " <<std::endl;
                ui->text->append("("+QString::number(x[0]) + "," + QString::number(x[1]) + ")");
            }
        }
    }
    else{
        QMessageBox::warning(this,"Warning","there is no data yet imported \n please press the \'Fill Data botton\'  \n and import data");
    }
}




void MainWindow::on_fill_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tabWidget->setCurrentIndex(0);

}



void MainWindow::on_pushButton_clicked()
{
    MainWindow::allText.clear();
    QString filename = QFileDialog::getOpenFileName(this,"Open CSV File", "", "CSV Files (*.csv);;All Files (*)");
    std::ifstream file(filename.toStdString());
        if (!file.is_open()) return;
        std::string data;
        std::string line;
        while (std::getline(file, line)) {
            MainWindow::allText += QString::fromStdString(line) + "\n";
            data += line;
        }

        std::stringstream ss(data);

        std::string token;

        std::getline(ss, token, ',');
        int first = std::stoi(token);

        std::getline(ss, token, ',');
        int second = std::stoi(token);

        MainWindow::n = second;

        MainWindow::m = first;
        int x;
        std::vector<int> temp_v;
        for (int i = 0; i <n ; ++i) {
            std::getline(ss,token,',');
            x = std::stoi(token);
            MainWindow::tm.push_back(x);

        }

        for (int i = 0; i <n ; ++i) {
            for (int j = 0; j<m ; ++j) {
                std::getline(ss,token,',');
                x = std::stoi(token);
                temp_v.push_back(x);
            }
            MainWindow::c.push_back(temp_v);
            temp_v.clear();
        }


        for (int i = 0; i <n ; ++i) {
            for (int j = 0; j <m ; ++j) {
                std::getline(ss,token,',');
                x = std::stoi(token);
                temp_v.push_back(x);
            }
            MainWindow::p.push_back(temp_v);
            temp_v.clear();

        }



        ui->csv->setText(MainWindow::allText);

}


void MainWindow::on_pushButton_2_clicked()
{
    QString F =ui->csv->toPlainText();
    if(MainWindow::p.size() ==0 && MainWindow::c.size() == 0){
        QMessageBox::warning(this,"Warning","no data is Filled yet");
    }
    else if (F!=MainWindow::allText){
        std::string t= F.toStdString();
        std::stringstream ss(t);

        std::string token;

        std::getline(ss, token, ',');
        int first = std::stoi(token);

        std::getline(ss, token, ',');
        int second = std::stoi(token);

        MainWindow::n = second;

        MainWindow::m = first;
        int x;
        std::vector<int> temp_v;
        for (int i = 0; i <n ; ++i) {
            std::getline(ss,token,',');
            x = std::stoi(token);
            MainWindow::tm.push_back(x);

        }

        for (int i = 0; i <n ; ++i) {
            for (int j = 0; j<m ; ++j) {
                std::getline(ss,token,',');
                x = std::stoi(token);
                temp_v.push_back(x);
            }
            MainWindow::c.push_back(temp_v);
            temp_v.clear();
        }


        for (int i = 0; i <n ; ++i) {
            for (int j = 0; j <m ; ++j) {
                std::getline(ss,token,',');
                x = std::stoi(token);
                temp_v.push_back(x);
            }
            MainWindow::p.push_back(temp_v);
            temp_v.clear();

        }

        QMessageBox::information(this,"Sucses","your Data is Updated");
    }

    else{
        QMessageBox::information(this,"Sucsess","Data imported Sucessfully");
    }
}


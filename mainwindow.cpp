#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
      double numbers;
      QString new_label;
      numbers = (ui->result_show->text()+ button->text()).toDouble();
      new_label = QString::number(numbers,'g',15);
      ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::operations()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
      double numbers;
      QString new_label;

      if(button->text() == "+/-"){
          numbers = (ui->result_show->text()).toDouble();
          numbers *= -1;
          new_label = QString::number(numbers,'g',15);
          ui->result_show->setText(new_label);
      }else if(button->text() == "%"){
          numbers = (ui->result_show->text()).toDouble();
          numbers *= 0.01;
          new_label = QString::number(numbers,'g',15);
          ui->result_show->setText(new_label);
      }
}

void MainWindow::math_operations()
{
    QPushButton *button = static_cast<QPushButton*>(sender());

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");

    button->setChecked(true);
}
void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setCheckable(false);
    ui->pushButton_minus->setCheckable(false);
    ui->pushButton_divide->setCheckable(false);
    ui->pushButton_multiply->setCheckable(false);

    ui->result_show->setText("0");
}
void MainWindow::on_pushButton_result_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();
    if(ui->pushButton_plus->isChecked()){
        labelNumber = num_first + num_second;
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_minus->isChecked()){
        labelNumber = num_first - num_second;
        ui->pushButton_minus->setChecked(false);
    }else if(ui->pushButton_divide->isChecked()){
        if(num_second == 0){
            ui->result_show->setText("0");
        }else{
        labelNumber = num_first / num_second;
        ui->pushButton_divide->setChecked(false);
        }
    }else if(ui->pushButton_multiply->isChecked()){
        labelNumber = num_first * num_second;
        ui->pushButton_multiply->setChecked(false);
    }
    new_label = QString::number(labelNumber,'g',15);
    ui->result_show->setText(new_label);
}

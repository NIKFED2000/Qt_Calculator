#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_noll, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plusandminus, SIGNAL(clicked()), this, SLOT(Operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(Operations()));
    connect(ui->pushButton_devide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    //connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(Operations()));

    ui->pushButton_devide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    double all_numbers;
    if (ui->label->text().contains(".") && button->text() == "0")
        new_label = ui->label->text() + button->text();
    else
    {
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->label->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->label->text().contains('.'))
        ui->label->setText(ui->label->text() + ".");
}
void MainWindow::Operations()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    double all_numbers;
    if(button->text() == "+/-")
    {
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);


        ui->label->setText(new_label);
    }
    else if(button->text() == "%")
    {
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);


        ui->label->setText(new_label);
    }

}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    num_first = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);

}
void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->label->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_devide->isChecked())
    {
        if (num_second == 0)
            ui->label->setText("0");
        else
        {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);
            ui->label->setText(new_label);
            ui->pushButton_devide->setChecked(false);
        }
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->label->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->label->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    }
}

void MainWindow::on_pushButton_cancel_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_devide->setChecked(false);
    ui->label->setText("0");
}

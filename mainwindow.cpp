#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <io.h>   // For access().
#include <sys/types.h>  // For stat().
#include <sys/stat.h>   // For stat().
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (data.IsDataEmpty())
    {
        std::string RunUATPATHData;
        std::string ProjectPATHData;

        RunUATPATHData = data.GetRunUATPATH();
        ProjectPATHData = data.GetProjectPATH();

        if (RunUATPATHData.empty() || ProjectPATHData.empty())
        {
            ui->PS4Button->setEnabled(false);
            ui->WindowsButton->setEnabled(false);
            ui->XboxButton->setEnabled(false);
            ui->NeedCookCheckBox->setEnabled(false);
        }
        else
        {
            if (!RunUATPATHData.empty())
            {
                ui->RunUATLineEdit->setText(QString::fromStdString(RunUATPATHData));
            }

            if (!ProjectPATHData.empty())
            {
                ui->ProjectPathLineEdit->setText(QString::fromStdString(ProjectPATHData));
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (!ui->RunUATLineEdit->text().isEmpty())
    {
        data.SetRunUATPATH(ui->RunUATLineEdit->text().toStdString());
    }

    if (!ui->ProjectPathLineEdit->text().isEmpty())
    {
        data.SetProjectPATH(ui->ProjectPathLineEdit->text().toStdString());
    }

    if (!data.GetRunUATPATH().empty() && !data.GetProjectPATH().empty())
    {
        ui->PS4Button->setEnabled(true);
        ui->WindowsButton->setEnabled(true);
        ui->XboxButton->setEnabled(true);
        ui->NeedCookCheckBox->setEnabled(true);
        std::cout << "333\n";
    }
}


void MainWindow::on_WindowsButton_clicked()
{
    std::string command;
    std::string SystemCommand = "start powershell.exe -Command ";
    command += data.GetRunUATPATH();
    command += " BuildCookRun -skipcompile -compileeditor -project=";
    command += data.GetProjectPATH();

    if (ui->NeedCookCheckBox->isChecked())
    {
        command += " -cook ";
    }
    else
    {
        command += " -skipcook ";
    }

    command += "-stage -archive  -package -clientconfig=Development -pak -compressed -targetplatform=Win64 -build -utf8output -compile";

    SystemCommand += command;
    system(&SystemCommand[0]);
}


void MainWindow::on_PS4Button_clicked()
{
    std::string command;
    std::string SystemCommand = "start powershell.exe -Command ";
    command += data.GetRunUATPATH();
    command += " BuildCookRun -skipcompile -compileeditor -project=";
    command += data.GetProjectPATH();

    if (ui->NeedCookCheckBox->isChecked())
    {
        command += " -cook ";
    }
    else
    {
        command += " -skipcook ";
    }

    command += "-stage -archive  -package -clientconfig=Development -pak -compressed -targetplatform=PS4 -build -utf8output -compile";

    SystemCommand += command;
    system(&SystemCommand[0]);
}


void MainWindow::on_XboxButton_clicked()
{
    std::string command;
    std::string SystemCommand = "start powershell.exe -Command ";
    command += data.GetRunUATPATH();
    command += " BuildCookRun -skipcompile -compileeditor -project=";
    command += data.GetProjectPATH();

    if (ui->NeedCookCheckBox->isChecked())
    {
        command += " -cook ";
    }
    else
    {
        command += " -skipcook ";
    }

    command += "-stage -archive  -package -clientconfig=Development -pak -compressed -targetplatform=XboxOneGDK -build -utf8output -compile";

    SystemCommand += command;
    system(&SystemCommand[0]);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonFindPasswords_clicked()
{
    int tempChancePower = ui->textEditChance->toPlainText().toInt();
    int tempSpeed = ui->textEditSpeed->toPlainText().toInt();
    int tempValidity = ui->textEditValidity->toPlainText().toInt();
    int tempCountPasswords = ui->textEditCountPassword->toPlainText().toInt();

    findPasswords(tempChancePower, tempSpeed, tempValidity, tempCountPasswords);
}

void MainWindow::findPasswords(const int &inputChancePower, const int &inputSpeed, const int &inputValidity, const int &inputCountPassword)
{
    for(int i = 0; i < inputCountPassword; i++)
    {
        EvaluatorChance *calculatedData = new EvaluatorChance(inputChancePower, inputSpeed, inputValidity, MIN_STRONG, MIN_LENGTH);
        PasswordGenerator *generatedPassword = new PasswordGenerator(calculatedData->getStrong(), calculatedData->getLength());

        QListWidgetItem *newItem = new QListWidgetItem;
        QString buffer = QString::fromStdString(generatedPassword->getPassword());
        newItem->setText(buffer);

        ui->listWidget->insertItem(0, newItem);

        delete calculatedData;
        delete generatedPassword;
        //delete newItem;
    }
}

void MainWindow::on_action_triggered()
{
    QMessageBox *helpBox = new QMessageBox(this);

    helpBox->setGeometry(this->geometry().x(), this->geometry().y(), 250, 120);

    helpBox->setWindowTitle("Окно помощи");
    helpBox->setText("Генератор паролей");
    helpBox->setInformativeText("Необходимо внести данные в поля. "
                                "При этом вводятся:\n\n "
                                "\t1) Степень вероятности умноженная на -1;\n "
                                "\t2) Скорость перебора в единицах паролей в час;\n "
                                "\t3) Срок действия пароля в днях.\n\n"
                                "Алгоритм ищет число максимально близкое к нужному значению A^(L) >= *S, "
                                "где S = (V * T)/P. При этом инкрементируется сначала мощность пароля (A) до тех пор, "
                                "пока меньше или равна 61, затем инкрементируется длина пароля, "
                                "при этом сбрасывается сила в минимальное значение 26");

    helpBox->setWindowModality(Qt::WindowModal);
    helpBox->show();

    helpBox->exec();
}

void MainWindow::on_pushButtonClearListView_clicked()
{
    ui->textEditChance->clear();
    ui->textEditSpeed->clear();
    ui->textEditValidity->clear();
    ui->textEditCountPassword->clear();
    ui->listWidget->clear();
}

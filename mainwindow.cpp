#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filereader.h"
#include "qtscenedrawer.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), graphicsScene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(graphicsScene);

    auto reader = std::make_unique<FileReader>();
    auto drawer = std::make_unique<QtSceneDrawer>(graphicsScene);
    facade = std::make_unique<Facade>(std::move(reader), std::move(drawer));

    setupConnections();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupConnections() {
    connect(ui->filePushButton, &QPushButton::clicked, this, &MainWindow::onFileButtonClicked);
    connect(ui->rotateXPlusButton, &QPushButton::clicked,this, &MainWindow::onRotateXPlusClicked);
    connect(ui->rotateXMinusButton, &QPushButton::clicked,this, &MainWindow::onRotateXMinusClicked);
    connect(ui->rotateYPlusButton, &QPushButton::clicked,this, &MainWindow::onRotateYPlusClicked);
    connect(ui->rotateYMinusButton, &QPushButton::clicked,this, &MainWindow::onRotateYMinusClicked);
    connect(ui->rotateZPlusButton, &QPushButton::clicked,this, &MainWindow::onRotateZPlusClicked);
    connect(ui->rotateZMinusButton, &QPushButton::clicked,this, &MainWindow::onRotateZMinusClicked);
    connect(ui->uploadPushButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClicked);
    connect(ui->zoomInButton, &QPushButton::clicked, this, &MainWindow::onZoomInClicked);
    connect(ui->zoomOutButton, &QPushButton::clicked, this, &MainWindow::onZoomOutClicked);
    connect(ui->translateXPlusButton, &QPushButton::clicked, this, &MainWindow::onTranslateXPlusClicked);
    connect(ui->translateXMinusButton, &QPushButton::clicked, this, &MainWindow::onTranslateXMinusClicked);
    connect(ui->translateYPlusButton, &QPushButton::clicked, this, &MainWindow::onTranslateYPlusClicked);
    connect(ui->translateYMinusButton, &QPushButton::clicked, this, &MainWindow::onTranslateYMinusClicked);
    connect(ui->translateZPlusButton, &QPushButton::clicked, this, &MainWindow::onTranslateZPlusClicked);
    connect(ui->translateZMinusButton, &QPushButton::clicked, this, &MainWindow::onTranslateZMinusClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::onExitButtonClicked);
}

void MainWindow::onFileButtonClicked() {

    if(ui->pathLabel->text().isEmpty())
        ui->pathLabel->clear();
    QString filePath = QFileDialog::getOpenFileName(this, "Open CSV File", "D:/labsFiles/2semester/OOP/OOP_lab4/files4labs", "CSV Files (*.csv)");
    if (filePath.isEmpty()) return;
    ui->pathLabel->setText(filePath);
}

void MainWindow::onLoadButtonClicked() {
    NormalizationParameters params{ui->normBSpinBox->value(), ui->normASpinBox->value(),ui->stepSpinBox->value()};
    std::filesystem::path path = ui->pathLabel->text().toStdString();

    auto result = facade->LoadScene(path, params);

    if (result.isSuccess() ) {
        drawScene();
        QMessageBox::information(this, "Успех", result.getMessage().c_str());
    }
    else {
        QMessageBox::critical(this, "Ошибка", result.getMessage().c_str());
    }
}

void MainWindow::drawScene() {
    clearScene();
    facade->DrawScene();
}

void MainWindow::clearScene() {
    graphicsScene->clear();
}

void MainWindow::onRotateXPlusClicked(){
    auto result = facade->RotateScene(Constants::UNIT_OF_ROTATION, Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onRotateXMinusClicked() {
    auto result = facade->RotateScene(-Constants::UNIT_OF_ROTATION, Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onRotateYPlusClicked() {
    auto result = facade->RotateScene(Constants::DEFAULT_VALUE, Constants::UNIT_OF_ROTATION, Constants::DEFAULT_VALUE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}
void MainWindow::onRotateYMinusClicked() {
    auto result = facade->RotateScene(Constants::DEFAULT_VALUE, -Constants::UNIT_OF_ROTATION, Constants::DEFAULT_VALUE);

    if(result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onRotateZPlusClicked() {
    auto result = facade->RotateScene(Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE, Constants::UNIT_OF_ROTATION);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onRotateZMinusClicked() {
    auto result = facade->RotateScene(Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE, -Constants::UNIT_OF_ROTATION);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onTranslateXPlusClicked() {
    auto result = facade->MoveScene(Constants::UNIT_OF_TRANSLATE, Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onTranslateXMinusClicked() {
    auto result = facade->MoveScene(-Constants::UNIT_OF_TRANSLATE, Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка",result.getMessage().c_str());
}

void MainWindow::onTranslateYPlusClicked() {
    auto result = facade->MoveScene(Constants::DEFAULT_VALUE, Constants::UNIT_OF_TRANSLATE, Constants::DEFAULT_VALUE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onTranslateYMinusClicked() {
    auto result = facade->MoveScene(Constants::DEFAULT_VALUE, -Constants::UNIT_OF_TRANSLATE, Constants::DEFAULT_VALUE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());

}

void MainWindow::onTranslateZPlusClicked() {
    auto result = facade->MoveScene(Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE, Constants::UNIT_OF_TRANSLATE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onTranslateZMinusClicked() {
    auto result = facade->MoveScene(Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE, -Constants::UNIT_OF_TRANSLATE);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onZoomInClicked() {
    auto result = facade->ScaleScene(Constants::COEFFICIENT_ZOMM_IN,Constants::COEFFICIENT_ZOMM_IN,Constants::COEFFICIENT_ZOMM_IN);

    if (result.isSuccess())
        drawScene();
    else
        QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onZoomOutClicked() {
    auto result = facade->ScaleScene(Constants::COEFFICIENT_ZOMM_OUT,Constants::COEFFICIENT_ZOMM_OUT,Constants::COEFFICIENT_ZOMM_OUT);

    if (result.isSuccess())
        drawScene();
    else QMessageBox::warning(this, "Ошибка", result.getMessage().c_str());
}

void MainWindow::onExitButtonClicked() {
    if(graphicsScene)
        graphicsScene->clear();
    qApp->exit();
}


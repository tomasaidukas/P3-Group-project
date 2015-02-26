#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

//user-defined header files
#include "numerical.h"
#include "mesh.h"
#include "topalg.h"
#include "CImg.h"

QString fname;

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

// Loads and stores an image file
void MainWindow::on_toolButtonLoad_clicked()
{
    fname = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Image Files (*.png *.jpg *.bmp)"));
    ui->toolButtonLoad->setText( QFileInfo(fname).fileName() );
}

// Makes a Pixmap of a plot
QPixmap plotPix(const char *plot)
{
    QImage *qImg;
    QPixmap pixma;

    qImg = new QImage();
    if(!(qImg->load( plot )))
        qWarning("ERROR");

    return pixma = QPixmap::fromImage(*qImg);
}

// When 'run' button is clicked, run the algorithm
void MainWindow::on_pushButtonRun_clicked()
{
        system("./run.sh &");

    // Disable button while process is running
        ui->pushButtonRun->setEnabled(false);

    // Convert filname from QString to string
        QByteArray ba = fname.toLocal8Bit();
        const char *filename = ba.data();

    // Load the mesh
        Numerical numerical( ui->doubleSpinBoxTolerance->value(), ui->doubleSpinBoxVoltageUp->value(), ui->doubleSpinBoxVoltageGround->value(),
                             ui->doubleSpinBoxVoltageLow->value(), filename, ui->spinBoxScale->value() );
    //(tolerance, potential for RED, potential for GREEN, potential for BLUE, image name, scale)

    // Find the numerical solution
        numerical.runAlgorithm();
        numerical.printGNUPLOT(3);
        numerical.printROOT(3, 5);

    // Analysis of iterations and time
        ui->labelIteration->setText( "Number of Iterations: "+QString::number(numerical.getIter()) );
        ui->labelTime->setText( "Algorithm ran for "+QString::number(numerical.getTime())+" seconds" );

    // Plot the results
        system("./Plot");

    //Display the plotted results
        QPixmap vplot = plotPix("Plots/Vnumerical.png");
        ui->plotV->setPixmap(vplot);
        ui->plotV->setScaledContents(true);

        QPixmap eplot = plotPix("Plots/Enumerical.png");
        ui->plotE->setPixmap(eplot);
        ui->plotE->setScaledContents(true);

    // Re-enable button when process is finished
        ui->pushButtonRun->setEnabled(true);
}

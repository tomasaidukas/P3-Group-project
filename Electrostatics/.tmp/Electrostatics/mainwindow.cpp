#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numerical.cpp"

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


// When 'run' button is clicked, run the algorithm
void MainWindow::on_pushButtonRun_clicked()
{
    // Convert filname from QString to string
        QByteArray ba = fname.toLocal8Bit();
        const char *filename = ba.data();

    // Assign voltage
        double V = ui->doubleSpinBoxVoltage->value();

    // Input values to the numerical function
        qDebug() << V;
        qDebug() << ui->doubleSpinBoxTolerance->value();

        Numerical numerical( ui->doubleSpinBoxTolerance->value(), V, 0, -V, filename );

    // Find the numerical solution
        numerical.runAlgorithm();
        numerical.printPotential(3);
        numerical.runElectric(3);
        qWarning("Algorithm ran");

    // Test to see if files exist
        QFile numTest("Vnumerical.txt");
        if(!numTest.exists())
            qWarning("ERROR");
        else
            qWarning("Plotted");

    // Plot the results
        system("gnuplot numPlot");

    //Display the plotted results
        QImage *qImg;
        QPixmap pixma;

        qImg = new QImage();
        if(!(qImg->load("Vnumerical.png")))
            qWarning("ERROR");
        pixma = QPixmap::fromImage(*qImg);

        ui->plotV->setPixmap(pixma);
        delete qImg;
}

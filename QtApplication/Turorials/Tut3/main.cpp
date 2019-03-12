/*
    CREATED BY : Matthew Cumber
    STUDENT ID : 201131527
    EMAIL : ll16m23c@leeds.ac.uk

    STYLE:
        lowerCamelcase variables
        UpperCamelcase Methods and ClassNames
        CAPS macros

    CURRENT STATUS:

*/


#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    QLabel *label = new QLabel("Hello World"); // Create label with text hello world
    label-> setWindowTitle("16Cycles");  // Title to label
    label-> resize(400,400); // Initial size 400 x 400
    label-> show(); // Show label
    return app.exec();
}

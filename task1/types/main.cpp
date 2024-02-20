#include <QLabel>
#include <QVBoxLayout>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool b = true;
    char c = 'C';
    short s = 93;
    int i = 42;
    float f = 34.5;
    double f2 = 3.14;
    QString str1 = "Hello Wanda!";


    QString outputText = QString("bool : %1\nchar: %2\nshort: %3\nint : %4\nfloat : %5\ndouble : %6\nstring : %7")
        .arg(b)
        .arg(c)
        .arg(s)
        .arg(i)
        .arg(f)
        .arg(f2)
        .arg(str1);


    QLabel label(outputText);


    QVBoxLayout layout;
    layout.addWidget(&label);


    QWidget mainWindow;
    mainWindow.setLayout(&layout);
    mainWindow.show();

    return a.exec();
}


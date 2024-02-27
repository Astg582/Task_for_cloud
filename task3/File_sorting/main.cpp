#include "mainwindow.h"
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>
#include <functional>
#include <QApplication>
#include <QFileDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>




enum SortingStrategy {
    BubleSort,
    InsertSort,
    SelectSort,
};


QVector<int> readIntArrayFromFile(const QString&);
void buble( QVector<int>& arr);
void insert_S(QVector<int>& arr);
void sel_sort(QVector<int>& arr);



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString filename = QFileDialog::getSaveFileName(nullptr, "Save File", "", "Text Files (*.txt);;All Files (*)");

    if (filename.isEmpty()) {
           qDebug() << "User canceled the file dialog or entered an empty file name.";
           return -1;
     } else {
          qDebug() << "Selected file name: " << filename;
       }


    QVector<int> integers = readIntArrayFromFile(filename);
    if (integers.isEmpty()) {
           qDebug() << "Failed to read integers from the file.";
           return -1;
       }
      qDebug() << "input for file: " << integers;


            QString sortAlgorithm = QInputDialog::getItem(nullptr, "Input", "Select sorting algorithm:", {"Selection Sort", "Insertion Sort"});
             void (*sortFunction)(QVector<int>&) = nullptr;

             if (sortAlgorithm == "Selection Sort") {
                     sortFunction = sel_sort;
                 } else if (sortAlgorithm == "Insertion Sort") {
                     sortFunction = insert_S;
                 }  else if (sortAlgorithm == "Bubble Sort") {
                     sortFunction = buble;
                 } else {

                     qDebug() << "Invalid sorting algorithm choice.";
                     return -1;
                 }

                  sortFunction(integers);
                  qDebug() << "sorted data: " << integers;

                   QFile file(filename);
                   if(file.open(QIODevice::WriteOnly)){
                       QTextStream out(&file);
                       for (int value : integers) {
                              out << value << endl;
                          }
                       file.close();
                   }else {
                   qWarning("could not open file for reading");
                   }
    return a.exec();
}


QVector<int> readIntArrayFromFile(const QString& filename) {
    QVector<int> result;
    QFile inputFile(filename);

    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&inputFile);

        while (!in.atEnd()) {

            QString line = in.readLine();
            bool ok;
            int number = line.toInt(&ok);

            if (ok) {
                result.append(number);
            } else {
                qWarning() << "Failed to convert" << line << "to integer.";
            }
        }

        inputFile.close();
    } else {

        qWarning() << "Unable to open file:" << filename;
    }

    return result;
}


void sel_sort(QVector<int>& arr)
{
    int s = arr.size();
    for(int i = 0; i < s - 1; ++i)
    {

        int in2 = i;

        for(int j = i + 1; j < s; ++j)
        {
            if(arr[j] < arr[in2])
            {
                in2 = j;
            }
        }
        if(in2 != i)
        {
            std::swap(arr[i], arr[in2]);
        }
    }
}

void insert_S(QVector<int>& arr)
{
    int s = arr.size();
    int key = 0;
    int j = 0;
    for(int i = 1; i < s; ++i){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void buble( QVector<int>& arr)
{

    int s2 = arr.size();

    for(int i = 0; i < s2-1; ++i)
    {
        for(int j = 0; j < s2 - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        --s2;
    }
}

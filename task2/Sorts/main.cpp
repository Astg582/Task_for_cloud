#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QInputDialog>
#include <QStringList>
#include <QDebug>
#include <QVBoxLayout>
#include <algorithm>
#include <climits>

void sel_sort(int*, int);
void insert_S(int*, int);

void (*s)(int*, int) = sel_sort;
void  (*i)(int*, int) = insert_S;
void displayArray(int*, int);


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    bool ok;
   int size = QInputDialog::getInt(nullptr, "Input", "Enter the size of the array:", 0, 0, INT_MAX, 1, &ok);

   if (!ok) {
          // The user pressed Cancel, handle accordingly
          return 0;
      }

    int* arr = new int[size];

    QString inputText = QInputDialog::getText(nullptr, "Input", "Enter space-separated elements:");

      // Parse the input and fill the array
      QStringList inputList = inputText.split(' ');
      for (int i = 0; i < size; ++i) {
          arr[i] = inputList.value(i).toInt();
      }

      QString sortAlgorithm = QInputDialog::getItem(nullptr, "Input", "Select sorting algorithm:", {"Selection Sort", "Insertion Sort"});
       void (*sortFunction)(int*, int) = nullptr;

       if (sortAlgorithm == "Selection Sort") {
               sortFunction = s;
           } else if (sortAlgorithm == "Insertion Sort") {
               sortFunction = i;
           } else {

               qDebug() << "Invalid sorting algorithm choice.";
               delete[] arr;
               return 0;
           }

         sortFunction(arr, size);

          displayArray(arr, size);






    delete[] arr;
    return a.exec();
}

void insert_S(int* arr, int s){
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

void sel_sort(int* arr, int s)
{
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

void displayArray(int* arr, int size) {
    QWidget* arrayWindow = new QWidget;
    QListWidget* listWidget = new QListWidget(arrayWindow);

    for (int i = 0; i < size; ++i) {
        QListWidgetItem* item = new QListWidgetItem(QString::number(arr[i]));
        listWidget->addItem(item);
    }

    QVBoxLayout* layout = new QVBoxLayout(arrayWindow);
    layout->addWidget(listWidget);
    arrayWindow->setLayout(layout);

    arrayWindow->show();
}


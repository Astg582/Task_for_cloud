#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QInputDialog>
#include <QStringList>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <cstring>
#include <iostream>
#include <QtCore/qcoreapplication.h>



int max(int*, const size_t);
int min(int*, const size_t);
int str_len(const char*);
char* com_cat(char*, const char* );
int avr(int*, const size_t);
void displayArray(int*, int);

int main(int argc, char *argv[])
{
       QApplication a(argc, argv);

       QWidget mainWindow;
       QVBoxLayout layout(&mainWindow);




     mainWindow.show();

   bool ok = true;
   size_t size = QInputDialog::getInt(nullptr, "Input", "Enter the size of the array:", 0, 0, INT_MAX, 1, &ok);

   if (!ok) {

          return 0;
      }

    int* arr = new int[size];

    QString inputText = QInputDialog::getText(nullptr, "Input", "Enter space-separated elements:");


      QStringList inputList = inputText.split(' ');
      for (int i = 0; i < size; ++i) {
          arr[i] = inputList.value(i).toInt();
      }
        int max1 = max(arr, size);
        int min1 = min(arr, size);
        int avr1 = avr(arr, size);

        QString labelText = QString("max val in arr: %1\nmin val in arr: %2\naverag in arr : %3")
                  .arg(max1)
                  .arg(min1)
                  .arg(avr1);

                displayArray(arr, size);
                QLabel label(labelText);
                label.show();

                char* strC = qstrdup(QInputDialog::getText(nullptr, "Input", "Enter the first string:", QLineEdit::Normal, "", &ok).toUtf8().constData());

                    if (!ok) {

                        delete[] arr;
                        delete[] strC;
                        return 0;
                    }

                    char* strC1 = qstrdup(QInputDialog::getText(nullptr, "Input", "Enter the first string:", QLineEdit::Normal, "", &ok).toUtf8().constData());

                      if (!ok) {

                          delete[] arr;
                          delete[] strC;
                          delete[] strC1;
                          return 0;
                      }

                      qDebug() << "You entered:";
                      qDebug() << "First string:" << strC;
                      qDebug() << "Second string:" << strC1;
                      strC = com_cat(strC,strC1);
                      qDebug() << "First string new:" << strC;

                      delete [] arr;
                      delete [] strC;
                      delete [] strC1;
    return a.exec();
}

int max(int* arr, const size_t s){
    int m = INT_MIN;
    for(int i = 0; i < s; ++i ){
        if(arr[i] > m){
        m = arr[i];
         }
    }
    return m;
}

int min(int* arr, const size_t s){
    int m = INT_MAX;
    for(int i = 0; i < s; ++i ){
        if(arr[i] < m){
        m = arr[i];
         }
    }
    return m;
}

int avr(int* arr, const size_t s){
    int sum = 0;
    for(int i = 0; i < s; ++i){
        sum += arr[i];
    }
    return sum / s;
}

int str_len(const char* str){
    int i = 0;
    while(str[i] != '\0'){
        ++i;
    }
    return i;
}


char* com_cat(char* str, const char* str1) {
    int l = str_len(str);
    int l1 = str_len(str1);
    char* tmp = new char[l + l1 + 1];
    int i = 0;


    for (i = 0; i < l; ++i) {
        tmp[i] = str[i];
    }


    for (int j = 0; j < l1; ++j, ++i) {
        tmp[i] = str1[j];
    }


    tmp[i] = '\0';


    delete[] str;
    str = tmp;

    return str;
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

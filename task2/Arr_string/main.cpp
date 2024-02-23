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



int max(int*, const int);
int min(int*, const int);
int str_len(const char*);
char* com_cat(char*, const char* );
int avr(int*, const int);
void displayArray(int*, int);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    QWidget mainWindow;
       QVBoxLayout layout(&mainWindow);

       QLineEdit inputLineEdit(&mainWindow);
       layout.addWidget(&inputLineEdit);

       QPushButton submitButton("Submit", &mainWindow);
       layout.addWidget(&submitButton);

       QLabel resultLabel(&mainWindow);
       layout.addWidget(&resultLabel);

       char* str = new char[256];
       char* str1 = new char[256];


     QObject::connect(&submitButton, &QPushButton::clicked, [&]() {
         QString userInput = inputLineEdit.text();


                strcpy(str, userInput.toLocal8Bit().constData());
                strcpy(str1, userInput.toLocal8Bit().constData());


                resultLabel.setText("Строка 1: " + QString(str) + "\nСтрока 2: " + QString(str1));


                inputLineEdit.clear();
     });

     mainWindow.show();

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
                delete [] arr;
                delete [] str;
                delete [] str1;
    return a.exec();
}

int max(int* arr, const int s){
    int m = INT_MIN;
    for(int i = 0; i < s; ++i ){
        if(arr[i] > m){
        m = arr[i];
         }
    }
    return m;
}

int min(int* arr, const int s){
    int m = INT_MAX;
    for(int i = 0; i < s; ++i ){
        if(arr[i] < m){
        m = arr[i];
         }
    }
    return m;
}

int avr(int* arr, const int s){
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


char* com_cat(char*str, const char* str1){
    int i = 0;
    int j = 0;
    while(str1[j] != '\0'){
        while(str[i] != '\0'){
            ++i;
        }
        str[i] = str1[j];
        ++i;
        ++j;
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

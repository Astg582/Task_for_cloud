#include "mainwindow.h"
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <functional>

enum SortingStrategy {
    BubleSort,
    InsertSort,
    SelectSort,
};

struct SortingOption {
    SortingStrategy strategy;
    std::function<void(QVector<int>&)> sortingFunction;

    SortingOption(SortingStrategy s, std::function<void(QVector<int>&)> func)
        : strategy(s), sortingFunction(func) {}
};

QVector<int> readIntArrayFromFile(const QString&);
void buble( QVector<int>& arr);
void insert_S(QVector<int>& arr);
void sel_sort(QVector<int>& arr);

int main()
{
    QString filename = "/home/astghik/Desktop/Task_for_cloud/task3/files/arr.txt";
    QVector<int> integers = readIntArrayFromFile(filename);

            qDebug() << "input for file: " << integers;



    return 0;
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

#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>
#include <QApplication>
#include <QFileDialog>
#include <QMainWindow>
#include <QLabel>

class SortingStrategy {
public:
    virtual void sort(QVector<int>&) = 0;
    virtual ~SortingStrategy() = default;
};

class SelectionSort : public SortingStrategy {
public:
    SelectionSort(){}
    ~SelectionSort(){}
    void sort(QVector<int>& arr) override {
        int s = arr.size();
        for (int i = 0; i < s - 1; ++i) {
            int in2 = i;

            for (int j = i + 1; j < s; ++j) {
                if (arr[j] < arr[in2]) {
                    in2 = j;
                }
            }
            if (in2 != i) {
                std::swap(arr[i], arr[in2]);
            }
        }
    }
};

class InsertSort : public SortingStrategy {
public:
    InsertSort(){}
    ~InsertSort(){}
    void sort(QVector<int>& arr) override {
        int s = arr.size();
        int key = 0;
        int j = 0;
        for (int i = 1; i < s; ++i) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && key < arr[j]) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

class BubbleSort : public SortingStrategy {
public:
    BubbleSort(){}
    ~BubbleSort(){}
    void sort(QVector<int>& arr) override {
        int s2 = arr.size();

        for (int i = 0; i < s2 - 1; ++i) {
            for (int j = 0; j < s2 - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
            --s2;
        }
    }
};

class FileHandler {
public:
    FileHandler(){}

    QVector<int> readArrayFromFile() {
        QString filename = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Text Files (*.txt);;All Files (*)");

        if (filename.isEmpty()) {
            qDebug() << "User canceled the file dialog or entered an empty file name.";
            return QVector<int>();
        } else {
            qDebug() << "Selected file name: " << filename;
        }

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

    void saveArrayToFile(QVector<int>& integers, const QString& filePath) {
        if (filePath.isEmpty()) {
            qDebug() << "Empty file path provided for saving. Aborting.";
            return;
        }

        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            for (int value : integers) {
                out << value << endl;
            }
            file.close();
            qDebug() << "File saved successfully to:" << filePath;
        } else {
            qWarning() << "Could not open file for writing:" << filePath;
        }
    }
~FileHandler() = default;
};

class SortingApplication {
private:
    SortingStrategy* sorting;
    FileHandler files;

public:
    SortingApplication() : sorting(nullptr) {}



    void runSortingApplication() {
           QString sortAlgorithm = QInputDialog::getItem(nullptr, "Input", "Select sorting algorithm:", {"Selection Sort", "Insertion Sort", "Bubble Sort"});

           if (sortAlgorithm.isEmpty()) {
               qDebug() << "User canceled the sorting algorithm selection.";
               return;
           }

           if (sortAlgorithm == "Selection Sort") {
                       sorting = new SelectionSort();
                   } else if (sortAlgorithm == "Insertion Sort") {
                       sorting = new InsertSort();
                   } else if (sortAlgorithm == "Bubble Sort") {
                       sorting = new BubbleSort();
                   } else {
                       qDebug() << "Invalid sorting algorithm choice.";
                       return;
                   }

           QVector<int> vec = files.readArrayFromFile();
           sorting->sort(vec);
           if(sorting != nullptr){
            delete  sorting;
           }
           for (int i = 0; i < vec.size(); ++i) {
               qDebug() << "vec[" << i << "]:" << vec[i];
           }

           QString saveFileName = QFileDialog::getSaveFileName(nullptr, "Save Sorted Array", "", "Text Files (*.txt);;All Files (*)");
           if (!saveFileName.isEmpty()) {
               files.saveArrayToFile(vec, saveFileName);
               qDebug() << "File saved successfully.";
           } else {
               qDebug() << "User canceled the file dialog or entered an empty file name. Array not saved.";
           }
       }
     ~SortingApplication() {if(sorting != nullptr) { delete sorting;}}

};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    SortingApplication appl;
    appl.runSortingApplication();

    return a.exec();
}








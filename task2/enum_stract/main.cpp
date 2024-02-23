#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <iostream>
#include <QLabel>
#include <QString>
#include <QInputDialog>

enum Week {
    Sun,
    Mon,
    Tu,
    We,
    Thu,
    Fri,
    Sat
};

struct Day {
    size_t year;
    size_t month;
    size_t day;
};

void disp(const Day& d, Week w, QLabel* label) {
    QString weekD;

    switch (w) {
        case Sun: weekD = QCoreApplication::translate("MainWindow", "Sunday"); break;
        case Mon: weekD = QCoreApplication::translate("MainWindow", "Monday"); break;
        case Tu: weekD = QCoreApplication::translate("MainWindow", "Tuesday"); break;
        case We: weekD = QCoreApplication::translate("MainWindow", "Wednesday"); break;
        case Thu: weekD = QCoreApplication::translate("MainWindow", "Thursday"); break;
        case Fri: weekD = QCoreApplication::translate("MainWindow", "Friday"); break;
        case Sat: weekD = QCoreApplication::translate("MainWindow", "Saturday"); break;
    }

    label->setText(weekD + ", " + QString::number(d.day) + " " + QString::number(d.month) + " " + QString::number(d.year));
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Day Dday;
    Dday.day = QInputDialog::getInt(nullptr, "Enter day", "Enter day:");
    Dday.month = QInputDialog::getInt(nullptr, "Enter day", "Enter month:");
    Dday.year = QInputDialog::getInt(nullptr, "Enter day", "Enter Year:");

    int dayOfWeekNum = QInputDialog::getInt(nullptr, "Enter day of the week", "Enter day of the week (0-6):");
    Week dayOfWeek = static_cast<Week>(dayOfWeekNum);

    QLabel label;
    disp(Dday, dayOfWeek, &label);
    label.show();

    return a.exec();
}

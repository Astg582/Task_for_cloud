#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

class ToDoList : public QWidget {
public:
    ToDoList(QWidget *parent = nullptr) : QWidget(parent) {

        taskInput = new QLineEdit(this);
        addButton = new QPushButton("Add", this);
        deleteButton = new QPushButton("Delete", this);
        taskList = new QListWidget(this);


        connect(addButton, &QPushButton::clicked, this, &ToDoList::addTask);
        connect(deleteButton, &QPushButton::clicked, this, &ToDoList::deleteTask);


        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(taskInput);
        layout->addWidget(addButton);
        layout->addWidget(deleteButton);
        layout->addWidget(taskList);

        setLayout(layout);
        setWindowTitle("To-Do List");
    }

private slots:
    void addTask() {

        QString task = taskInput->text();
        if (!task.isEmpty()) {
            taskList->addItem(task);
            taskInput->clear();
        }
    }

    void deleteTask() {

        int selectedRow = taskList->currentRow();
        if (selectedRow != -1) {
            delete taskList->takeItem(selectedRow);
        }
    }

private:
    QLineEdit *taskInput;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QListWidget *taskList;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ToDoList todo;
    todo.show();

    return app.exec();
}

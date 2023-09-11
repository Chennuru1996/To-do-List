#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("To-Do List");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLineEdit *taskInput = new QLineEdit(&window);
    layout->addWidget(taskInput);

    QListWidget *taskList = new QListWidget(&window);
    layout->addWidget(taskList);

    QPushButton *addButton = new QPushButton("Add Task", &window);
    layout->addWidget(addButton);

    QPushButton *removeButton = new QPushButton("Remove Task", &window);
    layout->addWidget(removeButton);

    QObject::connect(addButton, &QPushButton::clicked, [&]() {
        QString task = taskInput->text();
        if (!task.isEmpty()) {
            taskList->addItem(task);
            taskInput->clear();
        }
    });

    QObject::connect(removeButton, &QPushButton::clicked, [&]() {
        QListWidgetItem *selectedItem = taskList->currentItem();
        if (selectedItem) {
            delete selectedItem;
        }
    });

    window.show();

    return app.exec();
}


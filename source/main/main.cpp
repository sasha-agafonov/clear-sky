#include <QApplication>
#include <QVBoxLayout>

#include "widgets/gui.hpp"

int main(int argc, char *argv[])
{ 
    auto app = QApplication{argc, argv};

    auto* const gui = new ::gui;

    gui->setStyleSheet("background: rgba(40, 44, 52, 1);");
    gui->showMaximized();

    app.exec();

    delete gui;

    return 0;
}

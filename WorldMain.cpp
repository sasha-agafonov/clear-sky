#include <QApplication>
#include <QVBoxLayout>
#include "WorldWindow.h"

int main(int argc, char *argv[]) { 

    QApplication app(argc, argv);

    WorldWindow *window = new WorldWindow(NULL);

    window->setStyleSheet("background: rgba(40, 44, 52, 1);");
    window->resize(512, 712);
    window->show();

    app.exec();

    delete window;

    return 0;
}

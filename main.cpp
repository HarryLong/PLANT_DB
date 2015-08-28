#include <QApplication>
#include "main_window.h"

int main(int argc, char *argv[])
{
    printf("Launching Plant DB Editor...\n");
    QApplication app(argc, argv);
    MainWindow w;
    w.resize(w.sizeHint());
    w.showMaximized();

    return app.exec();
}

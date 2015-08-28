#include "main_window.h"
#include "plant_db_editor.h"

MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
    PlantDBEditor * plant_db_editor (new PlantDBEditor);

    setCentralWidget(plant_db_editor);
}

MainWindow::~MainWindow()
{

}

#include <QApplication>
#include "grid.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Grid grid;
    QIcon icon("/Users/berkaybgk/Desktop/assets/mine.png");
    grid.setWindowIcon(icon);
    grid.setWindowTitle("Mine Sweeper");
    grid.setFixedSize((34 * BOARD_WIDTH + 30), (36 * BOARD_HEIGHT + 60));
    grid.show();
    return app.exec();
}

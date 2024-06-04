#ifndef GRID_H
#define GRID_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>

#define BOARD_WIDTH 16
#define BOARD_HEIGHT 16
#define MINE_COUNT 36

class Grid : public QWidget {
    Q_OBJECT

public slots:
    void handleButtonClick();
    void restartGame();
    void revealAll();
    void winningGame(int score);
    int giveHint();
    void rightClicked();
    void deleteArray(int** array, int j);
    int** neighborCell(int** array, int currentX, int currentY);

public:
    Grid(QWidget *parent = nullptr);
    QPushButton* getButtonAt(int row, int col);
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    int isClickableList[BOARD_HEIGHT][BOARD_WIDTH];
    int winningCondition = BOARD_WIDTH * BOARD_HEIGHT - MINE_COUNT;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonLayout;
    QGridLayout *layout;
    QPushButton *restartButton;
    QPushButton *hintButton;
    QLabel *scoreLabel;
    QPixmap buttonImage0, buttonImage1, buttonImage2, buttonImage3;
    QPixmap buttonImage4, buttonImage5, buttonImage6, buttonImage7;
    QPixmap buttonImage8, buttonImageMine, buttonImageEmpty, buttonImageHint;
    QPixmap buttonImageFlag;
    int lastHint[2] = {-1, -1};
    int flagsList[BOARD_HEIGHT][BOARD_WIDTH];

    void puttingImage(QPushButton *button, int revealRow,int revealCol);
    void initializeBoard();
    void placeMines();
    void initializeClickableList();
    void initializeMineCount();
    bool isMine(int x, int y);
    bool isClickable(int x, int y);
    bool isWin();
    int keepingScore();
    int numberOfClickableCell(int** array);
    int mineNumber(int array[][BOARD_WIDTH],int currentX,int currentY);
    int findCorrectPlace(int* correctLocation,int array[][BOARD_WIDTH],int array2[][BOARD_WIDTH],int currentX,int currentY);
    void bfs(int x, int y);
    // main variables and grids

};

#endif // GRID_H

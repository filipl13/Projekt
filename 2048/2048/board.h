class Board {
private:
    int grid[4][4];
    int score;

    void addRandomTile();
    void rotateLeft();
    void rotateRight();

public:
    Board();

    void reset();

    int getValue(int row, int col) const;
    int getScore() const;

    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();
};


#include <vector>

class GameState {
public:
    static constexpr int EMPTY  = 0;
    static constexpr int BURNED = 1;
    static constexpr int WHITE  = 2;
    static constexpr int BLACK  = 3;

    GameState(int width, int height, const std::vector<std::vector<int>>& board);

    std::vector<int[]> getLegalMoves(int color);
    GameState performMove(const std::vector<int>& move) const;
    void doMove(const std::vector<int>& move);
    void undoMove(const std::vector<int>& move);

    bool isTerminal(const std::vector<std::vector<int>>& currentPlayerMoves) const;
    int  getWinner(const std::vector<std::vector<int>>& currentPlayerMoves) const;
    int  evaluate(const std::vector<std::vector<int>>& currentPlayerMoves) const;

    GameState copy() const;

    int  width;
    int  height;
    bool whiteTurn;
    int  numOfEmptySquares;
    std::vector<std::vector<int>> board;

private:
    void getLegalMovesHelper(
        std::vector<std::vector<int>>& near,
        std::vector<std::vector<int>>& far,
        int row, int col,
        int dx, int dy,
        int oppColor
    );

    bool isAdjacentToOpponent(int r, int c, int oppColor) const;
    int  countMoveableQueens(int color) const;
    bool hasLegalMove(int row, int col) const;
};
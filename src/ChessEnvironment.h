#pragma once

#include <string>
#include <vector>

class ChessState;

class ChessEnvironment {
public:
    ChessEnvironment();

    void init(
        const std::string& role,
        int width,
        int height,
        int playclock,
        const std::vector<std::vector<int>>& white_positions,
        const std::vector<std::vector<int>>& black_positions
    );

    std::string nextAction(const std::vector<int>& lastMove);
    int evaluate(const ChessState& state, const std::vector<std::vector<int>>& moves) const;
    std::vector<int> bestMoveSearch(ChessState& state, int depth);
    int search(ChessState& state, int depth, int alpha, int beta);
    void cleanup();

private:
    std::string role;
    int playclock;
    bool myTurn;
    int width;
    int height;
    ChessState* state;
    long deadline;
    int exp;
    double time_avg;
    int last_search_value;
};

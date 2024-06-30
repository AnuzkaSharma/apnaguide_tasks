#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Piece {
public:
    Piece(char symbol, string color) : symbol_(symbol), color_(color) {}

    virtual bool canMove(const vector<vector<Piece*>>& board, int startRow, int startCol, int endRow, int endCol) const = 0;

    void move(vector<vector<Piece*>>& board, int startRow, int startCol, int endRow, int endCol) {
        board[endRow][endCol] = this;
        board[startRow][startCol] = nullptr;
    }

    char getSymbol() const { return symbol_; }
    string getColor() const { return color_; }

private:
    char symbol_;
    string color_;
};

// Define specific movement rules for each piece type (King, Queen, etc.)
// These classes inherit from the base Piece class and implement the canMove method

class King : public Piece {
public:
    King(string color) : Piece('K', color) {}

    bool canMove(const vector<vector<Piece*>>& board, int startRow, int startCol, int endRow, int endCol) const override {
        // One step in any direction (including diagonally)
        return abs(startRow - endRow) <= 1 && abs(startCol - endCol) <= 1;
    }
};

class Queen : public Piece {
public:
    Queen(string color) : Piece('Q', color) {}

    bool canMove(const vector<vector<Piece*>>& board, int startRow, int startCol, int endRow, int endCol) const override {
        // Can move any number of steps horizontally, vertically, or diagonally
        return (startRow == endRow || startCol == endCol) ||
               abs(startRow - endRow) == abs(startCol - endCol);
    }
};

// Similar classes can be defined for Rook, Bishop, Knight, Pawn, etc.

class Board {
public:
    Board() {
        // Initialize board with starting positions (replace with actual piece setup logic)
        for (int i = 0; i < 8; i++) {
            vector<Piece*> row;
            if (i == 0 || i == 7) {
                for (int j = 0; j < 8; j++) {
                    if (i == 0) {
                        row.push_back(abs Piece("PNBRQK"[j], "black"));
                    }
                    else {
                        row.push_back(abs Piece("pnbrqk"[j], "white"));
                    }
                }
            } else {
                for (int j = 0; j < 8; j++) {
                    row.push_back(nullptr);
                }
            }
            board_.push_back(row);
        }
    }

    ~Board() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                delete board_[i][j];
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board_[i][j]) {
                    cout << board_[i][j]->getSymbol();
                } else {
                    cout << " ";
                }
                cout << " ";
            }
            cout << endl;
        }
    }

    Piece* getPiece(int row, int col) const { return board_[row][col]; }

    bool movePiece(int startRow, int startCol, int endRow, int endCol) {
        Piece* piece = getPiece(startRow, startCol);
        if (!piece) {
            return false;
        }
        if (!piece->canMove(board_, startRow, startCol, endRow, endCol)) {
            return false;
        }
        piece->move(board_, startRow, startCol, endRow, endCol);
        return true;
    }

private:
    vector<vector<Piece*>> board_;
};

int getChessNotation(int row) {
    return 8 - row; // Convert row number to chess
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "Board.h"

namespace boggle {

void Board::setOffsets(int dimension) {
    offset[0] = -dimension - 1;
    offset[1] = -dimension;
    offset[2] = -dimension+1;
    offset[3] = -1;
    offset[4] = 1;
    offset[5] = dimension-1;
    offset[6] = dimension;
    offset[7] = dimension+1;
}

void Board::print () {
    int dimension = offset[6];
    for (unsigned int ii=dimension; ii<board.size(); ii++) {
        if (ii % dimension == 0)
            std::cout << std::endl;
        if (board[ii] != (char)0) {
            if (board[ii] == 'Q') {
                std::cout << " Qu ";
            } else {
                std::cout << " " << board[ii] << "  ";
            }
        }
    }
}

bool Board::setBoard(std::string s) {
    unsigned int dimension = (unsigned int)(sqrt(s.size())+ 0.5);
    if (dimension * dimension != s.size())
        return false;
    unsigned int boarddimension = dimension + 2;
    setOffsets(boarddimension);
    board.clear();
    used.clear();
    // first row
    for (unsigned int ii = 0; ii < boarddimension; ii++) {
        board.push_back((char) 0);
        used.push_back(true);
    }
    //middle rows
    for (unsigned int mr = 0; mr < dimension; mr++) {
        board.push_back ((char) 0);
        used.push_back (true);
        for (unsigned int col = 0; col < dimension; col++) {
            board.push_back(s[mr*dimension+col]);
            used.push_back (false);
        }
        board.push_back((char) 0);
        used.push_back (true);
    }
    //last row
    for (unsigned int ii = 0; ii < boarddimension; ii++) {
        board.push_back((char) 0);
        used.push_back(true);
    }
    return true;
}

void Board::solve(Dict &dict, Solution &solution) {
    solution.initialize();
    for (unsigned int boardIndex = 0; boardIndex < board.size(); boardIndex++) {
        if (board[boardIndex] != (char)0) {
            std::string s(1, board[boardIndex]);
            int dictIndex= dict.getNextIndex(0, board[boardIndex]);
            if (board[boardIndex] == 'Q') {
                s.push_back('U');
                dictIndex = dict.getNextIndex(dictIndex, 'U');
            }
            if (dictIndex > 0) {
                used[boardIndex] = true;
                search(s, boardIndex, dictIndex, dict, solution);
                used[boardIndex] = false;
            }
        }
    }
}

void Board::search(std::string current, int boardIndex, int dictIndex, 
                         Dict &dict, Solution &solution) {
    if (dict.isWord(dictIndex))
        solution.addWord(current);
    for (int direction = 0; direction<8; direction++) {
        int newBoardIndex = boardIndex + offset[direction];
        if (!used[newBoardIndex]) {
            char letter = board[newBoardIndex];
            int newDictIndex = dict.getNextIndex(dictIndex, letter);
            if (letter == 'Q' && newDictIndex > 0)
                newDictIndex = dict.getNextIndex(newDictIndex, 'U');
            if (newDictIndex > 0) {
                used[newBoardIndex] = true;
                current.push_back(letter);
                if (letter == 'Q')
                    current.push_back('U');
                search(current, newBoardIndex, newDictIndex, dict, solution);
                current.erase(current.size() - 1);
                if (letter == 'Q')
                    current.erase(current.size() - 1);
                used[newBoardIndex] = false;
            }
        }
    }
}
} // namespace boggle

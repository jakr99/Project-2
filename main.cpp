#include "puzzle.h"
#include <iostream>
using namespace std;

int main() {
  int puzzles;
  cin >> puzzles;
  Puzzle puzzle;

  for (int k = 0; k < puzzles; k++) {
    int rows, cols, moves;
    cin >> rows >> cols >> moves;

    puzzle.create_grid(rows, cols);

    puzzle.fill_grid();

    for (int m = 0; m < moves; m++) {
      int row_col;
      char direction;
      cin >> row_col >> direction;

      if (row_col < rows) {
        if (direction == 'R') {
          puzzle.shift_row(row_col);
        } else if (direction == 'L') {
          puzzle.shift_row(row_col, true);
        }
      } else {
        row_col -= rows;
        if (direction == 'D') {
          puzzle.shift_col(row_col);
        } else if (direction == 'U') {
          puzzle.shift_col(row_col, true);
        }
      }
    }

    puzzle.print_grid();

    puzzle.delete_grid();
  }

  return 0;
}

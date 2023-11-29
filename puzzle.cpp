#include "puzzle.h"
#include <cstring>
#include <iostream>
using namespace std;

void Puzzle::create_grid(int r, int c) {
  delete_grid();

  rows = r;
  cols = c;

  symbols = new char *[rows];
  for (int i = 0; i < rows; ++i) {
    symbols[i] = new char[cols];
  }
}

void Puzzle::delete_grid() {
  if (symbols != nullptr) {
    for (int i = 0; i < rows; ++i) {
      delete[] symbols[i];
    }
    delete[] symbols;
    symbols = nullptr;
  }

  rows = 0;
  cols = 0;
}

void Puzzle::shift_row(int row, bool reverse) {
  char *temp = new char[cols];
  memcpy(temp, symbols[row], cols * sizeof(char));

  for (int i = 0; i < cols; ++i) {
    int newPos = reverse ? (i - 1 + cols) % cols : (i + 1) % cols;
    newPos = (newPos + cols) % cols;
    symbols[row][newPos] = temp[i];
  }

  delete[] temp;
}

void Puzzle::shift_col(int col, bool reverse) {
  char *temp = new char[rows];
  for (int i = 0; i < rows; ++i) {
    temp[i] = symbols[i][col];
  }

  for (int i = 0; i < rows; ++i) {
    int newPos = reverse ? (i - 1 + rows) % rows : (i + 1) % rows;
    newPos = (newPos + rows) % rows;
    symbols[newPos][col] = temp[i];
  }

  delete[] temp;
}

void Puzzle::fill_grid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> symbols[i][j];
    }
  }
}

void Puzzle::print_grid() const {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << symbols[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

const Puzzle &Puzzle::operator=(const Puzzle &rhs) {
  if (this == &rhs) {
    return *this;
  }

  delete_grid();
  create_grid(rhs.rows, rhs.cols);
  for (int r = 0; r < rhs.rows; r++)
    for (int c = 0; c < rhs.cols; c++)
      symbols[r][c] = rhs.symbols[r][c];

  return *this;
}

Puzzle::Puzzle(const Puzzle &source) {
  symbols = nullptr;
  *this = source;
}

Puzzle::~Puzzle() { delete_grid(); }

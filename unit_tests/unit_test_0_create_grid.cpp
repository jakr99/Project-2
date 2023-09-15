#include "puzzle.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    int rows = 1000, cols = 1000;
    Puzzle p;

    try {
      p.create_grid(rows, cols);
      p.grid()[999][999] = 'x';
    }

    catch (...) {
      return false;
    }

    if (p.get_rows() != 1000 || p.get_cols() != 1000)
      return false;

    return true;
  });
}

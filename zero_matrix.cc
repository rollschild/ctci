#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> zero_matrix(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  vector<int> memo_row(m, 0);
  vector<int> memo_col(n, 0);
  vector<pair<int, int>> pos{};
  for (int i = 0; i < m; ++i) {
    auto itr = find(matrix[i].begin(), matrix[i].end(), 0);
    if (itr != matrix[i].end()) {
      int j = itr - matrix[i].begin();
      pos.push_back(make_pair(i, j));
    }
  }

  for (auto pr : pos) {
    if (memo_row[pr.first] && memo_col[pr.second]) {
      continue;
    } else if (memo_row[pr.first]) {
      memo_col[pr.second] = 1;
      for (int p = 0; p < m; ++p) {
        matrix[p][pr.second] = 0;
      }
    } else if (memo_col[pr.second]) {
      memo_row[pr.first] = 1;
      for (int q = 0; q < n; ++q) {
        matrix[pr.first][q] = 0;
      }
    } else {
      for (int p = 0; p < m; ++p) {
        matrix[p][pr.second] = 0;
      }
      for (int q = 0; q < n; ++q) {
        matrix[pr.first][q] = 0;
      }
    }
  }

  return matrix;
}

void print_matrix(vector<vector<int>> &matrix) {
  for (auto outer : matrix) {
    for (auto inner : outer) {
      cout << inner << ", ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> matrix{
      {16, 0, -1},
      {8, 99, 4},
      {-3, 100, 2037},
  };

  auto res = zero_matrix(matrix);

  print_matrix(res);

  return 0;
}

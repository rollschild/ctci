#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<int>> &matrix) {
  for (auto outer : matrix) {
    for (auto inner : outer) {
      cout << inner << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> rotate_matrix(vector<vector<int>> &matrix) {
  vector<int> row{};
  vector<vector<int>> result{};
  for (int i = 0; i < matrix.size(); ++i) {
    row.clear();
    for (int j = matrix.size() - 1; j >= 0; --j) {
      row.push_back(matrix[j][i]);
    }
    result.push_back(row);
  }

  return result;
}

int main() {
  vector<vector<int>> matrix{
      {16, 0, -1},
      {8, 99, 4},
      {-3, 100, 2037},
  };

  auto res = rotate_matrix(matrix);

  print_matrix(res);

  return 0;
}

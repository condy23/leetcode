#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    // 定义一个二维数组
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startx = 0;
    int starty = 0;
    int offset = 1;
    int count = 1;
    int loop = n / 2;
    while (loop--) {
      int i = startx;
      int j = starty;
      for (; j < n - offset; j++) {
        res[i][j] = count++;
      }
      for (; i < n - offset; i++) {
        res[i][j] = count++;
      }
      for (; j > starty; j--) {
        res[i][j] = count++;
      }
      for (; i > startx; i--) {
        res[i][j] = count++;
      }
      startx++;
      starty++;
      offset += 1;
    }
    if (n % 2 == 1) {
      res[n / 2][n / 2] = count;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> res = s.generateMatrix(3);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
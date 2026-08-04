#include <bits/stdc++.h>
using namespace std;

// Modified Number of Islands: count islands with size >= k
class Solution {
public:
    int numIslands(vector<vector<char>> grid, int k) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int size = dfs(grid, i, j, m, n);
                    if (size >= k) count++;
                }
            }
        }
        return count;
    }

private:
    int dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return 0;

        grid[i][j] = '0'; // mark visited

        int size = 1;
        size += dfs(grid, i + 1, j, m, n); // down
        size += dfs(grid, i - 1, j, m, n); // up
        size += dfs(grid, i, j + 1, m, n); // right
        size += dfs(grid, i, j - 1, m, n); // left

        return size;
    }
};

// Helper function to print grid
void printGrid(const vector<vector<char>>& grid) {
    for (auto& row : grid) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

// Main function (test cases)
int main() {
    Solution sol;

    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    vector<vector<char>> grid3 = {
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };

    vector<vector<char>> grid4 = {
        {'1'}
    };

    vector<vector<char>> grid5 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };

    cout << "=== Test Cases for Modified Number of Islands (Size >= k) ===\n\n";

    cout << "Test 1: Grid1\n";
    cout << "  Islands with size >= 1: " << sol.numIslands(grid1, 1) << endl;
    cout << "  Islands with size >= 2: " << sol.numIslands(grid1, 2) << endl;
    cout << "  Islands with size >= 5: " << sol.numIslands(grid1, 5) << endl;

    cout << "\nTest 2: Grid2\n";
    cout << "  Islands with size >= 1: " << sol.numIslands(grid2, 1) << endl;
    cout << "  Islands with size >= 2: " << sol.numIslands(grid2, 2) << endl;
    cout << "  Islands with size >= 3: " << sol.numIslands(grid2, 3) << endl;
    cout << "  Islands with size >= 4: " << sol.numIslands(grid2, 4) << endl;

    cout << "\nTest 3: All water grid\n";
    cout << "  Islands with size >= 1: " << sol.numIslands(grid3, 1) << endl;

    cout << "\nTest 4: Single cell grid\n";
    cout << "  Islands with size >= 1: " << sol.numIslands(grid4, 1) << endl;
    cout << "  Islands with size >= 2: " << sol.numIslands(grid4, 2) << endl;

    cout << "\nTest 5: 3x3 all land grid\n";
    cout << "  Islands with size >= 5: " << sol.numIslands(grid5, 5) << endl;
    cout << "  Islands with size >= 10: " << sol.numIslands(grid5, 10) << endl;

    return 0;
}
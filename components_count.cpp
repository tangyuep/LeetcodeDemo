//
// Created by 81554 on 24-8-9.
//

//在一个无限大的网格图内，初始所有格子都是白色。
//有n次操作，每次操作给出x,y,c。若c = 0即为将(x,y)以及(x,y)上下左右4个格子染成红色。
//若c = 1即为将(x,y)以及(x,y)上下左右4个格子染成黑色。所有操作完成后，问红色连通块个数，黑色连通块个数。

//输入用例：
//4
//2 3 0
//3 2 1
//3 3 0
//2 4 1

//输出： 2 3

#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(pair<int, int> pos, map<pair<int, int>, int> &grid, map<pair<int, int>, bool> &visited, int color) {
    stack<pair<int, int>> s;
    s.push(pos);
    visited[pos] = true;

    while (!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            pair<int, int> next = {nx, ny};

            if (grid.count(next) && grid[next] == color && !visited[next]) {
                visited[next] = true;
                s.push(next);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    map<pair<int, int>, int> grid;

    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;

        vector<pair<int, int>> points = {{x, y}, {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

        for (auto point : points) {
            grid[point] = c;
        }
    }

    map<pair<int, int>, bool> visited;
    int redComponents = 0, blackComponents = 0;

    for (auto &cell : grid) {
        pair<int, int> pos = cell.first;
        int color = cell.second;

        if (!visited[pos]) {
            if (color == 0) {
                redComponents++;
            } else if (color == 1) {
                blackComponents++;
            }
            dfs(pos, grid, visited, color);
        }
    }

    cout << "Red Components: " << redComponents << endl;
    cout << "Black Components: " << blackComponents << endl;

    return 0;
}

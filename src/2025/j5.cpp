#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lowest_cost(vector<vector<int>> grid, vector<vector<int>>& costs, int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int width, height, max_cost;
    cin >> height >> width >> max_cost;

    vector<vector<int>> grid = vector(height, vector(width, 0));
    int i = 1;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = i;
            if (++i > max_cost)
                i = 1;
        }
    }

    vector<vector<int>> costs = vector(height, vector(width, 0));
    for (int x = 0; x < width; ++x)
        costs[0][x] = lowest_cost(grid, costs, x, 0);
    cout << *min_element(costs[0].begin(), costs[0].end()) << '\n';
    return 0;
}

int lowest_cost(vector<vector<int>> grid, vector<vector<int>>& costs, int x, int y) {
    if (y == (int)grid.size() - 1)
        return grid[y][x];

    vector<int> child_costs;
    if (costs[y + 1][x]) {
        child_costs.push_back(costs[y + 1][x]);
    } else {
        costs[y + 1][x] = lowest_cost(grid, costs, x, y + 1);
        child_costs.push_back(costs[y + 1][x]);
    }
    if (x != 0) {
        if (costs[y + 1][x - 1]) {
            child_costs.push_back(costs[y + 1][x - 1]);
        } else {
            costs[y + 1][x - 1] = lowest_cost(grid, costs, x - 1, y + 1);
            child_costs.push_back(costs[y + 1][x - 1]);
        }
    }
    if (x != (int)grid[y].size() - 1) {
        if (costs[y + 1][x + 1]) {
            child_costs.push_back(costs[y + 1][x + 1]);
        } else {
            costs[y + 1][x + 1] = lowest_cost(grid, costs, x + 1, y + 1);
            child_costs.push_back(costs[y + 1][x + 1]);
        }
    }

    return grid[y][x] + *min_element(child_costs.begin(), child_costs.end());
}

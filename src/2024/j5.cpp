#include <iostream>
#include <vector>

using namespace std;

int value(vector<int> &patch, vector<int> &values, int width, int height, int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int width, height;
    cin >> height >> width;

    vector<int> patch(width * height);
    for (int y = 0; y < height; ++y) {
        string row;
        cin >> row;

        for (int x = 0; x < width; ++x) {
            int cell = 0;
            switch (row[x]) {
            case 'S':
                cell = 1;
                break;
            case 'M':
                cell = 5;
                break;
            case 'L':
                cell = 10;
                break;
            }

            patch[y * width + x] = cell;
        }
    }

    int farmer_x, farmer_y;
    cin >> farmer_y >> farmer_x;

    vector<int> values(width * height, 0);
    cout << value(patch, values, width, height, farmer_x, farmer_y) << '\n';

    return 0;
}

int value(vector<int> &patch, vector<int> &values, int width, int height, int x, int y) {
    int pos, sum = 0;

    pos = y * width + x;
    values[pos] = -1;

    pos = y * width + x + 1;
    if (x + 1 < width && patch[pos] && !values[pos]) {
        values[pos] = value(patch, values, width, height, x + 1, y);
        sum += values[pos];
    }

    pos = y * width + x - 1;
    if (x - 1 >= 0 && patch[pos] && !values[pos]) {
        values[pos] = value(patch, values, width, height, x - 1, y);
        sum += values[pos];
    }

    pos = (y - 1) * width + x;
    if (y - 1 >= 0 && patch[pos] && !values[pos]) {
        values[pos] = value(patch, values, width, height, x, y - 1);
        sum += values[pos];
    }

    pos = (y + 1) * width + x;
    if (y + 1 < height && patch[pos] && !values[pos]) {
        values[pos] = value(patch, values, width, height, x, y + 1);
        sum += values[pos];
    }

    pos = y * width + x;
    sum += patch[pos];

    return sum;
}

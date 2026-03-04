#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Pen {
    long long color;
    long long prettiness;
};

struct Change {
    long long type;
    long long pen;
    long long value;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long num_pens, num_colors, num_pictures;
    cin >> num_pens >> num_colors >> num_pictures;
    num_pictures += 1;

    vector<Pen> pens(num_pens);
    for (Pen &pen : pens) {
        long long color, prettiness;
        cin >> color >> prettiness;
        pen = Pen{color - 1, prettiness};
    }

    vector<Change> changes(num_pictures);
    changes[0] = Change{0, 0, 0};
    for (Change &change : changes) {
        long long type, pen, value;
        cin >> type >> pen >> value;
        if (type == 1)
            value -= 1;
        change = Change{type, pen - 1, value};
    }

    for (Change change : changes) {
        if (change.type == 1)
            pens[change.pen].color = change.value;
        else if (change.type == 2)
            pens[change.pen].prettiness = change.value;

        vector<long long> first_prettiest_colors(num_colors, 0);
        vector<long long> second_prettiest_colors(num_colors, 0);
        for (Pen pen : pens) {
            if (pen.prettiness > first_prettiest_colors[pen.color]) {
                second_prettiest_colors[pen.color] = first_prettiest_colors[pen.color];
                first_prettiest_colors[pen.color] = pen.prettiness;
            } else if (pen.prettiness > second_prettiest_colors[pen.color]) {
                second_prettiest_colors[pen.color] = pen.prettiness;
            }
        }

        long long weakest_first =
            *min_element(first_prettiest_colors.begin(), first_prettiest_colors.end());
        long long strongest_second =
            *max_element(second_prettiest_colors.begin(), second_prettiest_colors.end());

        cout << reduce(first_prettiest_colors.begin(), first_prettiest_colors.end()) -
                    weakest_first + max(strongest_second, weakest_first)
             << '\n';
    }

    return 0;
}

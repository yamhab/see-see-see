#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long spot_count, light_count, question_count;
    cin >> spot_count >> light_count >> question_count;

    vector<pair<long long, long long>> lights(light_count);
    for (pair<long long, long long> &light : lights) {
        cin >> light.first >> light.second;
        --light.first;
    }

    vector<long long> questions(question_count);
    for (long long &question : questions) {
        cin >> question;
        --question;
    }

    vector<bool> spots(spot_count);
    for (pair<long long, long long> light: lights) {
        long long spot = light.first;
        long long spread = light.second;

        long long begin = max((long long)0, spot - spread);
        long long end = min(spot + spread + 1, spot_count);

        for (int i = begin; i < end; ++i)
            spots[i] = true;
    }

    for (long long question : questions)
        cout << (spots[question] ? "Y\n" : "N\n");

    return 0;
}

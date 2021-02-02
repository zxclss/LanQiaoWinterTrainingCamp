#include <iostream>
#include <vector>
using namespace std;

vector<string> dirt = {
    "zero", "one", "two",
    "three", "four", "five",
    "six", "seven", "eight",
    "nine"
};

int main() {
    int sum = 0;
    string num;
    vector<string> res;

    cin >> num;
    for (auto ch: num) sum += ch - '0';
    if (!sum) res.push_back(dirt[0]);
    while (sum) {
        res.push_back(dirt[sum % 10]);
        sum /= 10;
    }
    cout << res[res.size() - 1];
    for (int i = res.size() - 2; i >= 0; --i) cout << " " << res[i];
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, vector<int>> grade;
vector<int> q[4];
//A > C > M > E

int find(vector<int>& vec, int x) {
    int l = 0, r = vec.size() - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (vec[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return vec.size() - l;
}
int main() {
    int n, m;
    cin >> n >> m;
    while (n--) {
        int id, score[4] = {0};
        cin >> id;
        for (int j = 1; j < 4; ++j) cin >> score[j], score[0] += score[j];
        score[0] /= 3;

        for (int j = 0; j < 4; ++j) {
            grade[id].push_back(score[j]);
            q[j].push_back(score[j]);
        }
    }
    //sort
    for (int i = 0; i < 4; ++i) sort(q[i].begin(), q[i].end());
    char className[] = {"ACME"};

    while (m--) {
        int id;
        cin >> id;
        if (!grade.count(id)) cout << "N/A" << endl;
        else {
            int rank = 1e9;
            char classTemp;
            for (int i = 0; i < 4; ++i) {
                int rankTemp = find(q[i], grade[id][i]);
                if (rankTemp < rank)
                    rank = rankTemp, classTemp = className[i];
            }
            cout << rank << " " << classTemp << endl;
        }
    }

    return 0;
}


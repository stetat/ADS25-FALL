#include <iostream>
#include <vector>

using namespace std;

int enemies[1000100];
int n;


pair<int, int> fight(int power) {
    int en_pow = 0;
    int en_num = 0;

    for(int i = 0; i < n; i++) {
        if (enemies[i] <= power) {
            en_pow+=enemies[i];
            en_num++;
        }
    }

    return make_pair(en_num, en_pow);


}


int main() {
    int x, r, power;
    vector<pair<int, int>> result;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> x;
        enemies[i] = x;
    }

    cin >> r;

    for(int i = 0; i < r; i++) {
        cin >> power;
        result.push_back(fight(power));

    }

    for(pair<int, int> x : result) {
        cout << x.first << " " << x.second << endl;
    }




    



    return 0;
}
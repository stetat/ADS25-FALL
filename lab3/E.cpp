#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long

vector<pair<pair<LL, LL>, pair<LL, LL>>> coords;
int k;

bool covers(int size) {
    int cows = 0;

    for(pair<pair<LL, LL>, pair<LL, LL>> x : coords) {
        if( x.second.first <= size && x.second.second <= size) {
            cows++;
        }

        if(cows >= k) {
            return true;
        }

    }

    return false;


}

int main() {
    int n;
    LL x1, y1, x2, y2, max_side = 0, res;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        max_side = max((max(x1, y2), max(x2, y2)), max_side);
        coords.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
    }

    LL l, r, mid;
    l = 0;
    r = max_side;

    while (l <= r) {
        mid = (l+r)/2;
        
        if(covers(mid)) {
           
            res = mid;
            r = mid -1;
        }

        else {
            l = mid + 1;
        }

    }

    cout << res <<endl;

    








    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long 

LL arr[100100] = {0};


bool split(LL max, LL nar, LL n) {
    LL sub = 1, sum = 0, pos = 0;

    while(pos < n) {
        if(arr[pos] > max) return false;


        sum += arr[pos];
        if(sum > max) {
            sub++;
            sum = arr[pos];
            if(sub > nar) return false;
        }


        pos++;
    }

    return sub <= nar;

}

int main() {
    LL n, k, x, max_num = 0, esum = 0;
    cin >> n >> k;
    LL res = 0;
    

    for(int i = 0; i<n; i++) {
        cin >> x;
        max_num = max(x, max_num);
        esum += x;
        arr[i] = x;
    }

    LL l,r,mid;
    l = max_num;
    r = esum;

    while(l <= r) {
        mid = l + (r - l) / 2;

        if(split(mid, k, n)) {
            r = mid - 1;
            res = mid;

        }

        else {
            l = mid + 1;

        }

    }

    cout << res << endl;


    return 0;
}
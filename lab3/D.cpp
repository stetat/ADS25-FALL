#include <iostream>
#include <vector>
#include <map>
#define LL long long

using namespace std;

vector<LL> numbers;
vector<int> sum_freqs;


int find_LB(LL x) {
    int pos = numbers.size();
    int l = 0, r = numbers.size() - 1, mid;

    while (l <= r) {
        mid = (l+r)/2;
        if(numbers[mid] >= x) {
            pos = mid;
            r = mid - 1;
        }

        else {
            l = mid + 1;
        }

    

    }

    return pos;

}


int find_RB(LL x) {
    int pos = numbers.size();
    int l = 0, r = numbers.size() - 1, mid;

    while (l <= r) {
        mid = (l+r)/2;
        if(numbers[mid] > x) {
            pos = mid;
            r = mid - 1;
        }

        else {
            l = mid + 1;
        }

    

    }

    return pos;

}




int main() {
    int n, q;
    map<LL, int> freqs;
    LL x, l1, r1, l2, r2, sum = 0;
    cin >> n >> q;


    for(int i = 0; i<n; i++) {
        cin >> x;
        freqs[x]++;
    }

    for(pair<LL, int> x : freqs) {
        numbers.push_back(x.first);
        sum += x.second;
        sum_freqs.push_back(sum);
    }

    int sz = numbers.size();

    for(int i = 0; i<q; i++) {
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = 0, pos_l1 = find_LB(l1), pos_r1 = find_RB(r1) - 1;

        if( pos_r1 >= 0 && pos_l1 <= pos_r1 && pos_l1 < sz) {
            if(pos_l1 == 0) {
                c1 = sum_freqs[pos_r1];
            }

            else {
                c1 = sum_freqs[pos_r1] - sum_freqs[pos_l1 - 1];
            }
        }

        int c2 = 0, pos_l2 = find_LB(l2), pos_r2 = find_RB(r2) - 1;

        if( pos_r2 >= 0 && pos_l2 <= pos_r2 && pos_l2 < sz) {
            if(pos_l2 == 0) {
                c2 = sum_freqs[pos_r2];
            }

            else {
                c2 = sum_freqs[pos_r2] - sum_freqs[pos_l2 - 1];
            }
        }


        int inter_c = 0;
        LL inter_l = l1;
        if (l2 > inter_l) inter_l = l2;
        LL inter_r = r2;
        if (r1 < inter_r) inter_r = r1;

        if(inter_l <= inter_r) {
            int pos_inter_l = find_LB(inter_l), pos_inter_r = find_RB(inter_r) - 1;

            if(pos_inter_l <= pos_inter_r && pos_inter_r >= 0 && pos_inter_l < sz) {
                if(pos_inter_l == 0) {
                    inter_c = sum_freqs[pos_inter_r];
                }

                else {
                    inter_c = sum_freqs[pos_inter_r] - sum_freqs[pos_inter_l - 1];
                }
            }

        }

        int res = c1 + c2 - inter_c;
        cout << res << endl;

    }



    return 0;
}

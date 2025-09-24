#include <iostream>

using namespace std;


#define LL long long

int main() {
    LL n, x, k, b, block, sum = 0;

    

    int l, r, mid;

    cin >> n >> k;
    int arr[n];
    int errors[k];
    for(int i = 0; i<n; i++) {
        cin >> x;
        sum += x;
        arr[i] = sum;
    }

    for(int i = 0; i<k; i++) {
        cin >> b;

        block = 0;
        l = 0;
        r = n - 1;

        while(l <= r) {
            mid = (l+r)/2;
            if(b <= arr[mid]) {
                block = mid + 1;
                r = mid - 1;
            }

            else {
                l = mid + 1;
            }

        }




        errors[i] = block;
    }


    for(int i = 0; i<k; i++) {
        cout << errors[i] << endl;
    }




    










    return 0;
}

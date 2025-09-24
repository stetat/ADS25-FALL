#include <iostream>

using namespace std;

int main() {
    int n, r, x, l1, r1, l2, r2;
    cin>>n>>r;
    int arr[n];
    int result[101] = {};

    for(int i = 0; i<n; i++) {
        cin >>x;
        arr[i]=x;
    }

    for(int i = 0; i<r; i++) {
        cin >> l1 >> r1 >> l2 >> r2;

        for(int j = 0; j<n; j++) {
            if ((l1 <= arr[j] && arr[j] <= r1) || (l2 <= arr[j] && arr[j] <= r2)){
                result[i]++;
            }

        }
    }

    for(int i = 0; i<r; i++) {
        cout << result[i] << endl;
    }








    return 0;
}
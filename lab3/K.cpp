#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x, tar, ps = 0;
    cin >> n >> tar;
    int arr[n];
    int pre_sums[n];

    for(int i = 0; i<n; i++) {
        cin >> x;
        ps += x;
        pre_sums[i] = ps; 
        arr[i] = x;
    }

    int l, r, mid, fix, els = n+1, sum = pre_sums[n-1] + 1;

    for(int i = 0; i<n; i++) {
        fix = arr[i];
        l = i;
        r = n - 1;

        

        int dif = 0;
        if ( i != 0 ) {
            dif = pre_sums[i-1];

        } 

        

        

        while( l <= r) {

           
            mid = (l+r)/2;

            

            if ( pre_sums[mid] - dif >= tar) {
               

                r = mid - 1;
        
                if(pre_sums[mid] - dif - fix >= tar) {
                    
                    els = min(els, mid - i);
                    sum = pre_sums[mid] - dif - fix;
                    
                    
                    
                }

                else {
                    els = min(els, mid + 1 - i);
                    sum = pre_sums[mid] - dif;
                }

                
            }

            else {
                l = mid + 1;
            }

            

        }
        

    }

    cout <<  els <<endl;

}
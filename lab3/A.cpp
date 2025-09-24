#include <iostream>
#include <vector>

using namespace std;



int main() {
    int k, x, n, m;
    cin >> k;
    int targets[k];
    int row[k];
    vector< pair<int,int> > result;

    for(int i = 0; i<k; i++) {
        cin >> x;
        targets[i] = x;
    }

    cin >> n >> m;
    int arr[n][m];
    int l,r, mid, ro, num;

    
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> x;
            arr[i][j] = x;
        }
    }

  

    for(int i = 0; i<k; i++) {
        num = targets[i];
        l = 0;
        r = n - 1;

        while (l <= r) {
            mid = (l+r)/2;
            if(mid % 2 == 0) {
                if (arr[mid][0] >= num && num >= arr[mid][m-1]) {
                    row[i] = mid;
                    break;
                }

                else if (num < arr[mid][m-1]) {
                    l = mid + 1;
                }

                else if (num > arr[mid][0]) {
                    r = mid - 1;

                }
            }

            else {
                if (arr[mid][0] <= num && num <= arr[mid][m-1]) {
                    row[i] = mid;
                    break;
                }

                else if (num > arr[mid][m-1]) {
                    r = mid - 1;
                }

                else if (num < arr[mid][0]) {
                    l = mid + 1;

                }

            
            }

            if(l > r) {
                row[i] = -1;
            }
          
        }

        
    }

    
    for(int i = 0; i<k; i++) {
        num = targets[i];
        ro = row[i];
        l = 0;
        r = m-1;

        while(l <= r) {
            if ( ro == -1) {
                result.push_back(make_pair(-1, -1));
                break;
            }
            mid = (l+r)/2;

            if(arr[ro][mid] == num) {
                result.push_back(make_pair(ro, mid));
                break;
            }

            else if (arr[ro][mid] > num) {
                if(ro % 2 == 0) {
                    l = mid + 1;
                }

                else {
                    r = mid - 1;
                }


            }

            else if (arr[ro][mid] < num) {
                if(ro % 2 == 0) {
                    r = mid - 1;
                }

                else {
                    l = mid + 1;
                }
            }


            if ( r < l) {
                result.push_back(make_pair(-1, -1));
            }
        }


    }


    for(pair<int,int> x : result) {
        if(x.first == -1) {
            cout << -1 << endl;
            continue;
        }

        cout << x.first << " " << x.second << endl;
    }








}
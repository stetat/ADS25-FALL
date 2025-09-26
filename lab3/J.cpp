#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

double bags[10100];
long long h;
int n;

bool steal(double x) {
    long long hours = 0;

    for(int i = 0; i < n; i++) {
        hours += ceil(bags[i]/x);

        if ( hours > h) {
            return false;
        }

    }


    return true;


}


int main() {
    double x, max_speed = 0, speed;
    cin >> n >> h;

    for(int i = 0; i<n; i++) {
        cin >> x;
        max_speed = max(max_speed, x);
        bags[i] = x;

    }

    long long l,r,mid;


    l = 0, r = max_speed;


    while(l <= r) {
        mid = (l+r)/2;
       

        if(steal(mid)) {
            speed = mid;
            r = mid - 1;
        }

        else {
            l = mid + 1;
        }


    }


    cout << (speed);



    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;

bool find(int x) {
    int l = 0;
    int r = numbers.size()-1;
    int mid;

    while(l <= r) {
        mid = (l+r)/2;
        if(numbers[mid] == x) {
            return true;
        }

        else if (numbers[mid] > x) {
            r = mid - 1;
        }

        else {
            l = mid + 1;
        }
    }
    return false;

}

int main() {
    int n,c, t;
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> c;
        numbers.push_back(c);
    }

    cin >> t;

    if(find(t)) {
        cout << "Yes";
    }

    else {
        cout << "No";
    }

}

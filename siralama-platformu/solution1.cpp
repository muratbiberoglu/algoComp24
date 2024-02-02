#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int column;
        cin >> column;
        arr.push_back(column);
    }
    long long count = 0;
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        count++;
        bool left = true;
        while(true){
            if(left && l > 0 && arr[l-1] < arr[r]){
                l--;
                left = false;
            }
            else if(!left && r < n-1 && arr[r+1] < arr[l]){
                r++;
                left = true;
            }
            else{
                break;
            }
            count++;
        }
    }

    cout << count;
    return 0;
}

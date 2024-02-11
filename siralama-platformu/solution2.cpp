    #include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define endl '\n'
#define INF __LONG_LONG_MAX__
using namespace std;

vector<int> nums;

long long solution(int index){
    int size = nums.size();
    int curr = nums[index];
    long long ans = 1;
    int next_index = index - 1;
    
    while(next_index >= 0 && next_index < size){
        int next = nums[next_index];
        if(next >= curr) break;
        curr = next;
        ans++;
        if(ans % 2 == 0) next_index += ans;
        else next_index -= ans;
    }
    return ans;
}

int32_t main() {
    fastio
    int n;
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    long long res = 0;
    for(int i = 0; i < n; i++){
        long long ans = solution(i);
        res += ans;
    }
    
    cout << res << "\n";

}
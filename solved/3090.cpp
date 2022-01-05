#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

ll make_smooth(vector<ll>& arr, ll smooth) {
    ll cnt = 0;
    for (ll i=0; i<arr.size()-1; i++) {
        if (arr[i]+smooth < arr[i+1]) {
            cnt += arr[i+1] - (arr[i]+smooth);
            arr[i+1] = arr[i]+smooth;
        }
    }
    for (ll i=arr.size()-1; i>0; i--) {
        if (arr[i]+smooth < arr[i-1]) {
            cnt += arr[i-1] - (arr[i]+smooth);
            arr[i-1] = arr[i]+smooth;
        }
    }
    return cnt;
}

void solve() {
    int N, T; cin>>N>>T;
    vector<ll> arr(N);
    for (int i=0; i<N; i++) {
        cin>>arr[i];
    }
    
    ll left = 0; ll right = 1000000000;
    ll cnt;
    while(left < right) {
        vector<ll> tmp(arr);
        ll mid = (left + right) / 2;
        cnt = make_smooth(tmp, mid);
        if(T < cnt) {
            left = mid + 1;
        } else {
            right = mid;
	    }
    }
    make_smooth(arr, left);
    for (int i=0; i<N; i++) {
        cout<<arr[i]<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void rev(vector<int>& arr, int s, int e) {
    if (s>=e) return;
    swap(arr[s], arr[e]);
    rev(arr, s+1, e-1);
}

bool valid(vector<int>& arr) {
    for (int i=2; i<arr.size()-1; i++) {
        if (arr[i-1] > arr[i]) return false;
    }
    return true;
}

vector<pair<int, int>> find_flip(vector<int> nums) {
    set<pair<int, int>> flips;
    for (int i=1; i<nums.size()-1; i++) {
        int num = nums[i];
        if (nums[i] != i) {
            if (nums[i] < i) flips.insert({nums[i], i});
            else flips.insert({i, nums[i]});
        }
    }
    return vector<pair<int, int>>(flips.begin(), flips.end());
}

vector<pair<int, int>> find_flip2(vector<int> nums) {
    int last = -1;
    int s = 0;
    vector<pair<int, int>> flips;
    for (int i=1; i<nums.size(); i++) {
        int num = nums[i];
        if (last == -1) {
            s = i;
        } else {
            if (num - last == 1 || last - num == 1) {
            } else {
                int e = i-1;
                if (nums[e] <= nums[s]) {
                    if (e < nums[e]) flips.push_back({e, nums[e]});
                    else flips.push_back({nums[e], e});
                    // cout<<s<<' '<<e<<' '<<flips[flips.size()-1].first<<' '<<flips[flips.size()-1].second<<endl;
                }
                s = i;
            }
        }
        last = num;
    }
    return flips;
}

void solve() {
    int N; cin>>N;
    vector<int> nums;
    nums.push_back(-1);
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        nums.push_back(x);
    }
    nums.push_back(-1);

    auto flips = find_flip(nums);
    if (flips.size() == 0) {
        cout<<"1 1"<<endl<<"1 1"<<endl;
    } else {
        int S = flips.size();
        vector<int> tmp(nums.begin(), nums.end());
        for (int i=0; i<S; i++) {
            rev(tmp, flips[i].first, flips[i].second);
            if (valid(tmp)) {
                cout<<flips[i].first<<' '<<flips[i].second<<endl<<"1 1"<<endl;
                return;
            }
            auto flips2 = find_flip2(tmp);
            int S2 = flips2.size();
            for (int j=0; j<S2; j++) {
                rev(tmp, flips2[j].first, flips2[j].second);
                if (valid(tmp)) {
                    cout<<flips[i].first<<' '<<flips[i].second<<endl<<flips2[j].first<<' '<<flips2[j].second<<endl;
                    return;
                }
                rev(tmp, flips2[j].first, flips2[j].second);
            }
            rev(tmp, flips[i].first, flips[i].second);
        }
        cout<<"???"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
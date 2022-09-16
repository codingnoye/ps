#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first<b.first;
    return a.second<b.second;
}

int main() {
    fastio;
    
    int R, C, K; cin>>R>>C>>K;

    vector<vector<int>> A(3, vector<int>(3));
    for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
            cin>>A[y][x];
        }
    }

    for (int i=0; i<=100; i++) {
        int Y = A.size();
        int X = A[0].size();
        if (R-1<Y && C-1<X && A[R-1][C-1] == K) {
            cout<<i<<endl;
            break;
        }
        if (i == 100) {
            cout<<"-1"<<endl;
            break;
        }

        if (Y >= X) {
            vector<map<int, int>> counters;
            for (int y=0; y<Y; y++) {
                map<int, int> counter;
                for (int x=0; x<X; x++) {
                    if (A[y][x] != 0) {
                        if (counter.find(A[y][x]) == counter.end()) counter[A[y][x]] = 0;
                        counter[A[y][x]]++;
                    }
                }
                counters.push_back(counter);
            }

            size_t maxsz = 0;
            for (auto& counter: counters) maxsz = max(maxsz, sz(counter));
            vector<vector<int>> B(Y, vector<int>(maxsz*2));

            for (int y=0; y<Y; y++) {
                vector<pair<int, int>> tmp(all(counters[y]));
                sort(all(tmp), cmp);
                for (int i=0; i<sz(tmp); i++) {
                    B[y][i*2] = tmp[i].first;
                    B[y][i*2+1] = tmp[i].second;
                }
            }
            A = B;
        } else {
            vector<map<int, int>> counters;
            for (int x=0; x<X; x++) {
                map<int, int> counter;
                for (int y=0; y<Y; y++) {
                    if (A[y][x] != 0) {
                        if (counter.find(A[y][x]) == counter.end()) counter[A[y][x]] = 0;
                        counter[A[y][x]]++;
                    }
                }
                counters.push_back(counter);
            }

            size_t maxsz = 0;
            for (auto& counter: counters) maxsz = max(maxsz, sz(counter));
            vector<vector<int>> B(maxsz*2, vector<int>(X));

            for (int x=0; x<X; x++) {
                vector<pair<int, int>> tmp(all(counters[x]));
                sort(all(tmp), cmp);
                for (int i=0; i<sz(tmp); i++) {
                    B[i*2][x] = tmp[i].first;
                    B[i*2+1][x] = tmp[i].second;
                }
            }
            A = B;
        }
    }
}
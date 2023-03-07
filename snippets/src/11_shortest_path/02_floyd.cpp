/*!
prefix: floyd
title: 플로이드-와샬
description: 모든 V<->V 최단거리, O(N^3)
!*/
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#ifdef ONLINE_JUDGE
    #define endl '\n'
#endif
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

//[
// G is N*N weighted adjmat
const int INF = 987654321;
vector<vector<int>> floyd(vector<vector<int>>& G) {
    int N = sz(G);
    vector<vector<int>> dists(G);
    for (int m=0; m<N; m++) { // 경유 노드
        for (int s=0; s<N; s++) { // 출발 노드
            for (int e=0; e<N; e++) { // 도착 노드
                if (s==e) continue;
                dists[s][e] = min(dists[s][e], dists[s][m] + dists[m][e]);
            }
        }
    }
    return dists;
}
//]
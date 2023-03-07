/*!
prefix: dijkstra
title: 다익스트라
description: 1<->V 최단거리, O((V+E) log V), 양방향 가능
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
typedef pair<int, int> pii;
const int INF = 987654321;

// G: weighted adjlist, graph[n] = [<neighbor of n, dist>]
vector<int> get_dist(vector<vector<pii>>& graph, int s) {
    int N = graph.size();
    vector<int> dist(N);
    vector<int> from(N);
    vector<bool> visited(N);
    for (int i=0; i<N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [nowd, now] = pq.top(); pq.pop();
        if (visited[now]) continue;
        for (auto [near, cost]: graph[now]) {
            if (visited[near]) continue;
            if (dist[near] > nowd + cost) {
                dist[near] = nowd + cost;
                from[near] = cost;
            }
            pq.push({dist[near], near});
        }
        visited[now] = true;
    }
    return dist;
}
//]
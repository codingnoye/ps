#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int H;
    int destLine;
    int destH;
};
const int MAX = 1000000001;
bool cmp (edge A, edge B) {
    return A.H<B.H;
}

vector<vector<edge>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K; cin>>N>>M>>K;
    graph.resize(N);
    while (M--) {
        int a, b, c; cin>>a>>b>>c;
        graph[a-1].push_back(edge{b, a, c});
        graph[a].push_back(edge{c, a-1, b});
    }
    for (int n=0; n<N; n++) {
        graph[n].push_back(edge{MAX, 0, 0});
        sort(graph[n].begin(), graph[n].end(), cmp);
    }
    vector<int> goal;
    goal.resize(N);
    for (int n=0; n<N; n++) {
        int nowLine = n;
        int height = 0;
        while (true) {
            auto x = lower_bound(graph[nowLine].begin(), graph[nowLine].end(), edge{height+1, 0, 0}, cmp);
            if ((*x).H==MAX) {
                goal[nowLine] = n;
                break;
            }
            //cout<<"jump "<<(nowLine+1)<<" -> "<<((*x).destLine+1)<<endl;
            nowLine = (*x).destLine;
            height = (*x).destH;
        }
    }
    for (int n=0; n<N; n++) cout<<(goal[n]+1)<<' ';
}
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

int N;
vector<vector<int>> mincase = {{9}};
vector<vector<int>> board;
vector<pair<int, int>> sizes;
vector<vector<pair<int, int>>> jogaks;

void place_jogak(int d) {
    // for (auto& row : board) {
    //     for (auto& cell : row) {
    //         cout<<cell;
    //     }
    //     cout<<endl;
    // }
    if (d == 5) {
        if (mincase > board) {
            mincase = vector<vector<int>>(board);
        }
        return;
    }

    if (board[0][0] != 0 && d < 5 && board[0] > mincase[0]) {
        return;
    }

    auto [yl, xl] = sizes[d];
    auto& jogak = jogaks[d];

    for (int ys=0; ys<N-yl+1; ys++) {
        for (int xs=0; xs<N-xl+1; xs++) {
            bool breaked = false;
            for (int i=0; i<jogak.size(); i++) {
                auto [y, x] = jogak[i];
                if (board[ys+y][xs+x] != 0) {
                    breaked = true;
                    swap(jogak[0], jogak[i]);
                    break;
                }
            }
            if (!breaked) {
                for (int i=0; i<jogak.size(); i++) {
                    auto [y, x] = jogak[i];
                    board[ys+y][xs+x] = d+1;
                }
                place_jogak(d+1);
                for (int i=0; i<jogak.size(); i++) {
                    auto [y, x] = jogak[i];
                    board[ys+y][xs+x] = 0;
                }
            }
        }
    }
}

int main() {
    fastio;
    
    cin>>N;
    board = vector<vector<int>>(N, vector<int>(N));

    int ncell = 0;
    for (int i=0; i<5; i++) {
        int yl, xl; cin>>yl>>xl;
        vector<pair<int, int>> jogak;
        for (int y=0; y<yl; y++) {
            string tmp; cin>>tmp;
            for (int x=0; x<xl; x++) {
                if (tmp[x] == '#') {
                    jogak.push_back({y, x});
                    ncell++;
                }
            }
        }
        sizes.push_back({yl, xl});
        jogaks.push_back(jogak);
    }

    if (ncell != N*N) {
        cout<<"gg"<<endl;
        return 0;
    }
    
    place_jogak(0);
    if (mincase[0][0] == 9) {
        cout<<"gg"<<endl;
    } else {
        for (auto& row : mincase) {
            for (auto& cell : row) {
                cout<<cell;
            }
            cout<<endl;
        }
    }
}
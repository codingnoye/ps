#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
using namespace std;

int arr[20][20] = {0};
int N;

vector< pair<int, int> > synergy;

int cabs(int a) {
    return a<0?-a:a;
}

int mn = 999999999;

int calc(int mask) {
    int val = 0;
    for (auto it=synergy.begin(); it!=synergy.end(); it++) {
        if ((mask | (*it).first) == mask) {
            val += (*it).second;
        }
    }
    return val;
}
void perm(int depth, int now, int ones, int mask) {
    if (depth - now == ones) {
        mask<<=ones;
        mask += (1<<ones)-1;
        mn = min(cabs(calc(mask) - calc((1<<N)-1-mask)), mn);
        return;
    }
    perm(depth, now+1, ones, mask<<1);
    if (ones>=1) perm(depth, now+1, ones-1, (mask<<1)+1);
}
int main() {
    cin>>N;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin>>arr[y][x];
        }
    }
    for (int y=0; y<N; y++) {
        for (int x=y+1; x<N; x++) {
            int mask = (1<<x) + (1<<y);
            int val = arr[y][x] + arr[x][y];
            synergy.push_back(make_pair(mask, val));
        }
    }
    perm(N, 0, N/2, 0);
    cout<<mn<<endl;
}
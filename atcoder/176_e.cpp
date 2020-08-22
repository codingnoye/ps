#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[300001][300001] = {0};
int cntH[300001] = {0};
int cntW[300001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W, M; cin>>H>>W>>M;
    for (int i=0; i<M; i++) {
        int h, w; cin>>h>>w;
        arr[h][w] = 1;
        cntH[h]++;
        cntW[w]++;
    }

    vector<int> maxH;
    int mxh = 0;
    vector<int> maxW;
    int mxw = 0;
    for (int i=0; i<300001; i++) {
        int h = cntH[i];
        mxh = max(h, mxh);
    }
    for (int i=0; i<300001; i++) {
        int w = cntW[i];
        mxw = max(w, mxw);
    }
    for (int i=0; i<300001; i++) {
        int h = cntH[i];
        if (h==mxh) maxH.push_back(i);
    }
    for (int i=0; i<300001; i++) {
        int w = cntW[i];
        if (w==mxw) maxW.push_back(i);
    }
    int res = 0;
    for (int i=0; i<maxH.size(); i++) {
        
    }
}
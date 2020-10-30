#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int query(int* tree, int* pows, long long* h, int N, int i, int s, int e) {
    int ns = pows[i] * (i-N/pows[i]);
    int ne = ns + pows[i] - 1;
    int m1, m2;
    if (s<=ns && ne<=e) {
        return tree[i];
    } else if (e<ns || ne<s) {
        return N;
    }
    m1 = query(tree, pows, h, N, i*2, s, e);
    m2 = query(tree, pows, h, N, i*2+1, s, e);
    return h[m1]<h[m2]?m1:m2;
}
long long largest(int* tree, int* pows, long long* h, int N, int s, int e) {
    int mini = query(tree, pows, h, N, 1, s, e);
    long long minh = h[mini];
    long long s1 = (e-s+1) * minh;
    if (s>=e) {
        return s1;
    }
    long long s2 = largest(tree, pows, h, N, s, mini-1);
    long long s3 = largest(tree, pows, h, N, mini+1, e);
    return max({s1, s2, s3});
}
int tree[400001];
int pows[400001];
long long h[300001];
int main() {
    int n; cin>>n;
    int N, L;
    for (N=1, L=0; N<n; N*=2, L++);
    // pows 배열 초기화
    for (int l=L; l>=0; l--) {
        int p = (int) pow(2, l);
        for (int i=N/p; i<2*N/p; i++) {
            pows[i] = p;
        }
    }
    h[N] = 1000000001;
    // 입력 받아 높이배열에 저장
    for (int i=0; i<n; i++) {
        cin>>h[i];
    }
    // 트리 최하위 층 초기화
    for (int i=N; i<2*N; i++) {    
        tree[i]=i-N;
    }
    // 세그먼트 트리 빌드
    for (int i=N-1; i>=1; i--) {
        tree[i] = h[tree[i*2]]<h[tree[i*2+1]]?tree[i*2]:tree[i*2+1];
    }
    // 
    cout<<largest(tree, pows, h, N, 0, N-1)<<endl;
}
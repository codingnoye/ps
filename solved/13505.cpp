#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef unsigned long long ll;

struct TNode {
    ll val = 0;
    vector<TNode> childs;
};

TNode root;

const int max_b = 31;

ll bit(ll a) {
    if (a==0) return 0;
    return 1;
}

int main() {
    fastio;
    
    int N; cin>>N;

    vector<ll> inputs;
    for (int i=0; i<N; i++) {
        ll x; cin>>x;
        inputs.push_back(x);
        int c = max_b;
        TNode* now2 = &root;
        while (c>=0) {
            ll m2 = 1<<c;
            if ((now2->childs.size() == 0) ||
                (now2->childs.size() == 1 && ((now2->childs[0].val) != bit(m2 & x))) ||
                (now2->childs.size() == 2 && ((now2->childs[0].val) != bit(m2 & x)) && ((now2->childs[1].val) != bit(m2 & x)))
            ) {
                // cout<<"Add "<<c-1<<" "<<(((x & m2))?1ULL:0ULL)<<endl;
                now2->childs.push_back(TNode{bit(x & m2)});
                now2 = &(now2->childs[now2->childs.size()-1]);
            } else {
                if ((now2->childs[0].val) == (bit(m2 & x))) {
                    now2 = &(now2->childs[0]);
                } else {
                    now2 = &(now2->childs[1]);
                }
            }
            c--;
        }
    }

    ll maxdiff = 0;
    for (int i=0; i<N; i++) {
        ll x = inputs[i];
        TNode* now = &root;
        ll diff = 0;
        
        for (int b=max_b; b>=0; b--) {
            ll m = 1<<b;

            // cout<<"b "<<b<<" bit "<<((x & m)?1:0)<<" childs: ";
            // if (now->childs.size()>=1) cout<<now->childs[0].val<<' ';
            // if (now->childs.size()>=2) cout<<now->childs[1].val<<' ';
            // cout<<endl;
            
            // cout<<((x & (m)))<<' ';
            if (now->childs.size() == 1) {
                // cout<<"case1"<<endl;
                if (bit(x & (m)) != now->childs[0].val) {
                    diff += m;
                }
                now = &(now->childs[0]);
            } else {
                diff += m;
                if (((x & (m)) == 0)) { // 비트가 0이므로, 1인 child로 가야함
                    if (now->childs[1].val == 1)
                        now = &(now->childs[1]);
                    else
                        now = &(now->childs[0]);
                }
                else {
                    if (now->childs[1].val == 1)
                        now = &(now->childs[0]);
                    else
                        now = &(now->childs[1]);
                }
            }
        }
        maxdiff = max(diff, maxdiff);
    }
    cout<<maxdiff<<endl;
}
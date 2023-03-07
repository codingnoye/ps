/*!
prefix: comp
title: 좌표압축
description: 좌표압축 (justicehui)
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
vector<ll> comp(vector<ll>& v_origin) {
    vector<ll> v(v_origin);
    vector<ll> tmp(v);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (auto &i: v) {
        i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
    }
    return v;
}
//]
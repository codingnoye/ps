/*!
prefix: aid
title: Auto id
description: T -> int 매핑
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
template <typename T> class Aid {
public:
    map<T, int> kv;
    int i = 0;
    int operator[](T key) {
        auto found = kv.find(key);
        if (found == kv.end()) {
            kv[key] = i;
            return i++;
        }
        return found->second;
    }
};
//]
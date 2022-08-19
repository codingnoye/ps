#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#include "bits/stdc++.h"
#include "ext/rope"
 
using namespace std;
using namespace __gnu_cxx;
 
using ll = long long;
using pii = pair<int, int>;
 
int n;
pii home, office;
vector<pii> vec;
int mxx, mnx;
int homey, officey;
 
void solve()
{
  cin >> n;
  cin >> home.first >> home.second;
  cin >> office.first >> office.second;
  if (home > office) swap(home, office);
  mnx = home.first;
  mxx = office.first;
  homey = home.second;
  officey = office.second;
 
  int sign;
  if (homey <= officey) sign = 1;
  else sign = -1;
 
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    if (x < mnx or x > mxx) continue;
    if (y > max(homey, officey) or y < min(homey, officey)) continue;
    vec.push_back({x, y * sign});
  }
 
  if (vec.empty())
  {
    cout << 0;
    return;
  }
 
  sort(vec.begin(), vec.end(), [](pii &l, pii &r) {
    if (l.first != r.first) return l.first < r.first;
    return l.second > r.second;
  });
 
  vector<int> lis;
  lis.push_back(vec[0].second);
  for (int i = 1; i < vec.size(); i++)
  {
    int val = vec[i].second;
    if (val >= lis.back())
    {
      lis.push_back(val);
    }
    else
    {
      auto it = lower_bound(lis.begin(), lis.end(), val);
      *it = val;
    }
  }
 
  cout << lis.size();
}
 
int main()
{
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
 
  solve();
}
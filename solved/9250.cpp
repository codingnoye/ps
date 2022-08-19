#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAXN = 100005, MAXC = 26;
int trie[MAXN][MAXC], fail[MAXN], term[MAXN], piv;
void init(vector<string> &v){
	memset(trie, 0, sizeof(trie));
	memset(fail, 0, sizeof(fail));
	memset(term, 0, sizeof(term));
	piv = 0;
	for(auto &i : v){
		int p = 0;
		for(auto &j : i){
			if(!trie[p][j]) trie[p][j] = ++piv;
			p = trie[p][j];
		}
		term[p] = 1;
	}
	queue<int> que;
	for(int i=0; i<MAXC; i++){
		if(trie[0][i]) que.push(trie[0][i]);
	}
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(int i=0; i<MAXC; i++){
			if(trie[x][i]){
				int p = fail[x];
				while(p && !trie[p][i]) p = fail[p];
				p = trie[p][i];
				fail[trie[x][i]] = p;
				if(term[p]) term[trie[x][i]] = 1;
				que.push(trie[x][i]);
			}
		}
	}
}
bool query(string &s){
	int p = 0;
	for(auto &i : s){
		while(p && !trie[p][i]) p = fail[p];
		p = trie[p][i];
		if(term[p]) return 1;
	}
	return 0;
}

int main() {
    fastio;
    
    vector<string> aho_v;
    int N; cin>>N;
    for (int i=0; i<N; i++) {
        string s; cin>>s;
        for (char& c: s) {
            c -= 'a';
        }
        aho_v.push_back(s);
    }
    init(aho_v);
    
    int Q; cin>>Q;
    while (Q--) {
        string s; cin>>s;
        for (char& c: s) {
            c -= 'a';
        }
        cout<<(query(s)?"YES":"NO")<<endl;
    }
}
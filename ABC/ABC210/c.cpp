#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc210/tasks/abc210_c
// セグメント木でいける気もするが制約が怪しい
// しゃくとり法で O(N)
int c[300005];
void solve(){ 
    int N,K; cin >> N >> K;
    CINA(c,N);
    map<int,int> mp;
    int left = 0;
    int right = 0;
    int ans = 0;
    int cand = 0;
    while(right<K){
        int color = c[right];
        ++mp[ color ];
        if(mp[ color ]==1) ++cand;
        ++right;
    }
    ans = cand;
    while(right<N){
        dprint(right);
        int color = c[left];
        --mp[ color ];
        if(mp[color]==0) --cand;
        ++left;
        int dolor = c[right];
        ++mp[ dolor ];
        if(mp[dolor]==1) ++cand;
        ++right;
        chmax(ans,cand);
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
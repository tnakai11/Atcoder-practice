#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_b
// 値の範囲が狭いので map してから総当たりでいける
void solve(){ 
    int N,M; cin >> N >> M;
    map<int,int> mp;
    REP(i,N){
        int a; cin >> a;
        ++mp[a];
    }
    REP(j,M){
        int b; cin >> b;
        ++mp[b];
    }
    vector<int> ans;
    REP(x,1005){
        if(mp[x]==1) ans.emplace_back(x);
    }
    int S = ans.size();
    REP(i,S){
        cout << ans[i] << (i!=S?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
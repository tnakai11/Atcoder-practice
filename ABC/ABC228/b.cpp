#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc228/tasks/abc228_b
// 順番に辿ろう

void solve(){ 
    int N,X; cin >> N >> X;
    vector<int> a(N);
    --X;
    REP(i,N){
        cin >> a[i];
        --a[i];
    }
    int ans = 0;
    map<int,int> mp;
    int next = X;
    while(mp[next]==0){
        ++ans;
        mp[next] = 1;
        next = a[next];
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
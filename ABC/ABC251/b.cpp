#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc251/tasks/abc251_b
// 全探索は O(N^3). N<300 より一応OK
int N,W; 
map<int,int> mp;
int ans = 0;
bool put(int x){
    if(x>W) return false;
    if(mp[x]==0){
        ++ans;
        ++mp[x];
    }
    return true;
}
void solve(){ 
    cin >> N >> W;
    vector<int> a(N); REP(i,N) cin >> a[i];
    REP(i,N){
        if(!put(a[i])) continue;
        for(int j=i+1;j<N;++j){
            if(!put(a[i]+a[j])) continue;
            for(int k=j+1;k<N;++k){
                if(!put(a[i]+a[j]+a[k])) continue;
            }
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
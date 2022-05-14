#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc245/tasks/abc245_b
// A に出現する数を map で控えておいて 0 から調べていく
// 計算量は O(N log N)
void solve(){ 
    int N; cin >> N;
    map<int,int> mp;
    REP(i,N){
        int a; cin >> a;
        mp[a]=1;
    }
    int ans = -1;
    REP(i,3000){
        if(mp[i]==0){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
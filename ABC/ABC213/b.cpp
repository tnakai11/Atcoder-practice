#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc213/tasks/abc213_b
// ソートして調べれば O(N log N)
// トップ2を控える方針だと O(N)
struct ply {
    int scr,num;
};
bool func(ply a,ply b){
    return a.scr > b.scr;
}
void solve(){ 
    int N; cin >> N;
    ply p[N];
    REP(i,N){
        cin >> p[i].scr;
        p[i].num = i+1;
    }
    sort(p,p+N,func);
    cout << p[1].num << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
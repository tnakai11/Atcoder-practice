#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc235/tasks/abc235_b
// 愚直にシミュレーションでOK
int h[100005];
void solve(){ 
    int N; cin >> N;
    CINA(h,N);
    int ans = -1;
    REP(i,N){
        if(ans<h[i]){
            ans = h[i];
        }else{
            break;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
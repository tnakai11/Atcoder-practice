#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc251/tasks/abc251_d
// n = a + b + c
// n = 1 は a=1 でしか作れない
// n = 2 は a=2 or a=b=1 でしか作れないが後者の場合覆える範囲が狭い
// 重複を作らないように下から構成すれば多分いける
// 愚直に書くと W=1000程度が限界っぽい
// B の個数判定と同じ方法を使うのはどうか
// O(N^3) でいけそう
// N<=300 の制約を越えた...
// a * 10^5 + b* 10^4 + c* 10^3 + d * 10^2 + e * 10^1 + f  ... <10*6 個のおもりから6個以下選ぶ
// a * 10^4 + d * 10^2 +  f  ... < 100*3 個のおもりから3個以下選ぶ
void solve(){ 
    int W = 1000000;
    vector<int> ans;

    ans.emplace_back(1);
    for(int x=1;x<=99;++x){
        ans.emplace_back(x);
        ans.emplace_back(x*100);
        ans.emplace_back(x*10000);
    }
    sort(ALL(ans));

    int N = ans.size();
    cout << N << '\n';
    REP(i,N) cout << ans[i] << (i<N-1?' ':'\n');
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
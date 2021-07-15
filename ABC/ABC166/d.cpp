#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc166/tasks/abc166_d
// A^5 - B^5 = X
// (n+1)^5 - n^5 ~ n^4 より n = 10^3 以上で X が満たされることはない
// 全探索で通せる
void solve(){ 
    ll X; cin >> X;
    for(ll a=1;a<1000;++a){
        for(ll b=-1000;b<1000;++b){
           if(a*a*a*a*a-X==b*b*b*b*b){
               cout << a << ' ' << b << '\n';
               return;
           } 
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
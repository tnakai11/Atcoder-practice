#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/arc143/tasks/arc143_a
// 7,5,5
// 5,5,3
// 3,3,3
// 0,0,0

// A>=B>=C とする
// A=BとなるまでA,Cを削る
// A=B=CとなるまでA,Bを削る
// A=B=C=0となるまでA,B,Cを削る
// 全操作でAを削っているので途中でこけなければAが答え

ll solve(){ 
    vector<ll> v(3); CINA(v,3);
    sort(ALL(v),greater<ll>());
    ll A = v[0];
    ll B = v[1];
    ll C = v[2];

    ll dif = A - B;
    if(dif>C) return -1;

    return A;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  cout << solve() << '\n';
  return 0;
}
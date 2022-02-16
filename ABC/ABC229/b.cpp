#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
#define Liny "Yes\n"
#define Linn "No\n"
#define ll long long
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc229/tasks/abc229_b
// 1桁目から順に見ていけばOK
void solve(){ 
    ll A,B; cin >> A >> B;
    string ans = "Easy";
    while(A>0 && B>0){
        ll check = A%10 + B%10;
        if(check/10>0){
            ans = "Hard";
            break;
        }
        A /= 10;
        B /= 10;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}

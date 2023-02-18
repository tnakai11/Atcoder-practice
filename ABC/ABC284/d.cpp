#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc284/tasks/abc284_d
// x = min(p,q) とすると
// x^3 < 9 * 10^18
// x < 9^(1/3) * 10^6
// よって O(T N^(1/3))で全問解ける
void solve(){ 
    int T; cin >> T;
    REP(t,T){
        ll N; cin >> N;
        ll p,q;
        for(ll x=2;x<=3*pow(10,6);++x){
            if(N%x>0) continue;
            if(N%(x*x)==0){
                p = x;
                q = N/x/x;
            }else{
                p = sqrt(N/x);
                q = x;
            }
            break;
        }
        cout << p << ' ' << q << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
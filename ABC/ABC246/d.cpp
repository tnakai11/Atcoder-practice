#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc246/tasks/abc246_d
// a^3 + a^2 b + a b^2 + b^3
// 対称式ではある
// aの全探索 + binary search
const ll MAX = pow(10,6);
const ll DEF = -1;
ll N; 
ll chAns(ll ans, ll cand){
    if(ans==-1) return cand;
    if(ans > cand) return cand;
    return ans;
}
ll func(ll a, ll b){
    return a*a*a + a*a*b + a*b*b + b*b*b;
}
bool isOK(ll a,ll b){
    return func(a,b)>=N;
}
ll bs(ll a){
    ll ng = -1;
    ll ok = MAX;

    while( abs(ok - ng) > 1){
        ll mid = (ok + ng)/2;
        if(isOK(a,mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

void solve(){ 
    cin >> N;
    ll ans = DEF;
    for(ll a=0;a<=MAX;++a){
        ll b = bs(a);
        if(a>b) break;
        ans = chAns(ans, func(a,b) );
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
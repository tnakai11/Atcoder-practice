#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
// https://atcoder.jp/contests/abc272/tasks/abc272_c
// 偶数 を和で作り出す方法
// - 偶数 + 偶数
// - 奇数 + 奇数
// 偶奇で数を仕分けてそれぞれソート
// 計算量は O(NlogN)
ll func(vector<ll> v){
    if(v.size()<2) return -1;
    return v[0] + v[1];
}
void solve(){ 
    int N; cin >> N;
    vector<ll> v,w;
    REP(i,N){
        ll a; cin >> a;
        if(a%2){
            v.emplace_back(a);
        }else{
            w.emplace_back(a);
        }
    }
    sort(ALL(v), greater<ll>());
    sort(ALL(w), greater<ll>());
    ll ans = max(func(v),func(w));
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
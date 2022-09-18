#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc269/tasks/abc269_c
// 0~2^60の全探索は無理
// 実験
// x1 ... 100011001
// x2 ... 110011100
// N ...  111011101
// N の1となる位について0 or 1 を取る値を全列挙
// 2^15 < 4^8 = 16^4 < 20^4 = 1.6*10^5 より十分間に合う
// long long のビット演算に注意
set<ll> ans;
ll N;
ll K = 60;
void func(ll value, ll k){
    if(k==K){
        ans.insert(value);
        return;
        }
    if((N>>k)&1LL){
        func((ll)(value | (1LL<<k)), k+1);
        func((ll)(value & ~(1LL<<k)), k+1);
    }else{
        func(value, k+1);
    }
}

void solve(){ 
    cin >> N;
    func(0LL, 0LL);
    for(ll e: ans){
        cout << e << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
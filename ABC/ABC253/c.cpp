#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc253/tasks/abc253_c
// 値と個数の組を管理する
// map で書けそう
void solve(){ 
    int Q; cin >> Q;
    map<ll,ll> mp;
    REP(q,Q){
        int number; cin >> number;
        if(number==1){
            ll x; cin >> x;
            ++mp[x];
        }else if(number==2){
            ll x,c; cin >> x >> c;
            mp[x] -= c;
            if(mp[x]<=0){
                mp.erase(x);
            }
        }else{
            ll x = mp.begin()->first;
            ll y = mp.rbegin()->first;
            cout << y - x << '\n';
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
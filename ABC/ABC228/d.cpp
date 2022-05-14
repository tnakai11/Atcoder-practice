#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc228/tasks/abc228_d
// いまいちピンとこないのでわかるところを書いてみる
// -1 の置き換えと各位置の値の確認
// hをいちいちインクリメントすると t=1,x=1 を連打された場合 O(Q^2) 
// 置き換え可能位置の set を控えれば O(Q log N) で通せそう
const int N = 1048576; //pow(2,20);
void solve(){ 
    int Q; cin >> Q;
    ll a[N]; REP(i,N) a[i] = -1;
    set<int> s; REP(i,N) s.insert(i);
    REP(count,Q){
        ll t,x; cin >> t >> x;
        if(t==1){
            ll h = x%N;
            auto itr = s.upper_bound(h-1);
            if(itr == s.end()){
                itr = s.upper_bound(-1);
            }
            dprint(*itr);
            a[*itr] = x;
            s.erase(itr);
        }else{
            ll h = x % N;
            cout << a[h] << '\n';
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
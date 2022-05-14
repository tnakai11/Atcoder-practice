#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc247/tasks/abc247_d
// ボールを一個ずつ入れるとO(Qc) で大変そう 
// ボールを箱単位で管理すれば高々O(Q)ですむ
struct box {
    ll x,c;
};
void solve(){ 
    vector<box> v;
    int Q; cin >> Q;
    int index = 0;
    REP(count,Q){
        int order; cin >> order;
        if(order==1){
            ll x,c; cin >> x >> c;
            box b = {x,c};
            v.emplace_back(b);
        }else{
            ll c; cin >> c;
            ll ans = 0;
            while(c>0){
                ll num = min(c,v[index].c);
                ans += num * v[index].x;
                c -= num;
                v[index].c -= num;
                if(v[index].c==0) {
                    ++index;
                }
            }
            cout << ans << '\n';
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc230/tasks/abc230_d
// - 右端の座標が小さい順でソート
// - 右端を掠るようにパンチ (+D-1右側以内に存在する壁ごと消去)
// で無駄なくいけそう
struct wall{
    ll l,r;
};
bool func(wall a, wall b){
    if(a.r==b.r) return a.l < b.l;
    return a.r < b.r;
}

void solve(){ 
    ll N,D; cin >> N >> D;
    vector<wall> v(N);
    REP(i,N) cin >> v[i].l >> v[i].r;
    sort(ALL(v),func);
    ll ans = 0;
    int index = 0;
    while(1){
        wall w = v[index];
        ++ans;

        ll lim = w.r + D - 1;
        while(index<N && v[index].l<=lim){
            ++index;
        }
        if(index>=N) break;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
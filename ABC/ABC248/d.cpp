#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc248/tasks/abc248_d
// 値ごとに位置の set を控えておけば2分探索でいけそう
// v ... set_X に含まれる l 以上の数のうち最小のもの
// w ... set_X に含まれる r より大きい数のうち最小のもの
// index(w) - index(v) 
/// ...(l)v...(r)w.. 
const int MAX = 200005;
vector<int> vs[MAX];
void solve(){ 
    int N; cin >> N;
    REP(i,N){
        int a; cin >> a;
        vs[a].emplace_back(i);
    }
    int Q; cin >> Q;
    REP(count,Q){
        int L,R,X; cin >> L >> R >> X;
        --L; --R;
        if(vs[X].size()==0){
            cout << 0 << '\n';
            continue;
        }
        auto vitr = lower_bound(ALL(vs[X]),L);
        auto witr = lower_bound(ALL(vs[X]),R+1);
        int ans = witr - vitr;
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
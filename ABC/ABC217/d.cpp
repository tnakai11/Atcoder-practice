#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc217/tasks/abc217_d
// 愚直に調べると O(LQ) で厳しい
// 距離が一番近い切り込みを探す
// ソート済みだと楽
// ソート済みリストを維持できれば何とかなる
// 平衡二分探索木

void solve(){ 
    int L,Q; cin >> L >> Q;
    set<int> st;
    st.insert(0);
    st.insert(L);
    REP(count,Q){
        int c,x; cin >> c >> x;
        if(c==1){
            st.insert(x);
        }else{
            auto it = st.lower_bound(x);
            int ans = *it - *prev(it);
            cout << ans << '\n';
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int,int>
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc213/tasks/abc213_c
// 座標圧縮
void solve(){ 
    int H,W,N; cin >> H >> W >> N;
    vector<pii> card(N);
    vector<int> v(N),w(N);
    REP(i,N){
        int a,b; cin >> a >> b;
        card[i].first = a;
        card[i].second = b;
        v[i] = a;
        w[i] = b;
    }
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    sort(ALL(w));
    w.erase(unique(ALL(w)),w.end());

    REP(i,N){
        int a = card[i].first;
        int b = card[i].second;
        int he = distance(v.begin(),lower_bound(ALL(v),a))+1;
        int wi = distance(w.begin(),lower_bound(ALL(w),b))+1;
        cout << he << ' ' << wi << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
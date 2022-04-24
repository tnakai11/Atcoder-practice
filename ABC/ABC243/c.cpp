#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc243/tasks/abc243_c
// Y座標ごとにまとめて考えれば O(N) でなんとかなりそう
// a:一番右のL と b:一番左のR について
// a<b ならば衝突なし
// b<a ならば衝突
struct line {
    int rightestL = -1;
    int leftestR = 1e9 + 1;
};
int x[200005];
int y[200005];
map<int, line> mp;
set<int> st;
void solve(){ 
    int N; cin >> N;
    REP(i,N) cin >> x[i] >> y[i];
    string s; cin >> s;
    REP(i,N){
        st.insert(y[i]);
        if(s[i]=='L'){
            chmax(mp[ y[i] ].rightestL, x[i]);
        }else{
            chmin(mp[ y[i] ].leftestR, x[i]);
        }
    }
    bool collision = false;
    for(int e:st){
        if( mp[e].rightestL < mp[e].leftestR ) continue;
        collision = true;
    }
    cout << (collision?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc165/tasks/abc165_c
// 再帰でいけそうだが愚直に探索すると O(N^M) となり難しい
// 大小関係を使えば
// 調べる数列のパターンは 
// H(M,N) = C(M+N-1,N) <= C(19,10) < 10^5 でたぶん間に合う 
int a[55],b[55],c[55],d[55];
vector<int> v(20,0);
int N,M,Q; 
int ans = 0;

void dfs(int index,int pre){
    if(index==N){
        int cand = 0;
        REP(i,Q){
            if( v[ b[i] ] - v[ a[i] ]== c[i] ) cand += d[i];
        }
        chmax(ans,cand);
        dprint(cand);
        return;
    }
    for(int value = pre;value<=M;++value){
        v[index] = value;
        dfs(index+1,value);
    }
}

void solve(){ 
    cin >> N >> M >> Q;
    REP(i,Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];
        --b[i];
    }
    dfs(0,1);
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
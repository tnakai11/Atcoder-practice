#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
// https://atcoder.jp/contests/abc268/tasks/abc268_c
// 0 or 1 or 2 の位置に p1 があると加点
// 1 or 2 or 3 の位置に p2 があると加点
// 全パターンを愚直に検証すると O(N^2) かかり間に合わない
// 並び順から最大値パターンを構築する方法はないか

// 解説を読む

// 操作回数は0~N-1の間で十分
// 操作回数がkのときの加点数を数え上げる

int N;
int p[200005];
int c[200005];
bool good(int table, int plate){
    vector<int> v = { (plate-1+N)%N, plate, (plate+1)%N };
    for(int e:v){
        if(table==e) return true;
    }
    return false;
}
void solveSimply(){
    int ans = 0;
    REP(start,N){
        int cand = 0;
        int table = 0;
        while(table<N){
            if(good(table,p[(start+table)%N])) ++cand;
            ++table;
        }
        chmax(ans, cand);
    }
    cout << ans << '\n';
}
void solve(){ 
  REP(i,N) c[i] = 0;
  REP(h,N) {
    int plate = p[h];
    for(int i=-1;i<=1;++i){
        int k = (plate-(h+i)+N)%N;
        ++c[k];
    }
  }
  int ans = 0;
  REP(k,N) chmax(ans,c[k]);
  cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  cin >> N;
  CINA(p,N);
  if(DEBUG) solveSimply();
  solve();
  return 0;
}
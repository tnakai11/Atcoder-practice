#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/typical90/tasks/typical90_a
// 切り方全パターンを試すと O( N COM(N,K) ) となり厳しい
// 最良のスコアは L/(K+1) だから
// なるべく近づければOK...?
// 上手くいかない

// 一本道のグラフから点を除いていく操作...?
// よく分からない

// 解説を読んだ
// 答えを二分探索 O(N log L)
// めぐる式(https://qiita.com/drken/items/97e37dd6143e33a64c8c)で書いてみる

int a[100005];
int x[100005];
int N,L,K;
bool isOK(int target){
  int lumber = 0;
  int l = 0;
  REP(i,N+1){
    l += x[i];
    if(l>=target){
      ++lumber;
      l=0;
    }
  }
  return lumber>=K+1;
}
void solve(){ 
  cin >> N >> L >> K;
  CINA(a,N);
  a[N]=L;

  x[0]=a[0];
  for(int i=1;i<=N;++i){
    x[i] = a[i]-a[i-1];
  }

  int ng=L;
  int ok=1;
  while( abs(ok-ng) > 1){
    int mid = (ok+ng)/2;
    if(isOK(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
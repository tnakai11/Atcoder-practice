#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc258/tasks/abc258_a
// 21:00 + K(0<=K<=100) = HH:MM
// HH = 21 + K//60
// MM = K%60
// Kの範囲が狭いので日を跨いだ場合は考慮しなくてOK
// 考慮する場合は HH %= 24
void solve(){ 
    int K; cin >> K;
    int h = 21 + K/60;
    int m = K%60;
    printf("%02d:%02d\n",h,m);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
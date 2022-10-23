#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc271/tasks/abc271_a
// 進数の変換
// A = x*16 + y
// printf あたりでどうにかできそうな気もする
// できた https://marycore.jp/prog/c-lang/format-binary-octal-decimal-hex/
void solve(){ 
    int N; cin >> N;
    printf("%02X\n",N);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
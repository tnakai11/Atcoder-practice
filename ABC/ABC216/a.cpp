#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc216/tasks/abc216_a
// 入力の読み取りを少し工夫する必要がある
// '.' でスプリットするのもアリだがやや面倒
void solve(){ 
    int X,Y;
    scanf("%d.%d",&X,&Y);
    string sign = "+";
    if(Y<=2){
        sign = "-";
    }else if(Y<=6){
        sign = "";
    }
    cout << X << sign << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
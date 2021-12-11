#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc226/tasks/abc226_a
// 誤差が怖いので整数部分と小数部分を別々に読み込んで処理する
void solve(){ 
    int a,b;
    scanf("%d.%d",&a,&b);
    if(b>=500){
        ++a;
    }
    cout << a << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}
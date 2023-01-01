#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc278/tasks/abc278_b
// 高々24*60 パターン調べればOK
int H,M; 
void countUp(){
    ++M;
    if(M>=60){
        M %= 60;
        ++H;
    }
    if(H>=24){
        H %= 24;
    }
}
bool isDifficult(int h, int m){
    int a = h/10;
    int b = h%10;
    int c = m/10;
    int d = m%10;
    int x = a*10+c;
    int y = b*10+d;
    return (0<=x && x<=23) && (0<=y && y<=59);
}
void solve(){ 
    cin >> H >> M;
    int temp = 10000;
    while(--temp){
        if(isDifficult(H,M)){
            break;
        }
        countUp();
    }
    cout << H << ' ' << M << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
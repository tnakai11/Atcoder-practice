#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc267/tasks/abc267_b
// まずはs[0] が倒れているかどうか見る
// 倒れている場合は各列の立っているピン数を数えて調査
int stand(char c){
    return c == '1';
}
void solve(){ 
    string s; cin >> s;
    if(s[0]=='1'){
        cout << Linn;
        return;
    }
    int M = 7;
    int c[M];
    REP(i,M) c[i] = 0;
    c[0] = stand(s[6]);
    c[1] = stand(s[3]);
    c[2] = stand(s[1]) + stand(s[7]);
    c[3] = stand(s[0]) + stand(s[4]);
    c[4] = stand(s[2]) + stand(s[8]);
    c[5] = stand(s[5]);
    c[6] = stand(s[9]);
    int su = 0;
    REP(i,M){
        su += c[i];
    }
    if(su<=1){
        cout << Linn;
        return;
    }
    int l = -1;
    REP(i,M){
        if(c[i]>0) {
            l = i;
            break;
        }
    }
    int r = -1;
    for(int i=M-1;i>=0;--i){
        if(c[i]>0){
            r = i;
            break;
        }
    }
    bool isSplit = false;
    for(int i=l+1;i<r;++i){
        if(c[i]==0){
            isSplit = true;
            break;
        }
    }
    cout << (isSplit?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc256/tasks/abc256_c
// 愚直に総当たりすると O(X^9) (Xは取り得る値の範囲)
// 4箇所決まれば計算するだけなので O(X^4)
// a b AB | h0
// c d CD | h1
// AC BD E | h2
// --------
// w0 w1 w2
int h[3]; 
int w[3]; 
bool isGood(int a,int b,int c,int d){
    int AB = h[0] - (a+b);
    int CD = h[1] - (c+d);
    int AC = w[0] - (a+c);
    int BD = w[1] - (b+d);
    for(int e:{AB,CD,AC,BD}){
        if(e<=0) return false;
    }
    int Eh = h[2] - (AC+BD);
    int Ew = w[2] - (AB+CD);
    return Eh==Ew && Eh>0;
}
void solve(){ 
    CINA(h,3);
    CINA(w,3);
    int ans = 0;
    for(int a=1;a<=28;++a){
        for(int b=1;b<=28;++b){
            for(int c=1;c<=28;++c){
                for(int d=1;d<=28;++d){
                    if(isGood(a,b,c,d)){
                        ++ans;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
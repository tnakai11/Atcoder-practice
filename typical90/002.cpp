#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/typical90/tasks/typical90_b
// N の値が高々20なので
// 全列挙 O(N 2^N) でいける 
// ベクトルに結果を格納するのは重そうなので
// 再帰で解く
int N;
bool isOK(string s){
    int checker = 0;
    for(char c:s){
        if(c=='('){
            ++checker;
        }else{
            if(checker==0) return false;
            --checker;
        }
    }
    return checker==0;
}
bool mayOK(string s){
    int checker = 0;
    for(char c:s){
        if(c=='('){
            ++checker;
        }else{
            if(checker==0) return false;
            --checker;
        }
    }
    return checker>=0;
}

void func(int n, string s){
    if(n==N){
        if(isOK(s)) cout << s << '\n';
        return;
    }
    if(mayOK(s)){
        func(n+1,s+"(");
        func(n+1,s+")");
    }
}

void solve(){ 
    cin >> N;
    func(1,"(");
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
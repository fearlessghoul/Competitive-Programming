#include <bits/stdc++.h>
using namespace std;
long long compute_hash(string const &s){
    cout<<s.length()<<endl;
    const int p = 2;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s){
        hash_value = (hash_value + (c - 'a' + 1) * p_pow);
        p_pow = (p_pow * p);
    }
    return hash_value/32;
}
int main(){
    cout << compute_hash("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") << endl;
}
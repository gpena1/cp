#include <bits/stdc++.h>

std::string bin32(long x){
    std::string out;
    unsigned long y=*(unsigned long *)&x; // evil bit hack
    while(y){
        out.insert(0,std::to_string(y%2));
        y>>=1;
    }
    return out;
}
std::string bin64(long long x){
    std::string out;
    unsigned long long y=*(unsigned long long *)&x; // evil bit hack
    while(y){
        out.insert(0,std::to_string(y%2));
        y>>=1;
    }
    return out;
}
int main(){
    std::cout<<bin64(-5)<<'\n';
}

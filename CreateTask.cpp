#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> arbitstuff;
bool arbitrage(unordered_map<string,vector<pair<string,double>>>& map, string start, string end, double ratio, unordered_set<string>& visited, vector<string>& currentPath){
    if(start==end and visited.count(end) and ratio>1) {
        currentPath.push_back(start);
        arbitstuff.push_back(vector<string>(currentPath.begin(),currentPath.end()));
        return 1;
    };
    if(start==end and visited.count(end) and ratio<=1) return 0;
    visited.insert(end);
    currentPath.push_back(end);
    if(map.count(end)){
        for(const auto &k: map[end]){
            if(!visited.count(k.first) or k.first==start){
                if(arbitrage(map,start,k.first,ratio*k.second,visited,currentPath)) return 1;
            }
        }
    }
    visited.erase(end);
    currentPath.pop_back();
    return 0;
}
int main(){

    /*
     * WARNING: EXTREMELY IMPORTANT
     * THIS PROGRAM ASSUMES THAT CURRENCY EXCHANGES ARE BIDIRECTIONAL.
     * A CONNECTION FROM A TO B MEANS THAT A CAN BUY B AND VICE VERSA.
     */

//    SAMPLE INPUT 1:
//    ETH LTC 1000:6970
//    BTC ETH 32:1000
//    BTC LTC 100:22366

//    SAMPLE INPUT 2:
//    EUR USD 10000:11038
//    EUR GBP 10000:8937
//    GBP USD 10000:12376
//    EUR JPY 10000:1153520
//    EUR CHF 10000:10764
//    USD JPY 10000:1045380
//    USD CAD 10000:13373
//    AUD CAD 10000:10309
//    AUD JPY 10000:805590
//    USD AUD 7708:10000

//    SAMPLE INPUT 3:
//    USD EUR 5:1
//    EUR YEN 1:120
//    USD YEN 1:24

    cout<<"Enter the number of currencies you'll be using: ";
    int n;
    cin>>n;
    cout<<"Enter all of your currencies on a single line, space-separated:\n";
    vector<string> currencies;
    for(int i=0;i<n;++i){
        string cur;
        cin>>cur;
        currencies.push_back(cur);
    }
    cout<<"Enter the number of exchange rates are available: ";
    int exchanges;
    cin>>exchanges;
    cout<<"Enter the exchange rates, line by line, in the format 'CUR1 CUR2 X:Y', where X and Y are integers (without the single quotes):\n";
    unordered_map<string, vector<pair<string, double>>> map;
    for(int i=0;i<exchanges;++i){
        string cur1,cur2,exchange;
        cin>>cur1>>cur2>>exchange;
        if(!map.count(cur1)){
            map[cur1]=vector<pair<string,double>>();
        }
        if(!map.count(cur2)){
            map[cur2]=vector<pair<string,double>>();
        }
        auto idx=exchange.find(':');
        double rate=stod(exchange.substr(idx+1,string::npos),nullptr)/stod(exchange.substr(0,idx),nullptr);
        map[cur1].emplace_back(cur2,rate);
        map[cur2].emplace_back(cur1,1/rate);
    }
    bool arbit=0;
    unordered_set<string> visited;
    for(const auto &i:currencies){
        vector<string> path;
        arbit=arbit or arbitrage(map,i,i,1,visited,path);
//        if (arbit) break;
    }
    for(vector<string>& i: arbitstuff){
        for(const string& k:i){
            cout<<k<<' ';
        }
        cout<<'\n';
    }
    cout<<(arbit?"Arbitrage\n":"Ok\n");
    return 0;
}

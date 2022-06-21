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
     * THIS PROGRAM DOES NOT ASSUME THAT CURRENCY EXCHANGES ARE BIDIRECTIONAL.
     * I.E. IF YOU HAVE TWO CURRENCIES A AND B, AND YOU LIST THAT YOU CAN CONVERT FROM A TO B,
     * THIS PROGRAM WILL NOT LIST B AS CONNECTED TO A, BUT WILL LIST A AS CONNECTED TO B.
     */
    
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
    cout<<"Enter the exchange rates in the format 'CUR1 CUR2 X:Y', where X and Y are integers (without the single quoets):\n";
    unordered_map<string, vector<pair<string, double>>> map;
    for(int i=0;i<exchanges;++i){
        string cur1,cur2,exchange;
        cin>>cur1>>cur2>>exchange;
        if(!map.count(cur1)){
            map[cur1]=vector<pair<string,double>>();
        }
        auto idx=exchange.find(':');
        double rate=stod(exchange.substr(idx+1,string::npos),nullptr)/stod(exchange.substr(0,idx),nullptr);
        map[cur1].emplace_back(cur2,rate);
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

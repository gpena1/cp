#include <iostream>
long long sum(const long long tree[], int idx){
    long long sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(long long tree[], int n, int index, long long val){
    index++;
    while(index<=n){
        tree[index]+=val;
        index+=(index & (-index));
    }
}
long long* fenwick(long long arr[], int n){
    auto* fenwick=new long long[n+1];
    for(int i=1;i<=n;i++){
        fenwick[i]=0;
    }
    for(int i=0;i<n;i++){
        update(fenwick, n, i, arr[i]);
    }
    return fenwick;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N,Q;
    std::cin>>N>>Q;
    long long arr[N];
    for(int i=0;i<N;i++){
        arr[i]=0;
    }
    long long* fentree=fenwick(arr, N);
    for(int i=0;i<Q;i++){
        char type;
        std::cin>>type;
        if(type=='+'){
            int idx;
            long long val;
            std::cin>>idx>>val;
            update(fentree, N, idx, val);
        }else if(type=='?'){
            int idx;
            std::cin>>idx;
            if (idx==0) std::cout<<0<<'\n';
            else {
                long ans=sum(fentree, idx);
                std::cout<<ans<<'\n';
            }
        }
    }
    return 0;
}

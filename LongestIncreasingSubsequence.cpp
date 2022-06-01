#include <bits/stdc++.h>
using namespace std;

struct Node{
	int32_t v;
	uint32_t i;
};

bool operator<(const Node& left, const Node& right){
	return left.v<right.v;
}
// This is more or less the same algorithm
// used in https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// The primary difference is that this uses an unordered_map to keep track of each node's predecessor
// One minor difference to note is that in geeksforgeeks' algorithm, they use only the elements in the original array,
// while this algorithm employs the use of the elements' indices in addition to their actual values.

// Time complexity: O(N log N)
// Space complexity: O(N) (ordered set and unordered map)
int main() {
	unordered_map<uint32_t, uint32_t> parent;
	set<Node> s;
	vector<int32_t> a{10,9,2,5,3,7,101,18};

	for(uint32_t i=0;i<a.size();++i){
		Node n={a[i],i};
		auto it=s.insert(n).first;
		++it;
		if(it!=s.end()){
			s.erase(it);
		}
		it=s.find(n);
		--it;
		parent[i]=it->i;
	}
	for(auto it=parent.begin();it!=parent.end();++it){
		printf("%d -> %d\n",it->first,it->second);
	}
	uint32_t i=s.rbegin()->i;
	uint32_t n=s.size();
	vector<int32_t> lis;
	while(n--){
		lis.push_back(a[i]);
		i=parent[i];
	}
	// std::reverse is an in-place algorithm (has O(1) space complexity)
	reverse(lis.begin(),lis.end());
	for(const int32_t& i: lis){
		cout<<i<<' ';
	}
	cout<<'\n';
}

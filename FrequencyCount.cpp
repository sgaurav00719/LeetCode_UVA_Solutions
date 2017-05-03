#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;


/*
 * Sort elements by frequency, print the elements of an array in the
 * decreasing frequency if 2 numbers have same frequency
 * then print the one which is smallest.
 * */

vector<pair<int,int>> freqCount1(vector<int>& nums){

	struct CompareNums
	{
	public:
		//Keep min number at top if frequencies are same
		bool operator()(pair<int,int> n1,pair<int,int> n2) {
			if (n1.first == n2.first){
				return (n1.second > n2.second);
			}
			return (n1.first < n2.first);
		}
	};

	unordered_map<int,int> map;
	for(int num : nums){
		map[num]++;
	}
	vector<pair<int,int>> res;
	// pair<first, second>: first is frequency,  second is number
	priority_queue<pair<int,int>,vector<pair<int,int>>,CompareNums> pq;
	for(auto it = map.begin(); it != map.end(); it++){
		pq.push(make_pair(it->second, it->first));
	}
	res.push_back(make_pair(pq.top().second,pq.top().first));
	return res;
}

/*
 * Sort elements by frequency, print the elements of an array in the
 * decreasing frequency if 2 numbers have same frequency
 * then print the one which came first.
 * */

vector<pair<int,int>> freqCount2(vector<int>& nums){

	struct Node {
		int n;
		int firstSeenIndex;
		int frequency;
	};

	struct CompareNums
	{
	public:
		bool operator()(Node n1,Node n2) {
			//Keep number at top if seen first
			if (n1.frequency == n2.frequency){
				return (n1.firstSeenIndex > n2.firstSeenIndex);
			}
			return (n1.frequency < n2.frequency);
		}
	};

	unordered_map<int,Node> map;
	for(size_t i = 0; i < nums.size();i++){
		if(map.find(nums[i]) == map.end()){
			map[nums[i]].n = nums[i];
			map[nums[i]].frequency++;
			map[nums[i]].firstSeenIndex = i;
		}
		else{
			map[nums[i]].frequency++;
		}
	}
	vector<pair<int,int>> res;
		// pair<first, second>: first is frequency,  second is number
		priority_queue<Node,vector<Node>,CompareNums> pq;
		for(auto it = map.begin(); it != map.end(); it++){
			pq.push(it->second);
		}
		res.push_back(make_pair(pq.top().n,pq.top().frequency));
		return res;
}

int main(){
	vector<int> v = {3,3,4,4,8,8,1,1,-1,-1};
	cout<< "Top frequent element which is minimum among the elements with same frequency: " << " ";
	vector<pair<int,int>> res1 = freqCount1(v);
	for(auto i : res1)
	cout << i.first << ',' << i.second<<endl;
	cout<< "Top frequent element which was seen first: " <<" ";
	vector<pair<int,int>> res2 = freqCount2(v);
		for(auto i : res2)
		cout << i.first << ',' << i.second;
	return 0;
}

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
	int _capacity;
	//List of keys, 1st = MRU, last = LRU
	list<int> _lru;
	//<key, <value, key iterator>>
	unordered_map<int, pair<int,list<int>::iterator>> _cache;

public:
	LRUCache(int capacity) : _capacity(capacity){

	}

	int get(int key) {
		auto item = _cache.find(key);
		//If item does not exist
		if(item == _cache.end())
			return -1;
		use(item);
		//If item exists, we return the value, update the LRU
		return item->second.first;
	}

	void put(int key, int value) {
		auto item = _cache.find(key);
		//If key exists, just set the value and update
		if (item != _cache.end()){
			use(item);
		}
		else{
			//If the key doesn't exist, check the capacity
			if(_cache.size() == (size_t)_capacity){
				//Kick out the LRU item
				_cache.erase(_lru.back());
				_lru.pop_back();
			}
			_lru.push_front(key);
		}
		//Insert new key value pair
		_cache[key]= make_pair(value,_lru.begin());
	}

	void use(unordered_map<int, pair<int,list<int>::iterator>>::iterator& it){
		_lru.splice(_lru.begin(),_lru,it->second.second);
		//splice function is similar to the following operations
		//_lru.erase(it->second.second);
		//_lru.push_front(it->first);
		it->second.second = _lru.begin();
	}

	//Helper function to check the state of the list
	void printList(){
		for(auto i : _lru)
			cout << i << " ";
		cout << endl;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(){
	LRUCache *cache = new LRUCache(2);
	cache->put(1,1);
	cache->put(2,2);
	cache->printList();
	cout << cache->get(1) << endl;
	cache->printList();
	cache->put(3,3);
	cout << cache->get(2) << endl;
	cache->printList();
	return 0;
}

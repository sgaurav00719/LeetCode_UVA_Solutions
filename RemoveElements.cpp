#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (size_t j = 0; j < nums.size(); j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main(){
	vector<int> v = {2,2,3,1};
	int res = removeElement(v,3);
	cout << res <<  endl;
	for(int i = 0; i < res; i++)
		cout << v[i] << " ";
}

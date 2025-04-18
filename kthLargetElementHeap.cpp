// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

//Priority Queue
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i=0; i<nums.size(); i++) {
//             pq.push(nums[i]);
//             if(pq.size() > k)
//                 pq.pop();
//         }
//         return pq.top();
//     }
// };


//QUICK SORT
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        shuffleFunc(nums);

        int n = nums.size(), low = 0, high = n - 1;
        k = n - k;

        while(low < high) {
            int j = partition(nums, low, high);

            if( j < k ) 
                low = j + 1;
            else if( j > k )
                high = j - 1;
            else
                break;
        }
        
        return nums[k];
    }

    void shuffleFunc(vector<int>& nums) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(nums.begin(), nums.end(), default_random_engine(seed));
    }

    int partition(vector<int>& nums, int low, int high) {
        int i = low, j = high + 1, pivot = nums[low];

        while(i < j) {
            while(++i < high && nums[i] <= pivot);
            while(--j >= low && nums[j] > pivot);
            if( i < j )
                swap(nums[i], nums[j]);
        }

        swap(nums[low], nums[j]);
        return j;
    }
};

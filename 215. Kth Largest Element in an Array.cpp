// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    
    // ммм, щас буду решать через кучи
    
    void siftDown(vector<int>& heap, int i) {
        while (2 * i + 1 < heap.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if (right < heap.size() && heap[right] > heap[j]) {
                j = right;
            }
            if (heap[i] >= heap[j]) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    } 
    
    int extractMax(vector<int>& heap) {
        int max = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(heap.begin() + heap.size() - 1);
        siftDown(heap, 0);
        return max;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = nums.size() / 2 + 1; i > 0; i--) {
            siftDown(nums, i - 1);
        }
        int res = 0;
        for (int i = 0; i < k; i++) {
            res = extractMax(nums);
        }
        return res;
    }
};

// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    
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
    
    void siftUp(vector<int>& heap, int i) {
        int par = (i -1) / 2;
        while (i > 0 && heap[i] > heap[par]) {
            swap(heap[i], heap[par]);
            i = par;
            par = (i - 1) / 2;
        }
    }
    
    int extractMax(vector<int>& heap) {
        int max = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(heap.begin() + heap.size() - 1);
        siftDown(heap, 0);
        return max;
    }
    
    void insert(vector<int>& heap, int x) {
        heap.push_back(x);
        siftUp(heap, heap.size() - 1);
    }
    
    int lastStoneWeight(vector<int>& stones) {
        for (int i = stones.size() / 2 + 1; i > 0; i--) {
            siftDown(stones, i - 1);
        }
        while (stones.size() >= 2) {
            int y = extractMax(stones);
            int x = extractMax(stones);
            if (y != x) {
                insert(stones, y - x);
            }
        }
        return (stones.empty() ? 0 : stones[0]);
    }
    
};

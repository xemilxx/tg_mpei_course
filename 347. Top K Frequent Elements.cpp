// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    
    struct Node {
        int val;
        int freq;
        Node(int v, int f) : val(v), freq(f) {}
    };
    
    void siftDown(vector<Node>& heap, int i) {
        while (2 * i + 1 < heap.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if (right < heap.size() && heap[right].freq > heap[j].freq) {
                j = right;
            }
            if (heap[i].freq >= heap[j].freq) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    } 
    
    void siftUp(vector<Node>& heap, int i) {
        int par = (i -1) / 2;
        while (i > 0 && heap[i].freq > heap[par].freq) {
            swap(heap[i], heap[par]);
            i = par;
            par = (i - 1) / 2;
        }
    }
    
    void insert(vector<Node>& heap, Node x) {
        heap.push_back(x);
        siftUp(heap, heap.size() - 1);
    }
    
    
    Node extractMax(vector<Node>& heap) {
        Node max = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(heap.begin() + heap.size() - 1);
        siftDown(heap, 0);
        return max;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // частота элементов
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n] += 1;
        }
        
        vector<Node> heap;
        for (auto it = m.begin(); it != m.end(); it++) {
            insert(heap, Node(it->first, it->second));
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(extractMax(heap).val);
        }
        
        return res;
        
    }
};

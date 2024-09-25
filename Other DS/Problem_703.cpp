/*  Day 47: Problem 703 - Kth Largest Element in a Stream
    Implement the KthLargest class:
    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
    int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
*/

class KthLargest {
public:
    // Set k
    int kL;
    priority_queue<int, vector<int>, greater<int>> pq;

    // K-th problems use priority queue - min heap
    KthLargest(int k, vector<int>& nums) {
        // Store k
        kL = k;

        // Add each num into heap
        for(int n : nums) {
            pq.push(n);
            // check if we have k elements
            if(pq.size() > kL) pq.pop();
        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > kL) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 
    Time Complexity: O(N) since all N numbers will need to be considered and compared.      Space Complexity: O(k) since it only needs to store
    the k largest numbers in the priority queue.
    Explanation: I declared the priority queue to display the smaller number at the top due to the greater<int>. I go through nums and add each num
    to the queue. If it the size of the queue exceeds k then I remove the top element (smallest number). For add(), I push the val to the queue,
    check the size of the queue and remove the smallest num, if size is too big. Then I return the smallest element to be a part of the list with 
    kth largest elements so far. 
*/
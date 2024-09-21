/*  Day 43: Problem 232 - Implement Queue using Stacks
 *
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.size() == 0) {
            s1.push(x);
            return;
        }
        else {
            // put all numbers in s1 to s2
            while(s1.size() > 0) {
                s2.push(s1.top());
                s1.pop();
            }
            // add x to s1 to top
            s1.push(x);
            // re-add rest of numbers so x is last
            while(s2.size() > 0) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        // return first element and remove from stack
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        // return whether size is equal to 0 or not
        return (s1.size() == 0);
    }
};

/*  Time Complexity: O(N) since we need to traverse all N numbers of the stack to transfer it.
    Space Complexity: O(N) since we need to store all N numbers in the stack. 
    Explanation: We are mimicing a queue using stacks, so peek() can use the top() function of
    stack to return first element. pop() has the same idea but we also remove the first element
    with pop() function of stack. To push a element to the stack, we need to place the current values
    temporarily in another stack. We then add the new element, and stack all former numbers back into
    the O.G. stack. This will result in the stack containing the most recent element at the bottom of 
    the stack
*/

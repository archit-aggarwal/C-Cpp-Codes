// Elements are 0-indexed. 
//     -> For a parent at index i, its child are at index 2*i + 1, and 2*i + 2. 
//     -> For a child at index j, it's parent is at index (j-1)/2.

class PriorityQueue
{
    public:
    vector<int> data;
    
    int size()
    { return data.size(); }
    
    int top()
    {
        if(data.size() == 0) return -1;
        return data.front();
    }
    
    void push(int val)
    {
        data.push_back(val);
        upheapify(data.size() - 1);  
        
        // Upheapify is O(log N) operation where N is number of elements in heap.
        // Hence Inserting N elements in heap will take O(N logN) time.
    }
    
    void upheapify(int i)
    {
        if(i == 0) return;
        
        int par = (i-1)/2;
        if(data[par] > data[i])
        {
            swap(data[par], data[i]);
            upheapify(par);
        }
    }
     
    void create(vector<int> &elements)
    {
        for(auto &e: elements)
            data.push_back(e);
        
        for(int i = data.size()/2 - 1; i >= 0; i--)
            downheapify(i, data.size());
        
        // If we are given all elements to be pushed into stack, we call start building heap from bottom
        // by using downheapify. It will take O(N - logN) = O(N) time for inserting N elements.
        // Note: All elements to be inserted should be known before to build heap using downheapify in O(N)
    }
    
    int pop()
    {
        if(data.size() == 0) return -1;
        
        int top = data.front();
        swap(data[0], data[data.size()-1]);
        data.pop_back();
             
        downheapify(0, data.size()); 
        // Downheapify at 0th index is O(log N) operation where N is number of elements in heap.
        return top;
    }
             
    void downheapify(int i, int n)
    {
        int Min = i;
        
        int left = 2*i + 1;
        if(left < n && data[left] < data[Min])
            Min = left;
        
        int right = 2*i + 2;
        if(right < n && data[right] < data[Min])
            Min = right;
        
        if(Min != i)
        {
            swap(data[i], data[Min]);
            downheapify(Min, n);
        }
    }
             
    void heapsort()
    {
        for(int i = 0; i < data.size(); i++)
        {
            swap(data[0], data[data.size() -1 -i]);
            downheapify(0, data.size()-i-1);
        }
        
        // Note: Before Calling Heapsort, heap should be heapified already(either using create or push for n elements) should have been called.
        // We cannot call heapsort directly, as otherwise, top element will not be highest priority element.
        
        // All elements which will be popped (highest priority) will keep on adding on last of array.
        // Finally, data array will be sorted in reverse order of priority.
        // Heap Sort: 
        //  -> Time Complexity: O(NlogN) in best, average & worst case.
        //  -> Space Complexity: Inplace - O(1) Extra Space.
        //  -> It is Not Stable by default. (Equal keys can be popped out in any order). 
        //     However, we can modify it to make it stable, by storing the index while element was inserted for all elements, and compare this index for equal elements.
        //     This will take O(N) extra space as we will have to store (insertion order) index of all elements along with their value.
    }
};

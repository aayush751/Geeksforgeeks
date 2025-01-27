//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
    
    int capacity;
    std::list<std::pair<int, int>> cacheList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) : capacity(cap) {}
        // code here


    
    int get(int key) 
    {
        // your code here
        auto it = cacheMap.find( key );
        if ( it == cacheMap.end() )
        {
            return -1;
        }
        
        cacheList.splice( cacheList.begin(), cacheList, it->second );
        return it -> second -> second;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        auto it = cacheMap.find( key );
        if (it != cacheMap.end()) 
        {
            cacheList.splice( cacheList.begin(), cacheList, it -> second );
            it -> second -> second = value;
            return;
        }
      
        if ( cacheMap.size() == capacity )
        {
            int lruKey = cacheList.back().first;
            cacheMap.erase( lruKey );
            cacheList.pop_back();
        }
        
        cacheList.emplace_front( key, value );
        cacheMap[key] = cacheList.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
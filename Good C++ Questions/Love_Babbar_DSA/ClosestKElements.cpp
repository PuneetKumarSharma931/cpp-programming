
#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

class compare {
    
    public:
    
    bool operator() (pair<int,int>& p1, pair<int,int>& p2) {
        
        return (p1.second == p2.second?(p1.first > p2.first):(p1.second > p2.second));
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>, vector<pair<int,int> >, compare> pq;
        vector<int> ans;
        
        for(int i=0; i<arr.size(); i++) {
            
            pq.push(make_pair(arr[i], abs(arr[i] - x)));
        }
        
        
        while(k!=0) {
            
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};

int main() {
    
    system("clear");

    
    vector<int> arr;
    int k = 2;
    int x = -1;

    for(int i=1; i<=5; i++)
        arr.push_back(i);
    
    Solution s;
    
    vector<int> ans = s.findClosestElements(arr, k, x);
    
    for(int i=0; i<ans.size(); i++) {
        
        cout<<ans[i]<<" ";
        
    }
    
    return 0;
}
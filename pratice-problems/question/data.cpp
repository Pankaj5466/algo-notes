#define MAX_IDX 100005
int mem[MAX_IDX];

#define INF INT_MIN/2
class Solution {
    
    int findAns(int idx,bool taken,vector<int>&arr)
    {
        if(idx>=arr.size()) return INF;
        
        int inc=0; //take arr[idx] (if constrain allow)
        int exc=0; //do not take arr[idx]
        
        if(taken)
        {
            inc = arr[idx] + findAns(idx+1,1,arr);
        }
        
        exc = findAns(idx+1,0,arr);
        
        printf("[%d]:(%d,%d)\n",idx,inc,exc);
        
        return max({inc,exc,arr[idx]});
    }
   
    /*
    int findAns(int idx,vector<int>& arr)
    {
        if(idx >= arr.size()) return 0;
        
        if(mem[idx] != -1) return mem[idx];
        
        //maximum sum for range[idx,_] 
        //i.e idx must be included
        
        int t = findAns(idx+1,arr);
        if(t>0)
            return mem[idx] = arr[idx] +t;
        else
            return mem[idx] = arr[idx] + 0;       
        
    }*/
    
public:
    int maxSubArray(vector<int>& arr) 
    {
        
        int size = arr.size();
        vector<int> dp(arr);
        
        for(int idx=1;idx<size;idx++)
        {
            dp[idx] = max(arr[idx]+dp[idx-1], arr[idx]);
        }
        
        cout<<"DP array is\n";
        for(auto k:dp)
            cout<<k<<" ";
        cout<<endl;
        
        return *max_element(dp.begin(),dp.end());

    }
};
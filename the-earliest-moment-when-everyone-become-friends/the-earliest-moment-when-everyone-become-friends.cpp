class Solution {
public:
    vector<int> parent;
    
    int find(int j){
        // if(parent[j] != j){
        //     parent[j] = find(parent[j]);
        // }
        return parent[j];
    }
    
    bool union_p(int i, int j){
        int x = find(i);
        int y = find(j);
        
        std::set<int> pp;
        
        if(x!= y){
            for(int p=0; p<parent.size(); p++){
                if (parent[p] ==y) parent[p] = x;
                pp.insert(parent[p]);
            }
        }
        
        if(pp.size() == 1){
            return false;
        }
        return true;
        
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        if(logs.size() == 0) return -1;
        
        std::sort( logs.begin(), logs.end(), [](vector<int>& a, vector<int>&b){
           return a[0] < b[0];
       } ) ;
        
        parent.clear();
        for(int i=0; i<n; i++){
            parent.push_back(i);
        }
        
        for(auto& log : logs){
            if(union_p(log[1], log[2]) == false){
                return log[0];
            }
            
        }
        
        return -1;
    }
};
class Solution {
public:
    
    vector<int> parent;
    
    int find(int i){
        if(parent[i] != i){
            return find(parent[i]);
        }
        return parent[i];
    }
    
    void union_p(int i, int j){
        int x = find(i);
        int y = find(j);
        
        if(x != y ){
            parent[y] = x;    
        }        
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.clear();
        
        if(edges.size() != n-1) return false;
        
        for(int i =0; i< n; i++){
            parent.push_back(i);
        }
        
        for(auto& itr : edges){
            union_p(itr[0],itr[1]);
        }
        
        std::set<int> set_p;
        
        for(int i= 0; i<n ; i++){
            set_p.insert(find(parent[i]));
        }
        
        return set_p.size() == 1 && edges.size() == n-1;
        
    }
};
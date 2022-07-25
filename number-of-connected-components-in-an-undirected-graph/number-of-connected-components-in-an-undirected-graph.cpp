class Solution {
public:
    std::vector<int> parent;
    
    int find(int i){
        if(parent[i] != i){
            parent[i] = find(parent[i]);
        }    
        return parent[i];
    }
    
    void union_p(int i, int j){
        int x = find(i);
        int y = find(j);
        
        if(x!=y){
            parent[y]=x;
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.clear();
        
        if(edges.size() == 0) return n;
        
        for(int i =0; i<n; i++){
            parent.push_back(i);
        }
        
        for(auto& edge : edges){
            union_p(edge[0], edge[1]);
        }
        
        std::set<int> set_p;
        
        for(int j =0; j<n; j++){
            set_p.insert( find(parent[j]) );
        }
        
        return set_p.size();
        
        
    }
};
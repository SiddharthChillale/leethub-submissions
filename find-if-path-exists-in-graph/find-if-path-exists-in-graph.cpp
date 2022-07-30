class Solution {
public:
    vector<int> parent;
    
    int find(int i){
        if(i != parent[i]){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void union_p(int i, int j){
        int x = find(i);
        int y = find(j);
        if(x!=y){
           parent[x] = y;
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.clear();
        for(int i =0; i<n; i++){
            parent.push_back(i);
        }
        
        for(auto& edge : edges){
            union_p(edge[0], edge[1]);
        }
        
        return (find(source) == find(destination)) ;
        
    }
};
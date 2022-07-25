class Solution {
public:
    vector<int> parent;
    
    int find(int i){
        return parent[i];
    }
    
    void punion(int i, int j){
        int x = find(i);
        int y = find(j);
        
        if(x!= y){
            for(int p=0; p< parent.size(); p++){
                if(parent[p] == y) parent[p] = x;
            }    
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent.clear();
        int size = isConnected.size();
        for(int i =0; i<size; i++){
            parent.push_back(i);
        }
        
        for(int i =0; i<size; i++){
            for(int j =i+1; j<size; j++){
                if(isConnected[i][j]){
                    punion(i, j);
                }
            }
        }
        
        //for(auto x : parent) std::cout << x <<" ";
        
        std::set<int> suni(parent.begin(), parent.end());
        
        return suni.size();
        
    }
};
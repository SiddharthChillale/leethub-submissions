class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
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
            if(rank[x] >= rank[y]){
                parent[y] = x;
                rank[x] += rank[y];
            }
            else{
                parent[x] = y;
                rank[y] += rank[x];
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // construct a graph with (con)nected-(com)ponents. 
        // do following for every con-comp
        // items in each con-comp can be sorted lexically and inserted at the positions of items in that same con-comp
        vector<int> seen(s.size(), 0);    
        parent.clear();
        for(int p=0; p<s.size() ; p++){
            parent.push_back(p);
            rank.push_back(1);
        }
        
        for(auto& pair : pairs){
            union_p(pair[0], pair[1]);
        }
        
        // for(auto x : parent) std::cout << x << " | " ;
        
        std::unordered_map<int, vector<int>> parentToComponent;
        for(int j =0; j<parent.size(); j++){
            int root = find(parent[j]) ;
            parentToComponent[root].push_back(j);
        }
        
        string result(s.size(), '_');

        for(auto comp : parentToComponent){
            vector<int> indices = comp.second;
            
            vector<char> characters;
            for(int idx : indices){
                characters.push_back(s[idx]);
            }
            sort(characters.begin(), characters.end());
            
            for(int i =0; i<indices.size(); i++){
                result[indices[i]] = characters[i];
            }
        }
        
        return result;
        
//         for(auto con : set_p){
//             for(int p =0; p<s.size(); p++){
//                 if(parent[p] == con){
//                     same_con_idx.push_back( p );
//                 }
//             }
            
//             for(auto p_idx : same_con_idx){
//                 intr_str.push_back( s[p_idx] );
//             }
//             std::sort(intr_str.begin(), intr_str.end());
//             //std::sort(same_con_idx.begin(), same_con_idx.end());
//             while( !intr_str.empty() ){
//                 auto s_idx = same_con_idx.back();
//                 same_con_idx.pop_back();
                
//                 auto ch = intr_str.back();
//                 intr_str.pop_back();
                
//                 s[s_idx] = ch;
//             }
            
            
            
//         }
        
//        return s;
        
    }
};
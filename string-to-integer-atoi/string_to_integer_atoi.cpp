class Solution {
public:
    int myAtoi(string s) {
    
        int sign = 1;
        int value = 0;
        
        int itr = 0; 
        while(s[itr] == ' ' && itr < s.size()){
            itr ++;
        }
        if(s[itr] == '-') {
            sign = -1;
            itr++;
        }
        else if(s[itr] == '+'){
            itr++;
        }
        while(itr < s.size() && s[itr] == '0' ){
            itr++;
        }
        
        if(itr == s.size() ) return value;     
        
        // INT_MAX = 2^31-1
        // INT_MIN = 2^31
        
        int ceil  = abs(INT_MAX)/10;
        std::cout << itr << std::endl;
        std::cout << "INT_MAX: "<< INT_MAX << std::endl;
        std::cout << "INT_MIN: "<< INT_MIN << std::endl;
        
        for(itr; itr<s.size(); itr++){
            if(s[itr] < '0' || s[itr] > '9') {
                return sign == -1 ? -1*value: value;
            }
            int num = s[itr] - '0';
            
            
            if(sign == 1){
                // positive number
                std::cout << "value: " <<value<< " num: " << num << std::endl;
                if ( value > ceil){
                    return INT_MAX;
                }
                else if (value == ceil){
                    std::cout << "==value: " <<value<< " num: " << num << std::endl;
                    if(num < 7){
                        value = value * 10 + num;
                    std::cout << "<7 value: " <<value<< " num: " << num << std::endl;
                        
                    }
                    else{
                        return INT_MAX;
                    }
                }
                else{
                    // value < ceil
                    value = value * 10 + num;
                }
            }
            else{
                // negative number
                if ( value > ceil){
                    return INT_MIN;
                }
                else if (value == ceil){
                    if(num < 8){
                        value = value * 10 + num;
                    }
                    else{
                        return INT_MIN;
                    }
                }
                else{
                    // value < ceil
                    value = value * 10 + num;
                }
            }
            
            
        }
        std::cout << "{function exit} value: " <<value << std::endl;
        
        return sign == -1 ? -1*value: value;
        
    }
};

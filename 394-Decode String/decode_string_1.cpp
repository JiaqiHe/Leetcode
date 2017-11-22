class Solution {
public:
    bool isDigit(char a){
        return a >= '0' && a <= '9';
    }
    bool isCharacter(char a){
        return a >= 'a' && a <= 'z';
    }
    int getNumber(string s, int &ptr){
        int res = 0;
        while(ptr < s.length() && isDigit(s[ptr])) res = res*10+s[ptr++]-'0';
        return res;
    }
    string getSubstring(string s, int &ptr){
        string res = "";
        while(ptr < s.length() && isCharacter(s[ptr])) res += s[ptr++];
        return res;
    }
    
    string decode(string s, int &ptr){
        if(ptr > s.length()) return "";
        string res = "";
        if(isDigit(s[ptr])){
            int times = getNumber(s, ptr);
            ptr++;
            string cur = decode(s, ptr);
            for(int i = 0; i < times; i ++){
                res += cur;
            }
            if(ptr >= s.length() || s[ptr] == ']'){
                ptr++;
                return res;
            }
            else{
                return res + decode(s, ptr);
            }
            
        }
        else if(isCharacter(s[ptr])){
            string cur = getSubstring(s, ptr);
            if(ptr >= s.length() || s[ptr] == ']'){
                ptr++;
                return cur;
            } 
            else{
                //is a number
                res = cur + decode(s, ptr);
                return res;
            }
        }
        // else {
        //     ptr++;
        //     return decode(s, ptr);
        // }
    }
    string decodeString(string s) {
        int ptr = 0;
        string res = "";
        while(ptr < s.length()){
            res += decode(s, ptr);
        }
        return res;
    }
};

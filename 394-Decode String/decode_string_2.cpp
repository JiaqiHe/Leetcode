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
        string res = "";
        
        while(ptr < s.length() && s[ptr] != ']'){ //adding s[ptr] != ']' is awesome, this guarantees that every time we meet ], we return immediately
            if(!isDigit(s[ptr])){
                res += s[ptr++];
            }
            else{
                int times = getNumber(s, ptr);
                ptr++;//skip "["
                string cur = decode(s, ptr);
                ptr++;//skip "]"
                while(times > 0){
                    res += cur;
                    times--;
                }  
            }
        }
        return res;
    }
    string decodeString(string s) {
        int ptr = 0;
        return decode(s, ptr);
    }
};

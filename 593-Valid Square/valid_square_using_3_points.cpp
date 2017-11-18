#include <iostream>
#include <math>
#include <unordered_map> 

using namespace std;

namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first)*31 + int_hasher(v.second);
    }
};
}

int sqDis(pair<int, int> a, pair<int, int> b){
    return pow(a.first-b.first, 2)+pow(a.second-b.second, 2);
}

bool isIsoscelesRight(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c){
    unordered_map<int, int> sqEdges;
    int max = 0;
    int flag = 0;
    if(sqDis(a,b) > max){
        max = sqDis(a,b);
        flag = 1;
    }
    if(sqDis(a,c) > max){
        max = sqDis(a,b);
        flag = 2;
    }
    if(sqDis(b,c) > max){
        max = sqDis(a,b);
        flag = 3;
    }
    sqEdges[sqDis(a,b)]++;
    sqEdges[sqDis(a,c)]++;
    sqEdges[sqDis(b,c)]++;
    if(sqEdges.size() != 2) return false;
    else {
        unordered_set<int> val;
        for(auto elem : sqEdges){
            val.insert(elem.first * elem.second);
        }
        if(val.size() == 1){
            pair<int, int> temp;
            if(flag == 2){
                temp = b;
                b = c;
                c = temp;  
            } else if(flag == 3){
                temp = a;
                a = c;
                c = temp;
            }
            return true;
        } 
        else return false;
    }
}
int main() {
    vector<pair<int, int>> points;
    int number = 7;
    points.push_back(make_pair(0,0));
    points.push_back(make_pair(2,0));
    points.push_back(make_pair(1,-1));
    points.push_back(make_pair(1,1));
    points.push_back(make_pair(0,2));
    points.push_back(make_pair(2,2));
    points.push_back(make_pair(3,1));
    unordered_set<pair<int, int>> dict(points.begin(), points.end());
    int count = 0;
    for(int i = 0; i < number; i ++){
        for(int j = i+1; j < number; j ++){
            for(int k = j+1; k < number; k ++){
                pair<int, int> a = points[i];
                pair<int, int> b = points[j];
                pair<int, int> c = points[k];
                if(isIsoscelesRight(a, b, c)){
                    pair<int, int> d = make_pair(a.first+b.first-c.first, a.second+b.second-c.second);
                    if(dict.find(d) != dict.end()){
                        count++;
                    //     cout<<"["<<a.first<<", "<<a.second<<"]"<<"; ";
                    // cout<<"["<<b.first<<", "<<b.second<<"]"<<"; ";
                    // cout<<"["<<c.first<<", "<<c.second<<"]"<<"; ";
                    // cout<<"expected: ["<<a.first+b.first-c.first<<", "<<a.second+b.second-c.second<<"]"<<endl;
                    } 
                    
                }
            }
        }
    }
    cout<<"There are "<<count/4<<" squares."<<endl;
    return 0;
}

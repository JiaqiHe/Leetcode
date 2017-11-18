#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first)*31 + int_hasher(v.second);
    }
};
}


void print(pair<float, float> a){
    cout<<"["<<a.first<<","<<a.second<<"]; ";
    return;
}

void findPairs(pair<int, int> a, pair<int, int> b){
    print(a);
    print(b);
    cout<<endl;
    cout<<"expected another two points: "<<endl;
    print(make_pair(a.first+a.second-b.second, a.second+b.first-a.first));
    print(make_pair(b.first+a.second-b.second, b.second+b.first-a.first));
    cout<<endl;
    print(make_pair(a.first-a.second+b.second, a.second-b.first+a.first));
    print(make_pair(b.first-a.second+b.second, b.second-b.first+a.first));
    cout<<endl;
    print(make_pair((float)(a.first+b.first-a.second+b.second)/2.0, (float)(a.second+b.second-b.first+a.first)/2.0));
    print(make_pair((float)(a.first+b.first+a.second-b.second)/2.0, (float)(a.second+b.second+b.first-a.first)/2.0));
    cout<<endl;
    cout<<"---------------------------"<<endl;
}

void find_(pair<int, int> a, pair<int, int> b, unordered_set<pair<int, int>> dict, int &count){
    pair<int, int> c, d;
    c = make_pair(a.first+a.second-b.second, a.second+b.first-a.first);
    d = make_pair(b.first+a.second-b.second, b.second+b.first-a.first);
    if(dict.find(c)!= dict.end() && dict.find(d) != dict.end()){
        count++;
        // print(a);print(b);print(c);print(d);cout<<endl;
    }
    c = make_pair(a.first-a.second+b.second, a.second-b.first+a.first);
    d = make_pair(b.first-a.second+b.second, b.second-b.first+a.first);
    if(dict.find(c)!= dict.end() && dict.find(d) != dict.end()){
        count++;
        // print(a);print(b);print(c);print(d);cout<<endl;
    }
    c = make_pair((float)(a.first+b.first-a.second+b.second)/2.0, (float)(a.second+b.second-b.first+a.first)/2.0);
    d = make_pair((float)(a.first+b.first+a.second-b.second)/2.0, (float)(a.second+b.second+b.first-a.first)/2.0);
    if(dict.find(c)!= dict.end() && dict.find(d) != dict.end()){
        count++;
        // print(a);print(b);print(c); print(d);cout<<endl;
    }
    return;
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
            find_(points[i], points[j], dict, count);
        }
    }
    cout<<"There are "<<count/6<<" squares."<<endl;
    return 0;
}

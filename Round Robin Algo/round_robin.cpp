#include <iostream>
void RoundRobin(vector<pair<int, int>> tasks, int unit_time) {
    // tasks: (arrive time, process time)
    queue<pair<int, int>> q; // (index, remaining time)
    int cur_time = tasks[0].first;
    q.push(make_pair(0, tasks[0].second));
    int index = 1;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        cur_time += min(unit_time, p.second);
        // cout<<"time "<<cur_time<<" processed task "<<p.first<<" for "<<min(unit_time, p.second)<<" time"<<endl;
        while(index < tasks.size() && tasks[index].first < cur_time) {
            q.push(make_pair(index, tasks[index].second));
            index++;
        }
        if(p.second > unit_time) {
            // we cannot finish processing this task
            q.push(make_pair(p.first, p.second - unit_time));
        }
    }
}
int main() {
    vector<pair<int, int>> tasks = {{0,250},{50,170},{130,75},{190,100},{210,130},{350,50}};
    RoundRobin(tasks, 100);
}

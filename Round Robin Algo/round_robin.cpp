#include <iostream>
void RoundRobin(vector<pair<int, int>> tasks, int unit_time) {
    // tasks: (arrive time, process time)
    queue<pair<int, int>> q; // (index, remaining time)
    int cur_time = 0;
    int index = 0;
    while(!q.empty() || index < tasks.size()) {
        if(!q.empty()) {
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
        } else {
            // q is empty and yet we haven't done all tasks
            cur_time = tasks[index].first;
            q.push(make_pair(index, tasks[index].second));
            index++;
        }
    }
}
int main() {
    vector<pair<int, int>> tasks = {{0,250},{50,170},{130,75},{190,100},{210,130},{350,50},{800, 20}, {900,100}};
    RoundRobin(tasks, 100);
}

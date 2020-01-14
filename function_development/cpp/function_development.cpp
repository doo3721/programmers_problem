#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> que;
    int day, dist;
    
    // 프로세스를 완료하는데 걸리는 시간을 que에 저장
    for(int i=0; i < progresses.size(); i++) {
        int sum = progresses[i];
        int count = 0;
        
        while(sum < 100) {
            sum += speeds[i];
            count++;
        }
        
        que.push_back(count);
    }
    
    // 문제의 기능 배포 계산
    while(!que.empty()) {
        day = que.front();
        que.erase(que.begin());
        dist = 1;
        
        while(!que.empty() && day >= que.front()) {
            que.erase(que.begin());
            dist++;
        }
        
        answer.push_back(dist);
    }
    
    return answer;
}

int main(void) {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    for(auto result: solution(progresses, speeds)) {
        cout << result << " ";
    }
    cout << endl;

    vector<int>().swap(progresses);
    vector<int>().swap(speeds);

    return 0;
}
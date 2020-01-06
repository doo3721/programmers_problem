/*
 * 출처: Curookie
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int needHot;
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    
    while(pq.top() <  K) {
        if(pq.size()==1) return answer = -1;
        needHot = pq.top(); pq.pop();
        pq.push(needHot+pq.top()*2);    // 결과값은 반드시 top으로 오지 않는다
        pq.pop();                       // 2번째로 안 매운맛에 해당
        answer++;
    }
    
    return answer;
}

int main() {

    int array[6] = {1, 2, 3, 9, 10, 12};
    int k = 7;

    vector<int> scoville;

    for(int num: array) scoville.push_back(num);
    cout << solution(scoville, k) << endl;
    vector<int>().swap(scoville);

    return 0;
}
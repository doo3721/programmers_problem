#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first, second, sum;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto scvl: scoville) {
        pq.push(scvl);
    }
    
    while(pq.top() <  K && pq.size() > 1) {
        first = pq.top(); pq.pop();
        second = pq.top(); pq.pop();
        sum = first + second*2;
        answer++;
        pq.push(sum);
    }
    
    if(pq.size() == 1 && pq.top() < K) answer = -1;
    
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
#include <iostream>
#include <string>
#include <vector>

using namespace std;



/*
 * 문제 영역
 */
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int max_size = 0;
    
    vector<int> que;
    vector<int>::iterator tr_w = truck_weights.begin();
    
    for(; tr_w != truck_weights.end(); tr_w++) {
        while(1) {
            if(que.empty()) {   // 다리위에 트럭이 없는 경우
                que.push_back(*tr_w);
                max_size += *tr_w;
                answer++;
                break;
            }
            else if(que.size() == bridge_length) {      // 큐의 사이즈가 다리 길이와 같을 때
                max_size -= que.front();
                que.erase(que.begin());
            }
            else {      // 다리위에 트럭이 존재하는 상태에서 새 트럭이 들어올 때
                if(*tr_w + max_size > weight) {     // 버티는 무게를 초과 할 경우, 큐에 0을 추가
                    que.push_back(0);
                    answer++;
                }
                else {      // 트럭이 들어오는 경우
                    que.push_back(*tr_w);
                    max_size += *tr_w;
                    answer++;
                    break;
                }
            }
        }
    }


    return answer+bridge_length;
}

/*
 * 테스트 영역
 */
int main()
{
    int bLength1 = 2; int bLength2 = 100; int bLength3 = 100; int bLength4 = 5;
    int bWeight1 = 10; int bWeight2 = 100; int bWeight3 = 100; int bWeight4 = 10;
    int tWeights1[4] = {7,4,5,6};
    int tWeights2[1] = {10};
    int tWeights3[10] = {10,10,10,10,10,10,10,10,10,10};
    int tWeights4[6] = {9,2,3,4,5,8};


    vector<int> tWeights;

    for(int weight: tWeights1) tWeights.push_back(weight);
    cout << solution(bLength1, bWeight1, tWeights) << endl;
    tWeights.clear();

    for(int weight: tWeights2) tWeights.push_back(weight);
    cout << solution(bLength2, bWeight2, tWeights) << endl;
    tWeights.clear();

    for(int weight: tWeights3) tWeights.push_back(weight);
    cout << solution(bLength3, bWeight3, tWeights) << endl;
    tWeights.clear();

    for(int weight: tWeights4) tWeights.push_back(weight);
    cout << solution(bLength4, bWeight4, tWeights) << endl;
    tWeights.clear();

    return 0;
}
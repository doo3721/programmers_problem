#include <iostream>
#include <string>
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 메모이제이션을 함으로써 lost와 reserve에 동일 사람이 있을 경우를
    // 자연스럽게 처리한다
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;

    // 0을 시작점으로 두지 않는다 (0번째 학생은 없기 때문)
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }

    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}


using namespace std;

int main(void) {
    vector<int> nums = {4, 5, 5, 3};
    vector<vector<int>> losts = {{1,2,4}, {2,4}, {2,4}, {3}};
    vector<vector<int>> reserves = {{2}, {1,3,5}, {3}, {1}};

    for(int i=0; i < nums.size(); i++) {
        cout << solution(nums[i], losts[i], reserves[i]) << " "; 
    }

    vector<int>().swap(nums);
    vector<vector<int>>().swap(losts);
    vector<vector<int>>().swap(reserves);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>::iterator lostR, fR, bR;
    
    for(lostR = lost.begin(); lostR < lost.end();) {
        if(reserve.empty()) break;
        
        if(*lostR == *find(reserve.begin(), reserve.end(), *lostR)) {
            reserve.erase(find(reserve.begin(), reserve.end(), *lostR));
            lost.erase(lostR);
            continue;
        }
        else {
            lostR++;
            continue;
        }
    }
    
    for(lostR = lost.begin(); lostR < lost.end();) {
        if(reserve.empty()) break;
        
        fR = find(reserve.begin(), reserve.end(), *lostR-1);
        bR = find(reserve.begin(), reserve.end(), *lostR+1);
        
        if((*lostR-1) == *fR) {
            reserve.erase(fR);
            lost.erase(lostR);

            continue;
        }
        else if((*lostR+1) == *bR) {
            reserve.erase(bR);
            lost.erase(lostR);
            continue;
        }
        else {
            lostR++;
            continue;
        }
    }
    
    answer = n - lost.size();
    
    return answer;
}

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
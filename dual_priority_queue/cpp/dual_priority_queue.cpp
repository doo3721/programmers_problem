#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> que;
    
    for(string op: operations) {
        
        if(op[0] == 'D') {
            if(stoi(op.substr(2)) == 1) {
                if(!que.empty()) 
                    que.erase(max_element(que.begin(), que.end()));
            }
            else {
                if(!que.empty()) 
                    que.erase(min_element(que.begin(), que.end()));
            }
        }
        else 
            que.push_back(stoi(op.substr(2)));
    
    }
    
    if(!que.empty()) {
        answer.push_back(*max_element(que.begin(), que.end()));
        answer.push_back(*min_element(que.begin(), que.end()));
    }
    else answer.assign(2, 0);
    
    return answer;
}

int main(void) {
    vector<vector<string>> operations_s = {{"I 16", "D 1"},
                                           {"I 7","I 5","I -5","D -1"}};

    for(auto operations: operations_s) {
        for(auto result: solution(operations)) {
            cout << result << " ";
        }
        cout << endl;
    }

    vector<vector<string>>().swap(operations_s);

    return 0;          
}
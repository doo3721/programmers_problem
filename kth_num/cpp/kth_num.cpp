#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for(auto cmd: commands) {
        temp = array;
        sort(temp.begin()+(cmd[0]-1), temp.begin()+cmd[1]);
        answer.push_back(temp[cmd[0]+cmd[2]-2]);
    }
    
    return answer;
}

int main(void)
{
    int array[7] = {1, 5, 2, 6, 3, 7, 4};
    int commands[3][3] = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> arrayV;
    vector<int> commandV;
    vector<vector<int>> commandsV;

    for(auto a: array) arrayV.push_back(a);
    for(int i=0; i < 3; i++) {
        for(auto b: commands[i]) commandV.push_back(b);
        commandsV.push_back(commandV);
        commandV.clear();
    }
    vector<int>().swap(commandV);

    for(auto result: solution(arrayV, commandsV)) cout << result << " ";
    cout << endl;
    vector<int>().swap(arrayV);
    vector<vector<int>>().swap(commandsV);

    return 0;
}
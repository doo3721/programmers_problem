#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

/*
 * 문제 영역
 */
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    multiset<string> ms1, ms2;
    
    for(const auto player: participant) ms1.insert(player);
    for(const auto player: completion) ms2.insert(player);
    
    for(const auto player: ms1) {
        if(ms1.count(player) != ms2.count(player)) {
            answer = player;
            break;
        }
    }
    return answer;
}

/*
 * 테스트 영역
 */
int main()
{
    string p1[3] = {"leo", "kiki", "eden"};
    string c1[2] = {"eden", "kiki"};
    string p2[5] = {"marina", "josipa", "nikola", "vinko", "filipa"};
    string c2[4] = {"josipa", "filipa", "marina", "nikola"};
    string p3[4] = {"mislav", "stanko", "mislav", "ana"};
    string c3[3] = {"stanko", "ana", "mislav"};

    vector<string> participant, completion;

    for(string player: p1) participant.push_back(player);
    for(string player: c1) completion.push_back(player);
    cout << solution(participant, completion) << endl;
    participant.clear(); completion.clear();

    for(string player: p2) participant.push_back(player);
    for(string player: c2) completion.push_back(player);
    cout << solution(participant, completion) << endl;
    participant.clear(); completion.clear();

    for(string player: p3) participant.push_back(player);
    for(string player: c3) completion.push_back(player);
    cout << solution(participant, completion) << endl;
    participant.clear(); completion.clear();

}
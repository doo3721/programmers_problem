/*
 * 가로 길이 = x, 세로 길이 = y
 * brown  = 2(x + y) - 4
 * x + y = (brown + 4)/2
 * x >= y
 * x,y > 2
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int brown_x, brown_y, red_x, red_y;
    int harf_peri = (brown + 4)/2;
    
    for(brown_y = 3; brown_y <= (harf_peri - brown_y); brown_y++) {
        brown_x = harf_peri - brown_y;
        red_x = brown_x - 2; red_y = brown_y - 2;
        if(red_x*red_y == red) {
            answer.push_back(brown_x);
            answer.push_back(brown_y);
            break;
        }
    }
    
    return answer;
}

int main(void) {

    vector<int> brown = {10,8,24};
    vector<int> red = {2,1,24};

    for(int i=0; i < brown.size(); i++) {
        for(int result: solution(brown[i], red[i]))
            cout << result << " ";
        cout << endl;
    }

    vector<int>().swap(brown);
    vector<int>().swap(red);

    return 0;
}
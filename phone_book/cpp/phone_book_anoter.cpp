#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    // 정렬을 한다 (사전순 마냥 정렬됨)
    sort(phoneBook.begin(), phoneBook.end());

    /* 
     * 한 번호가 다른 번호의 접두어인 경우
     * 접두어를 가진 번호는 그 접두어 번호의 다음 번호이다
     */
    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
    {
        if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) )
        {
            answer = false;
            break;
        }
    }

    return answer;
}

int main(void) {
    vector<vector<string>> phone_books = {{"119", "97674223", "1195524421"},
                                            {"123", "456", "789"},
                                            {"12", "123", "1235", "567", "88"}};
    
    for(vector<string> phone_book: phone_books) {
        cout << solution(phone_book) << endl;
    }

    vector<vector<string>>().swap(phone_books);

    return 0;
    
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution(short n) {
    for (int i = 0; i < n; i++) {
        string l1, l2;
        vector <int> l1Colons;
        vector <int> l2Colons;
        long long l1Num = 0, l2Num = 0;
        string l1NumS, l2NumS;

        cin >> l1 >> l2;

        // ----- Decoding -----
        for (int j = 0; j < l1.length(); j++)
            if (l1[j] == ':') l1Colons.push_back(j);
        for (int j = 0; j < l2.length(); j++)
            if (l2[j] == ':') l2Colons.push_back(j);
        if (l1Colons.size() == 0) l1NumS = l1;
        else {
            int colonNumber = 0;
            string temp = "";
            for (int j = 0; j < l1.length(); j++) {
                char ch = l1[j];
                if (ch != ':') temp += ch;
                else if (ch == ':' && colonNumber % 2 == 0) {
                    l1NumS.append(temp);
                    temp = "";
                    colonNumber++;
                }
                else if (ch == ':' && colonNumber % 2 != 0) {
                    l1NumS += string(stoi(temp), '0');
                    temp = "";
                    colonNumber++;
                }
            }
            l1NumS += temp;
        }
        if (l2Colons.size() == 0) l2NumS += l2;
        else {
            int colonNumber = 0;
            string temp = "";
            for (int j = 0; j < l2.length(); j++) {
                char ch = l2[j];
                if (ch != ':') temp += ch;
                else if (ch == ':' && colonNumber % 2 == 0) {
                    l2NumS.append(temp);
                    temp = "";
                    colonNumber++;
                }
                else if (ch == ':' && colonNumber % 2 != 0) {
                    l2NumS += string(stoi(temp), '0');
                    temp = "";
                    colonNumber++;
                }
            }
            l2NumS += temp;
        }
        
        // ----- Math -----

        l1Num = stoi(l1NumS);
        l2Num = stoi(l2NumS);

        long long sol = l1Num + l2Num;
        string solS = to_string(sol);

        // ----- Encoding -----
        int zeroNumber = 0;
        bool zeros = false;
        string temp = "";
        string output = "";

        for (int j = 0; j < solS.length(); j++) {
            char ch = solS[j];
            if (ch != '0' && zeros == false) temp += ch;
            else if (ch != '0' && zeros == true) {
                temp += ch;
                temp = "";
                zeros = false;
                zeroNumber = 0;
            }
            else if (ch == '0' && zeros == false) {
                output += temp;
                zeroNumber++;
                zeros == true;
                temp = "0";
            }
            else if (ch == '0' && zeros == true) {
                temp += '0';
                zeroNumber++;
            }
        }
    }
}

int main() {
    short n;
    cin >> n;

    solution(n);
}
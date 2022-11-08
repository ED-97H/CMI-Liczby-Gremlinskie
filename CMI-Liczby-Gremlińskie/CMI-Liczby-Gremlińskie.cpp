#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::to_string;

void solution(short n) {
    short nOfSol = 0;
    vector <string> inputs;
    for (int j = 0; j < n; j++) {
        string s1, s2;
        std::cin >> s1 >> s2;
        inputs.push_back(s1);
        inputs.push_back(s2);
    }

    for (int i = 0; i < n; i++) {
        long long l1ColonsNumber = 0, l2ColonsNumber = 0;
        long long l1Num = 0, l2Num = 0;
        string l1NumS, l2NumS;

        string l1 = inputs[nOfSol], l2 = inputs[nOfSol + 1];
        nOfSol += 2;

        // ----- Decoding -----
        for (int j = 0; j < l1.length(); j++)
            if (l1[j] == ':') l1ColonsNumber++;
        for (int j = 0; j < l2.length(); j++)
            if (l2[j] == ':') l2ColonsNumber++;
        if (l1ColonsNumber == 0) l1NumS = l1;
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
            if (colonNumber % 2 != 0) {
                l1NumS += string(stoi(temp), '0');
            }
            else l1NumS += temp;
        }
        if (l2ColonsNumber == 0) l2NumS += l2;
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
            if (colonNumber % 2 != 0) {
                l2NumS += string(stoi(temp), '0');
            }
            else l2NumS += temp;

        }

        // ----- Math -----
        l1Num = stoll(l1NumS);
        l2Num = stoll(l2NumS);
        long long sol = l1Num + l2Num;
        string solS = to_string(sol);
        // std::cout << "\nSolution in int: " << sol;

        // ----- Encoding -----
        int zeroNumber = 0;
        bool zeros = false;
        string temp = "";
        string output = "";

        for (int j = 0; j < solS.length(); j++) {
            char ch = solS[j];
            if (ch != '0' && zeros == false) temp += ch;
            else if (ch != '0' && zeros == true) {
                if (zeroNumber > 2) {
                    output += ':';
                    output += to_string(zeroNumber);
                    output += ':';
                }
                else output += string(zeroNumber, '0');
                temp = "";
                temp += ch;
                zeros = false;
                zeroNumber = 0;
            }
            else if (ch == '0' && zeros == false) {
                output += temp;
                temp = "";
                zeroNumber++;
                zeros = true;
            }
            else if (ch == '0' && zeros == true) zeroNumber++;
        }
        if (zeroNumber > 2) {
            output += ':';
            output += to_string(zeroNumber);
        }
        else if (zeroNumber < 3 && zeroNumber > 0) {
            output += string(zeroNumber, '0');
        }
        else output += temp;
        std::cout << std::endl << output;
    }
}

int main() {
    short n;
    std::cin >> n;

    solution(n);
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    string str;
    cin >> str;
    unordered_map<string, long long> hash;
    for (auto& e : str) {
        if (e == 's') {
            hash["s"]++;
        }
        else if (e == 'h') {
            hash["sh"] += hash["s"];
        }
        else if (e == 'y') {
            hash["shy"] += hash["sh"];
        }
    }
    cout << hash["shy"];
    return 0;
}


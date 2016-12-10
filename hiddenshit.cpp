#include <iostream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main() {

#include <bits/stdc++.h>

using namespace std;

int main(){
    string word;
    string palindrome;
    cin >> word;
    palindrome = word;
    reverse(palindrome.begin(), palindrome.end());
    if (word == palindrome) {
        cout << word.size() << endl;
    } else {
        for (int j = 0; j < word.size() - 3; j++) {
          for (int l = 1; l < word.size() - 2; ) {
            for (int i = 0; i < word.size() - l; i++) {
                if (word[i + j] == palindrome[i + l]) {
                    if (i == word.size() - l - 1) {
                        cout << word.size() - l << endl;
                        return 0;
                    }
                } else if (palindrome [i + j] == word[i + l]) {
                        if (i == word.size() - l - 1) {
                            cout << word.size() - l << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}


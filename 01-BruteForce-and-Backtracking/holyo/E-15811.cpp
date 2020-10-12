#include <iostream>
#include <string>
#include <vector>

using namespace std;

string word1, word2, result;
bool alph_exist[26];
vector<int> alph;
bool num_selected[10];
int alph_to_num[26];
bool answer = false;

void check_exist(string word) {
    for (int i = 0; i < word.length(); i++) {
        alph_exist[word[i] - 'A'] = true;
    }
}

int convert(string word) {
    int num = 0;
    for (int i = 0; i < word.length(); i++) {
        num *= 10;
        num += alph_to_num[word[i] - 'A'];
    }
    return num;
}

void assign(int n) {
    if (n == alph.size()) {
        if (convert(word1) + convert(word2) == convert(result)) {
            answer = true;
        }
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        if (!num_selected[i]) {
            num_selected[i] = true;
            alph_to_num[alph[n]] = i;
            asign(n + 1);
            num_selected[i] = false;
        }
    }
}

int main() {
    cin >> word1 >> word2 >> result;
    
    check_exist(word1);
    check_exist(word2);
    check_exist(result);
    
    for (int i = 0; i < 26; i++) {
        if (alph_exist[i]) alph.push_back(i);
    }
    
    if (alph.size() > 10) {
        cout << "NO\n";
        return 0;
    }
    
    assign(0);
    
    if (answer) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

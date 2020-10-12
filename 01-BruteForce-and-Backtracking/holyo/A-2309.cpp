#include <iostream>
#include <algorithm>

using namespace std;

int dwarf[9];

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", dwarf + i);
    }
    
    sort(dwarf, dwarf + 9);
    
    do {
        int sum_of_height = 0;
        for (int i = 0; i < 7; i++) {
            sum_of_height += dwarf[i];
        }
        if (sum_of_height == 100) break;
    } while (next_permutation(dwarf, dwarf + 9));
    
    for (int i = 0; i < 7; i++) printf("%d\n", dwarf[i]);
    
    return 0;
}

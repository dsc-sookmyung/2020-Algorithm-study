#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct person {
    char name[11];
    int guger;
    int math;
    int eng;
} member [100000];

bool cmp(struct person a, struct person b) {
    if (a.guger == b.guger) {
    	if (a.eng == b.eng) {
    		if (a.math == b.math) {
    			if (strcmp(a.name, b.name) < 0) return true;
    			else return false;
    		} else
    			return a.math > b.math;
    	} else
    		return a.eng < b.eng;
    } else
        return a.guger > b.guger;
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", member[i].name, &member[i].guger, &member[i].eng, &member[i].math);
    }
    sort(member, member + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", member[i].name);
    }
}

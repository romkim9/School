#include <stdio.h>
#include <stdbool.h>

#define SIZE 4 

bool isEquivalenceRelation(bool relation[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!relation[i][i]) {
            return false;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (relation[i][j] != relation[j][i]) {
                return false;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (relation[i][j]) {
                for (int k = 0; k < SIZE; k++) {
                    if (relation[j][k] && !relation[i][k]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void printEquivalenceClasses(bool relation[SIZE][SIZE]) {
    bool printed[SIZE] = {false};

    for (int i = 0; i < SIZE; i++) {
        if (!printed[i]) {
            printf("Class { ");
            for (int j = 0; j < SIZE; j++) {
                if (relation[i][j]) {
                    printf("%d ", j);
                    printed[j] = true;
                }
            }
            printf("}\n");
        }
    }
}

int main() {
    bool relation[SIZE][SIZE] = {
        {true, true, false, false},
        {true, true, false, false},
        {false, false, true, true},
        {false, false, true, true}
    };

    if (isEquivalenceRelation(relation))
        printEquivalenceClasses(relation);

    return 0;
}


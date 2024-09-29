#include <stdio.h>
#include <time.h>

#define MAX 50

int n, a[MAX][MAX], count = 0, reach[MAX], pos[MAX];

void read_matrix();
void dfs(int v);
int adjacent(int i);
int checkreach(int u);

int main() {
    int v;
    double clk;
    clock_t starttime, endtime;

    printf("\n\t\t\t DEPTH FIRST SEARCH \n");
    printf("\n Enter number of Lands to be surveyed: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pos[i] = 0;
        reach[i] = 0; // Initialize reach array
    }

    read_matrix();

    printf("\n Enter the starting Land number: ");
    scanf("%d", &v);

    starttime = clock();
    dfs(v);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\n Vertices reached from the given vertex are...\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t", reach[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}

void read_matrix() {
    printf("\n Enter the adjacency matrix (Enter 0/1)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                printf("(%d,%d): ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            } else {
                a[i][j] = 0;
            }
        }
    }
}

void dfs(int v) {
    int u;
    reach[count++] = v;
    while ((u = adjacent(v)) != 0) {
        if (!checkreach(u)) {
            dfs(u);
        }
    }
}

int adjacent(int i) {
    for (int j = pos[i]; j < n; j++) {
        if (a[i][j] == 1) {
            pos[i] = j + 1;
            return j;
        }
    }
    pos[i] = n;
    return 0;
}

int checkreach(int u) {
    for (int i = 0; i < count; i++) {
        if (reach[i] == u) {
            return 1;
        }
    }
    return 0;
}

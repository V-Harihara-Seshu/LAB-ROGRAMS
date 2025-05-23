 #include <stdio.h>
#define INFINITY 999
#define MAX 100

struct EDGE {
    int x, y, wt;
} e[MAX];

int parent[MAX];
int cost[MAX][MAX];
int t[MAX][2];
int nedges = 0;
int eno = 0;

void sort_edges() {
    int i, j;
    struct EDGE temp;
    for (i = 0; i < nedges - 1; i++) {
        for (j = 0; j < nedges - i - 1; j++) {
            if (e[j].wt > e[j + 1].wt) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int get_parent(int v) {
    while (parent[v]) {
        v = parent[v];
    }
    return v;
}

void join(int i, int j) {
    parent[j] = i;
}

void kruskal(int n) {
    int i, j, k, sum = 0;
    int edge_count = 0;

    for (k = 0; edge_count < n - 1 && k < nedges; k++) {
        int u_root = get_parent(e[k].x);
        int v_root = get_parent(e[k].y);

        if (u_root != v_root) {
            join(u_root, v_root);
            t[edge_count][0] = e[k].x;
            t[edge_count][1] = e[k].y;
            sum += e[k].wt;
            edge_count++;
        }
    }

    printf("\nCost of the spanning tree is: %d\n", sum);
    printf("\nThe edges of the spanning tree are:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d -> %d\n", t[i][0], t[i][1]);
    }
}

int main() {
    int i, j, n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize parent array
    for (i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    printf("Enter the cost adjacency matrix (0 = self-loop, 999 = no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (i < j && cost[i][j] != 0 && cost[i][j] != INFINITY) {
                e[nedges].x = i;
                e[nedges].y = j;
                e[nedges].wt = cost[i][j];
                nedges++;
            }
        }
    }

    sort_edges();
    kruskal(n);

    return 0;
}

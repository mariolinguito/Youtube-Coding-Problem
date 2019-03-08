#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BST_LEN 8

struct node {
    int info;
    struct node *sx;
    struct node *dx;
};

typedef struct node NODE;
NODE *punt;

void build_BST(int []);
void search_second_max(NODE *, int **);

int main(int argc, char *argv[]) {
    int nodes_1[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    build_BST(nodes_1);
}

void build_BST(int nodes[]) {
    NODE *root = (NODE *)calloc(1, sizeof(NODE));
    root->sx = NULL; root->dx = NULL;
    root->info = nodes[0];
    
    NODE *data, *current;
    
    for(int i = 1; i < BST_LEN+1; i++) {
        data = (NODE *)calloc(1, sizeof(NODE));
        data->sx = NULL; data->dx = NULL;
        data->info = nodes[i];
        
        current = root;

        while(current->sx != NULL || current->dx != NULL) {
            if(data->info <= current->info && current->sx != NULL) {
                current = current->sx;
            } else if(data->info >= current->info && current->dx != NULL) {
                current = current->dx;
            } else {
                break;
            }
        }
        
        if(data->info <= current->info) {
            current->sx = data;
            printf("%d is sx of %d\n", data->info, current->info);
        } else {
            current->dx = data;
            printf("%d is dx of %d\n", data->info, current->info);
        }
    }
    
    int *trv = (int *)calloc(1, sizeof(int));
    search_second_max(root, &trv);
}

void search_second_max(NODE *root, int **trv) {
    if(root == NULL) {
        return;
    }
    
    search_second_max(root->sx, trv);
    
    if((**trv)++ == BST_LEN-1) {
        printf("NODO -> %d\n", root->info);
    }
    
    search_second_max(root->dx, trv);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BST_SIZE 8

struct node {
    int         info;
    struct node *sx;
    struct node *dx;
};

typedef struct node NODE;
NODE *punt;

void build_BST(int []);

int main(int argc, char *argv[]) {
    int nodes[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    build_BST(nodes);
}

void build_BST(int nodes[]) {
    NODE *root = (NODE *)calloc(1, sizeof(NODE));
    root->sx   = NULL;
    root->dx   = NULL;
    root->info = nodes[0];
    
    NODE *data, *current;
    
    for(int i = 1; i < BST_SIZE+1; i++) {
        data       = (NODE *)calloc(1, sizeof(NODE));
        data->sx   = NULL;
        data->dx   = NULL;
        data->info = nodes[i];
        
        current    = root;
        
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
            printf("%d è sx di %d\n", data->info, current->info);
        } else {
            current->dx = data;
            printf("%d è dx di %d\n", data->info, current->info);
        }
    }
}

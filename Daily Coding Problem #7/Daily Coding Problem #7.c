#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_FL 5
#define SIZE_SL 4

// We define a struct with two fields, the first
// field is the info, the second is an
// autoreference punter to the same struct.
struct node {
    int          info;
    struct node *p_next;
};

// So we define a new type that we call NODE, and
// after declaring a series of punter like the heads
// of the two lists, and other, like the two sentinels.
typedef struct node NODE;
NODE *head_1, *head_2, *punt_1, *punt_2, *s_head, *s_tile;

void show_linked_list();

// With a classic linked list, we have three functions
// for the insertion into the list: The insertion at
// the head, the insertion at the end of the list,
// and the classic insertion.
void ins_head(NODE *, int, NODE **);
void ins_tile(NODE *, int, NODE **);
void ins(NODE *, int, NODE **, int);

// With a linked list with sentinel, we have only one
// function for the same operation.
void ins_s(NODE *, int, NODE **, int);

// We make the same reasoning for the elimination.
void elim_head(NODE **);
void elim_tile(NODE **);
void elim(NODE **, int);

void elim_s(NODE **, int);

// The function searches the first intersection
// node of the two linked lists. In input, it
// has the head of the first list and the head
// of the second head of the second list.
int search_int(NODE *, NODE *);

int main(int argc, char *argv[]) {
    int inters = 0;
    
    // For the sentinel at the head of the
    // list, we allocate memory with the
    // buffer manipulation function. And
    // into the info field we insert a dummy
    // info, because this is a dummy node.
    s_head = (NODE *)calloc(1, sizeof(NODE));
    s_head->info = -1;
    s_head->p_next = NULL;
    
    // We can do the same operations for the
    // sentinel at the end of the list.
    s_tile = (NODE *)calloc(1, sizeof(NODE));
    s_tile->info = -1;
    s_tile->p_next = NULL;
    
    // Of course, the head should punt to
    // the sentinel (the sentinel at the
    // head of the list.
    s_head->p_next = s_tile;
    
    NODE *node_to_insert;
    head_1 = s_head; head_2 = NULL;
    
    show_linked_list();
    
    // For the initialization of the two lists, we
    // have two arrays of integers. So, with two
    // for loop, we can insert into the two lists
    // the elements of the array.
    int ele_first_list[SIZE_FL] = {10, 11, 3, 7, 3};
    int ele_second_list[SIZE_SL] = {10, 8, 1, 99};
    
    for(int index = 0; index < SIZE_FL; index++) {
        // For the insertion, we allocate memory for
        // the node to insert, the info field is
        // filled with the index element of the array
        // and then we insert into the list the current node.
        node_to_insert = (NODE *)calloc(1, sizeof(NODE));
        node_to_insert->info = ele_first_list[index];
        
        // We can use the classic function or the function for
        // the list that uses the sentinel.
        // ins_head(node_to_insert, sizeof(node_to_insert), &head_1);
        ins_s(node_to_insert, sizeof(node_to_insert), &punt_1, index);
        free(node_to_insert);
    }
    
    // If you want to understand why this code is
    // commented, watch my video on YouTube.
    
    /*
    for(int jndex = 0; jndex < SIZE_SL; jndex++) {
        node_to_insert = (NODE *)calloc(1, sizeof(NODE));
        node_to_insert->info = ele_second_list[jndex];
        ins_head(node_to_insert, sizeof(node_to_insert), &head_2);
        free(node_to_insert);
    }
     */
    
    /*
    if((inters = search_int(head_1, head_2)) == -1) {
        perror("Non ci sono punti di intersezione.\n");
        exit(-1);
    } else {
        printf("Inters: %d\n", inters);
    }
     */
    
    node_to_insert = (NODE *)calloc(1, sizeof(NODE));
    node_to_insert->info = 100;
    
    /*
    ins_tile(node_to_insert, sizeof(node_to_insert), &punt_1);
    show_linked_list();
    
    ins(node_to_insert, sizeof(node_to_insert), &punt_1, 0);
    show_linked_list();
    
    elim_head(&head_1);
    
    show_linked_list();
    
    elim_tile(&punt_1);
    
    show_linked_list();
    
    elim(&punt_1, 2);
    
    show_linked_list();
     */
    
    ins_s(node_to_insert, sizeof(node_to_insert), &punt_1, 3);
    show_linked_list();
    
    ins_s(node_to_insert, sizeof(node_to_insert), &punt_1, 6);
    show_linked_list();
    
    free(node_to_insert);
    
    elim_s(&punt_1, 1);
    show_linked_list();
    
    elim_s(&punt_1, 0);
    show_linked_list();
    
    elim_s(&punt_1, 4);
    show_linked_list();
}

// With this function we insert the node at the head of the
// linked list.
void ins_head(NODE *node_to_insert, int node_size, NODE **head) {
    NODE *ptr = (NODE *)calloc(1, sizeof(NODE));
    memcpy(ptr, node_to_insert, node_size);
    
    ptr->p_next = *head;
    *head = ptr;
}

// With this function we insert the node at the end
// if the linked list.
void ins_tile(NODE *node_to_insert, int node_size, NODE **punt) {
    NODE *ptr = (NODE *)calloc(1, sizeof(NODE));
    memcpy(ptr, node_to_insert, node_size);
    
    *punt = head_1;
    while((*punt)->p_next != NULL) {
        (*punt) = (*punt)->p_next;
    }
    
    (*punt)->p_next = ptr;
    ptr->p_next = NULL;
}

// With this function we insert the node everywhere into the
// linked list.
void ins(NODE *node_to_insert, int node_size, NODE **punt, int prv_node) {
    int index = 0;
    
    NODE *ptr = (NODE *)calloc(1, sizeof(NODE));
    memcpy(ptr, node_to_insert, node_size);
    
    (*punt) = head_1;
    while((*punt) != NULL && index < prv_node) {
        (*punt) = (*punt)->p_next;
        index++;
    }
    
    ptr->p_next = (*punt)->p_next;
    (*punt)->p_next = ptr;
    
}

// With this function we delete the node at the head
// of the linked list.
void elim_head(NODE **head) {
    NODE *node_to_delete;
    node_to_delete = (*head);
    
    *head = (*head)->p_next;
    free(node_to_delete);
}

// With this function we delete the node at the end
// of the linked list.
void elim_tile(NODE **punt_1) {
    (*punt_1) = head_1;
    while(((*punt_1)->p_next)->p_next != NULL) {
        (*punt_1) = (*punt_1)->p_next;
    }
    
    free((*punt_1)->p_next);
    (*punt_1)->p_next = NULL;
}

// With this function we delete the node everywhere
// from the linked list.
void elim(NODE **punt_1, int prv_node) {
    NODE *node_to_delete;
    int index = 0;
    
    (*punt_1) = head_1;
    while((*punt_1) != NULL && index < prv_node-1) {
        (*punt_1) = (*punt_1)->p_next;
        index++;
    }
    
    node_to_delete = (*punt_1)->p_next;
    (*punt_1)->p_next = ((*punt_1)->p_next)->p_next;
    free(node_to_delete);
}

// With this function we can insert a node into the list
// everywhere we want, because the list has the sentinel
// node.
void ins_s(NODE *node_to_insert, int node_size, NODE **punt, int node) {
    int index = 0;
    
    NODE *ptr = (NODE *)calloc(1, sizeof(NODE));
    memcpy(ptr, node_to_insert, node_size);
    
    (*punt) = head_1;
    while((*punt)->p_next != NULL && index < node) {
        (*punt) = (*punt)->p_next;
        index++;
    }
    
    ptr->p_next = (*punt)->p_next;
    (*punt)->p_next = ptr;
}

// With this function, we delete a node from the list
// everywhere we want.
void elim_s(NODE **punt, int node) {
    int index = 0;
    
    (*punt) = head_1;
    while((*punt)->p_next != NULL && index < node) {
        (*punt) = (*punt)->p_next;
        index++;
    }
    
    (*punt)->p_next = ((*punt)->p_next)->p_next;
}

int search_int(NODE *head_1, NODE *head_2) {
    int inters = -1;
    
    punt_1 = head_1;
    punt_2 = head_2;
    
    // With the loop, we scroll the two list and with
    // every iteration, we confront the info field of
    // the two nodes of the two lists. If we find two
    // nodes with the same info and the same position
    // into the linked list, we break the while.
    while(punt_1 != NULL && punt_2 != NULL) {
        if(punt_1->info == punt_2->info) {
            inters = punt_1->info;
            break;
        } else {
            punt_1 = punt_1->p_next;
            punt_2 = punt_2->p_next;
        }
    }
    
    return inters;
}

void show_linked_list() {
    punt_1 = head_1;
    while(punt_1 != NULL) {
        printf("%d\t", punt_1->info);
        punt_1 = punt_1->p_next;
    }   printf("\n");
}

/*
 
 head -> NULL => head -> 3 -> NULL
 head -> -1 -> 4 -> 3 -> -1 -> NULL
 
 */

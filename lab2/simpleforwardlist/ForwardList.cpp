//
// Created by bartek on 06.03.17.
//

#include "ForwardList.h"

using namespace std;

struct Node{
    struct Node *next;
    int value;
};

struct ForwardList{
    Node *head;
    Node *tail;
};

void init(ForwardList *list){
    list->head = 0;
    list->tail = 0;
}

void Append(ForwardList *list,int value){
    Node* element = new Node;
    element->next = 0;
    element->value = value;
    if(list->head){
        list->tail->next = element;
        list->tail = element;
    }else list->tail=list->head=element;
}

ForwardList *PushFront(ForwardList *list, int value){
    Node* element = new Node;
    element->value = value;
    element->next = 0;
    if(list->head){
        element->next = list->head;
        list->head = element;
    }else list->tail = list->head = element;
    return list;
}

void printList(ForwardList *list){
    if(!list->head) cout << "Pusta Lista" <<endl;
    else{
        Node *element;
        element = list->head;
        while(element){
            cout << element->value << endl;
            element = element->next;
        }
    }
}

void DestroyList(ForwardList *list){
    Node *element;
    element = list->head;
    while(element){
        delete element;
        element = element->next;
    }
}
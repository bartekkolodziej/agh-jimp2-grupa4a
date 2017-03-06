//
// Created by bartek on 06.03.17.
//

#ifndef JIMP_EXERCISES_FORWARDLIST_H_H
#define JIMP_EXERCISES_FORWARDLIST_H_H

#include<iostream>

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);
ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);

#endif //JIMP_EXERCISES_FORWARDLIST_H_H

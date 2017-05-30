//
// Created by kolobart on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

namespace tree{


    template <class T>
    class Node{
    public:
        Node(){};
        Node(T data){
            this->data = data;
            left = nullptr;
            right = nullptr;
            up = nullptr;
        };

        ~Node(){};

        T data;
        std::unique_ptr<Node<T>> up, left, right;
    };


    template <class T>
    class Tree{
    public:
        Tree(T element){
            size = 1;
            depth = 1;
            root = std::make_unique<Node<T>>(element);
        };
        Tree(){};
        ~Tree(){};

        T Value(){return root->data;};

        void Insert(const T &element){
            size_t tmp = 1;
            Node<T> * iterator = root.get();
            while(true){
                if(element > iterator->data){
                    if(iterator->right) {
                        iterator = iterator->right.get();
                        tmp++;
                    }
                    else {
                        iterator->right = std::make_unique<Node<T>>(element);
                        if(tmp+1 > depth) depth = tmp+1;
                        break;
                    }
                }
                else{
                    if(iterator->left) {
                        iterator = iterator->left.get();
                        tmp++;
                    }
                    else {
                        iterator->left = std::make_unique<Node<T>>(element);
                        if(tmp+1 > depth) depth = tmp+1;
                        break;
                    }
                }
            }
            size++;
        };

        bool Find(const T &element){
            Node<T> * iterator = root.get();
            while(true) {
                if (iterator->data == element) return true;
                if (element > iterator->data) {
                    if (iterator->right) iterator = iterator->right.get();
                    else return false;
                } else {
                    if (iterator->left) iterator = iterator->left.get();
                    else return false;
                }

            }

        }

        size_t Size(){return size;};
        size_t Depth(){return depth;};

        size_t size;
        size_t depth;

        std::unique_ptr<Node<T>> root;

    };



}


#endif //JIMP_EXERCISES_TREE_H

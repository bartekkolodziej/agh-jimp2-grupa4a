//
// Created by bartosz on 18.03.17.
//

#include "SmartTree.h"
namespace datastructures {
    std::unique_ptr<SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> leaf;
        leaf->value=value;
        return leaf;
    }

    void Dump(const std::unique_ptr<SmartTree> &tree, std::string *dumped){
        (*dumped)+=tree->value;
        if (tree->left) Dump(tree->left,dumped);
        else (*dumped)+="[none]";
        if (tree->left) Dump(tree->right,dumped);
        else (*dumped)+="[none]";
        (*dumped)+="]";
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left=left_subtree;
        return tree;
    }

    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=right_subtree;
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if (unique_ptr->left!=nullptr)PrintTreeInOrder(unique_ptr->left, std::ostream *out);
        printf("%d",unique_ptr->value);
        if (unique_ptr->right!=nullptr)PrintTreeInOrder(unique_ptr->right, std::ostream *out);
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        std::string dumped="[";
        dumped+=tree->value;
        if (tree->left) Dump(tree->left,&dumped);
        else dumped+="[none]";
        if (tree->left) Dump(tree->right,&dumped);
        else dumped+="[none]";
        dumped+="]";
        return dumped;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree);
}
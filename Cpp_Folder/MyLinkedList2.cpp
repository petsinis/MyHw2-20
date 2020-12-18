#include "MyLinkedList2.h"

MyLinkedList2::MyLinkedList2(int number)
{
    this->number=number;
    left=nullptr;
    right=nullptr;
}

MyLinkedList2::~MyLinkedList2()
{
    //dtor
}

void MyLinkedList2::setNumber(int number)
{
    this->number=number;
}

void MyLinkedList2::setLeft(MyLinkedList2* left)
{
    this->left=left;
}

void MyLinkedList2::setRight(MyLinkedList2* right)
{
    this->right=right;
}

int MyLinkedList2::getNumber()
{
    return(this->number);
}

MyLinkedList2* MyLinkedList2::getLeft()
{
    return(this->left);
}

MyLinkedList2* MyLinkedList2::getRight()
{
    return(this->right);
}

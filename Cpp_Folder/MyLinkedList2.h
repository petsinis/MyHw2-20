#ifndef MYLINKEDLIST2_H
#define MYLINKEDLIST2_H
using namespace std;
#include <iostream>

class MyLinkedList2
{
    int number;
    MyLinkedList2 *left;
    MyLinkedList2 *right;

    public:
        MyLinkedList2(int);
        virtual ~MyLinkedList2();

        virtual void setNumber(int);
        virtual void setLeft(MyLinkedList2*);
        virtual void setRight(MyLinkedList2*);

        virtual int getNumber();
        virtual MyLinkedList2* getLeft();
        virtual MyLinkedList2* getRight();



    protected:

    private:
};

#endif // MYLINKEDLIST_H

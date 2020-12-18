#ifndef DOUBLELINKEDLIST2_H
#define DOUBLELINKEDLIST2_H
#include "MyLinkedList2.h"

class DoubleLinkedList2
{
    MyLinkedList2 *start;
    MyLinkedList2 *finish;


    public:
        DoubleLinkedList2(int);
        virtual ~DoubleLinkedList2();

        virtual MyLinkedList2* getStart();
        virtual MyLinkedList2* getFinish();


        virtual bool insertAtStart(int);
        virtual bool insertAtEnd(int);

        virtual bool insertAfter(int,int);
        virtual bool insertBefore(int,int);

        virtual bool deleteStart();
        virtual bool deleteFinish();
        virtual bool deleteNode(int);

        virtual void printAllStart();
        virtual void printAllEnd();

        virtual void crossAll();
        virtual long countAll();
        virtual void deletePerStep(int step,int r);
        virtual bool deletePointer(MyLinkedList2* temp);


    protected:

    private:
        virtual MyLinkedList2* searchFor(int);
};

#endif // DOUBLELINKEDLIST_H

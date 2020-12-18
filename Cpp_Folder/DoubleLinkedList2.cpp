#include "DoubleLinkedList2.h"

DoubleLinkedList2::DoubleLinkedList2(int number)
{
    MyLinkedList2* start_end=new MyLinkedList2(number);
    start=start_end;
    finish=start_end;
}

DoubleLinkedList2::~DoubleLinkedList2()
{
    if(start==nullptr){
        return;
    }
    MyLinkedList2* temp1=start;
    MyLinkedList2* temp2=nullptr;
    while(((*temp1).getRight())!=nullptr){
        temp2=(*temp1).getRight();
        delete(temp1);
        temp1=temp2;
    }
}

bool DoubleLinkedList2::insertAtStart(int number)
{
    MyLinkedList2* node=new MyLinkedList2(number);
    if(start==nullptr){
        return(false);
    }
    (*node).setRight(start);
    (*start).setLeft(node);
    start=node;
    return(true);
}

bool DoubleLinkedList2::insertAtEnd(int number)
{
    MyLinkedList2* node=new MyLinkedList2(number);
    if(finish==nullptr){
        return(false);
    }
    (*node).setLeft(finish);
    (*finish).setRight(node);
    finish=node;
    return(true);
}

MyLinkedList2*  DoubleLinkedList2::searchFor(int number)
{
    if(start==nullptr){
        return(nullptr);
    }
    MyLinkedList2* temp=start;
    if((*temp).getNumber()==number){
        return temp;
    }

    while(((*temp).getRight())!=nullptr){
        temp=(*temp).getRight();
        if((*temp).getNumber()==number){
            return temp;
        }
    }
    return(nullptr);
}


bool DoubleLinkedList2::insertBefore(int number,int search_num)
{
    MyLinkedList2* temp=searchFor(search_num);
    if(temp==nullptr){
        return(false);
    }
    MyLinkedList2* node=new MyLinkedList2(number);

    (*node).setRight(temp);
    if(temp!=start){
        (*node).setLeft((*temp).getLeft());
        (*((*temp).getLeft())).setRight(node);
    }
    else{

        start=node;
    }
    (*temp).setLeft(node);
    return(true);

}

bool DoubleLinkedList2::insertAfter(int number,int search_num)
{
    MyLinkedList2* temp=searchFor(search_num);
    if(temp==nullptr){
        return(false);
    }
    MyLinkedList2* node=new MyLinkedList2(number);

    (*node).setLeft(temp);
    if(temp!=finish){
        (*node).setRight((*temp).getRight());
        (*((*temp).getRight())).setLeft(node);
    }
    else{
        finish=node;
    }
    (*temp).setRight(node);

    return(true);

}

bool DoubleLinkedList2::deleteStart()
{
    if(start==nullptr)
    {
        return(false);
    }
    if(start==finish){
        delete(start);
        return(true);
    }
     MyLinkedList2* temp=(*start).getRight();
     delete(start);

     start=temp;
     (*(start)).setLeft(nullptr);
     return(true);
}

bool DoubleLinkedList2::deleteNode(int number)
{
     MyLinkedList2* temp=searchFor(number);
     if(temp==nullptr)
     {
        return(false);
     }
     if(start==temp){
        return(deleteStart());
     }
     if(start==finish){
          return(deleteFinish());
     }
     MyLinkedList2* temp_left=(*temp).getLeft();
     MyLinkedList2* temp_right=(*temp).getRight();

     delete((*(temp_left)).getRight());


     ((*(temp_left)).setRight(temp_right));
     ((*(temp_right)).setLeft(temp_left));


     return(true);

}


bool DoubleLinkedList2::deleteFinish()
{
    if(start==nullptr)
    {
        return(false);
    }
    if(start==finish){
        delete(start);
        return(true);
    }
     MyLinkedList2* temp=(*finish).getLeft();
     delete(finish);
     finish=temp;
     (*(finish)).setRight(nullptr);

     return(true);
}



MyLinkedList2* DoubleLinkedList2::getStart()
{
    return(start);
}

MyLinkedList2* DoubleLinkedList2::getFinish()
{
    return(finish);

}

void DoubleLinkedList2::printAllStart()
{
    if(start==nullptr){
        return;
    }
    MyLinkedList2* temp=start;
    cout<<(*temp).getNumber();
    cout<<" ";
    while(((*temp).getRight())!=nullptr){
        temp=(*temp).getRight();
        cout<<(*temp).getNumber();
        cout<<" ";
    }
    cout<<endl;
}


void DoubleLinkedList2::printAllEnd()
{
    if(finish==nullptr){
        return;
    }
    MyLinkedList2* temp=finish;
    cout<<(*temp).getNumber();
    cout<<" ";
    while(((*temp).getLeft())!=nullptr){
        temp=(*temp).getLeft();
        cout<<" ";
    }
    cout<<endl;
}

void DoubleLinkedList2::crossAll()
{
    if(start==nullptr){
        return;
    }
    MyLinkedList2* temp=start;
    while(((*temp).getRight())!=nullptr){
        temp=(*temp).getRight();
    }
}

long DoubleLinkedList2::countAll()
{
    long countd=0;
    if(start==nullptr){
        return 0;
    }
    countd=1;
    MyLinkedList2* temp=start;
    while(((*temp).getRight())!=nullptr){
        temp=(*temp).getRight();
        countd=countd+1;
    }
    return countd;
}


void DoubleLinkedList2::deletePerStep(int step,int r)
	{
		int countd=0;
	    if(start==nullptr){
	        return;
	    }
	    MyLinkedList2* temp=start;
	    MyLinkedList2* temp2=nullptr;
	    while(((*temp).getRight())!=nullptr){
	    	temp2=temp;
	        temp=(*temp).getRight();
	        countd=countd+1;
	        if(((countd-1)%step)<=r) {
	        	//System.out.println(temp2.number);
	        	deletePointer(temp2);
	        }
	    }
	}

bool DoubleLinkedList2::deletePointer(MyLinkedList2* temp)
{

     if(temp==nullptr)
     {
        return(false);
     }
     if(start==temp){
        return(deleteStart());
     }
     if(start==finish){
          return(deleteFinish());
     }
     MyLinkedList2* temp_left=(*temp).getLeft();
     MyLinkedList2* temp_right=(*temp).getRight();

     delete((*(temp_left)).getRight());


     ((*(temp_left)).setRight(temp_right));
     ((*(temp_right)).setLeft(temp_left));


     return(true);

}



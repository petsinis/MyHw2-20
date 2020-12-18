#include <iostream>
#include "MyLinkedList2.h"
#include "DoubleLinkedList2.h"
#include <chrono>
using namespace std::chrono;

using namespace std;



int main()
{

    DoubleLinkedList2  *  double_link2;
    double_link2=new DoubleLinkedList2(0);

    auto start2 = high_resolution_clock::now();
    for(int i=1;i<170000000;i++) {
            (*double_link2).insertAtEnd(i);
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << duration2.count() << endl;

    auto start = high_resolution_clock::now();
    for(int i=0;i<20;i++) {
        DoubleLinkedList2* double_link4;
        double_link4=new DoubleLinkedList2(0);
        for(int j=1;j<34000000;j++) {
            (*double_link4).insertAtEnd(j);
        }
        delete(double_link4);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() << endl;

    cout << (*double_link2).countAll() << endl;
    return 0;

}


#include <iostream>
#include "MyLinkedList2.h"
#include "DoubleLinkedList2.h"
#include <chrono>

using namespace std::chrono;

using namespace std;



int main(int argc, char *argv[])
{
        DoubleLinkedList2  *double_link2;
        DoubleLinkedList2  *double_link3;
        DoubleLinkedList2  *double_link4;
		
        double_link2=new DoubleLinkedList2(0);
        double_link3=new DoubleLinkedList2(0);
        double_link4=new DoubleLinkedList2(0);


        for(int i=1;i<150000000;i++) {
            if(i%250==0.0) {
                (*double_link2).insertAtEnd(i);
            }
            else {
                (*double_link4).insertAtEnd(i);
            }
        }
        delete(double_link4);

        for(int i=1;i<160000000;i++) {
            (*double_link3).insertAtEnd(i);
        }
        delete(double_link3);

		
        auto start2 = high_resolution_clock::now();
        (*double_link2).crossAll();
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
        cout << (duration2.count()) << endl;


        DoubleLinkedList2  *double_link5;
        double_link5=new DoubleLinkedList2(0);
        for(int i=1;i<600000;i++) {
            (*double_link5).insertAtEnd(i);
        }
        auto start3 = high_resolution_clock::now();
        (*double_link5).crossAll();
        auto stop3 = high_resolution_clock::now();
        auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
        cout << (duration3.count()) << endl;

		return 0;
}


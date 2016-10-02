//
//  main.cpp
//  HomeWork_2
//
//  Created by Zhongheng Li on 9/27/16.
//  Copyright © 2016 NYU. All rights reserved.
//



#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>
#include "assert.h"

using namespace std;



class Node {
    
private:
    
    int data;
    Node* link;
    
public:
    
    Node();
    
    Node(int newData, Node* newLink);
    int getData();
    void  setData(int newData);
    Node* getLink();
    void setLink(Node* newLink);
    
};



Node::Node(){
    
    data = NULL;
    link = NULL;
    
};

Node::Node(int newData, Node* newLink){
    
    setData(newData);
    setLink(newLink);
  
}

Node* Node::getLink(){
    
    return link;
    
};


void Node::setLink(Node* newLink){
    
    link = newLink;
    
}

int Node::getData(){
    
    return data;
}

void Node::setData(int newData){
    
    data = newData;
}


class LinkedList{
    
public:
    int data;
    LinkedList();
    LinkedList(LinkedList& copy);
   // ~LinkedList();
    
    void operator=(const LinkedList& otherLinkedList);
    void head_insert(Node*& head_ptr, int newData); // Was item&
    void insert(const Node& entry);      // Was item&
    void remove(Node* previous_ptr);
    void setHeadPtr(Node* newHead_ptr);
    void setTailPtr(Node* newHead_ptr);
    void setLength(int newLength);
    
    Node* getHeadPtr();
    Node* getTailPtr();
    int getLength();
    //int getNthData(int index);
    
private:
    
    Node* head_ptr;
    Node* tail_ptr;
    int length;
    
    
};

LinkedList::LinkedList(){

    head_ptr = NULL;
    tail_ptr = NULL;
    length = 0;
    
}





LinkedList::LinkedList(LinkedList& copy){

    int length = 0;
    
    for (Node* cursor = copy.getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
        this->setHeadPtr(cursor);
        this->setTailPtr(cursor->getLink());
        
        length ++;
        
        this->setLength(length);
        
    }

}

//LinkedList::    ~LinkedList(){
//    
//    delete this;
//    
//};



void LinkedList::setLength(int newLength){
    
    
    length = newLength;
    
};

Node* LinkedList::getHeadPtr(){
    
    
    return head_ptr;
}

Node* LinkedList::getTailPtr(){
    
    
    return tail_ptr;
}


int LinkedList::getLength(){
    
    
    return length;
}



void LinkedList::setHeadPtr(Node *newHead_ptr){
    
    
    head_ptr = newHead_ptr;
    
}


void LinkedList::setTailPtr(Node *newTail_ptr){
    
    
    tail_ptr = newTail_ptr;
    
}


void LinkedList::head_insert(Node *&newHead_ptr, int newData){
    
    Node* insert_ptr;
    
    insert_ptr = new Node;
    insert_ptr->setData(newData);
    insert_ptr->setLink(newHead_ptr);
    
    head_ptr = insert_ptr;
    
}


int getNthData(LinkedList *list,  int index){
    
//    Node cursor = *LinkedList::head_ptr;
    
    int count = 1; /* index of Node we are
                    currently looking at */
    
    for (Node* cursor = list->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
    
        if (count == index){
            return cursor->getData();
            break;
        }
        count++;
 
    }

    return -1;
}



LinkedList concatenateLinkedLists( LinkedList *list1, LinkedList *list2){
    
  
    
    for (Node* cursor = list2->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
      
        
        list1->getTailPtr()->setLink(cursor);
        
        list1->setTailPtr(cursor);
        
      
        
        int listLength = 0;

        listLength++;
        
        list1->setLength(list1->getLength() + listLength);
    
    }
    
    
    return *list1;
    
};



void concatenateLinkedLists_View(){
    
    
    
    string list1_str;
    cout << "Please input the list1:" ;
    getline(cin, list1_str);
    
    LinkedList *list1 = new LinkedList();
    
    
    int listLength1 = 0;
    int myNumber1 = 0;
    stringstream list1Stream(list1_str);

    
    while(list1Stream >> myNumber1) {
        
        
        Node* newHeaderNode = new Node();
        newHeaderNode->setData(myNumber1);
        
        
        //Insert from Tail
        
        if(list1->getLength() == 0){
            
            list1->setHeadPtr(newHeaderNode);
            
            list1->setTailPtr(newHeaderNode);
            
        }
        
        
        list1->getTailPtr()->setLink(newHeaderNode);
        list1->setTailPtr(newHeaderNode);
        
        
        listLength1++;
        list1->setLength(listLength1);
        
        
        
        //Insert from Head
        
        //            newHeaderNode->setLink(list1.getHeadPtr());
        //
        //
        //            list1.setHeadPtr(newHeaderNode);
        //            list1.setTailPtr(list1.getHeadPtr());
        
        
    }
    
    
    
    
    string list2_str;
    cout << "Please input the list2:" ;
    getline(cin, list2_str);
    
    LinkedList *list2 = new LinkedList();
    
    int listLength2 = 0;
    int myNumber2 = 0;
    stringstream list2Stream(list2_str);

    
    while(list2Stream >> myNumber2) {
        
        
        Node* newHeaderNode = new Node();
        newHeaderNode->setData(myNumber2);
        
  
        //Insert from Tail
        
        if(list2->getLength() == 0){
            
            list2->setHeadPtr(newHeaderNode);
            
            list2->setTailPtr(newHeaderNode);
            
        }
        
        
        list2->getTailPtr()->setLink(newHeaderNode);
        list2->setTailPtr(newHeaderNode);
        
        
        listLength2++;
        
        
        list2->setLength(listLength2);
        
        
        
        
        
        //Insert from Head
        
        //         newHeaderNode->setLink(list2.getHeadPtr());
        //
        //
        //         list2.setHeadPtr(newHeaderNode);
        //         list2.setTailPtr(list2.getHeadPtr());
        
        
        
    }
    
    
    
    cout << "List 1: " << endl;
    
    
    for (Node* cursor = list1->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
        cout << cursor->getData() << endl;
        
    }
    
    cout << "   " << endl;
    
    
    cout << "List 2: " << endl;
    
    for (Node* cursor = list2->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
        cout << cursor->getData() << endl;
        
    }
    
    
    cout << "   " << endl;
    
    cout << "Concatenation..." << endl;
    
    concatenateLinkedLists( list1, list2);
    
    
    
    
    cout << "New List 1: " << endl;
    
    
    
    for (Node* cursor = list1->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
        cout << cursor->getData() << endl;
        
    }
    
    
    delete list1;
    delete list2;

}

void insertIntoSortedLinkedList(LinkedList* list, int newData){
    
    Node* newNode = new Node();
    newNode->setData(newData);
    
    Node* lastCursorNode = nullptr;

    for (Node* cursor = list->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
        if(cursor->getData() > newData){
            
            newNode->setLink(cursor);
            lastCursorNode->setLink(newNode);
 
            break;
        }
        
        lastCursorNode = cursor;
        
        
    }
    
       cout << "The outcome is:" << endl;
    
        for (Node* cursor = list->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
    
            cout << cursor->getData() << endl;
    
        }
    
    

}



LinkedList *createLinkedList(){
    
    
    
    string list_str;
    cout << "Please input the list:" ;
    getline(cin, list_str);
    
    LinkedList *list = new LinkedList();
    
    
    int listLength = 0;
    int myNumber = 0;
    stringstream list1Stream(list_str);
    
    
    while(list1Stream >> myNumber) {
        
        
        Node* newHeaderNode = new Node();
        newHeaderNode->setData(myNumber);
        
        
        //Insert from Tail
        
        if(list->getLength() == 0){
            
            list->setHeadPtr(newHeaderNode);
            
            list->setTailPtr(newHeaderNode);
            
        }
        
        
        
        list->getTailPtr()->setLink(newHeaderNode);
        list->setTailPtr(newHeaderNode);
        
        
        listLength++;
        list->setLength(listLength);
        
        
        
        //Insert from Head
        
        //            newHeaderNode->setLink(list1.getHeadPtr());
        //
        //
        //            list1.setHeadPtr(newHeaderNode);
        //            list1.setTailPtr(list1.getHeadPtr());
        
        
    }
    
    
    cout << "List: " << endl;
    
    
    for (Node* cursor = list->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
        cout << cursor->getData() << endl;
        
    }
    
    cout << "   " << endl;
    
    return list;
}



int getMedian(LinkedList *list){
    
    
    
    
    int median = 0;
    
    if( list->getLength()%2 == 0){
        
        
        int medianUpperBoundIndex =  (list->getLength()/2)+1 ;
        int medianLowerBoundIndex =  (list->getLength()/2);
        
        
        
        int upperBoundData = getNthData(list,medianUpperBoundIndex);
        int lowerBoundData = getNthData(list,medianLowerBoundIndex);
        
        median = upperBoundData + lowerBoundData / 2;
        
    }
    else{
        
        int medianIndex = (list->getLength()+1)/2 ;
        
        
        median = getNthData(list, medianIndex);
    }

    
    return median;
    
    
}


void getMedian_View(){
    
    LinkedList *list = createLinkedList();
  
    
    cout << "The median is:" << getMedian(list) << endl;
    
}


void insertIntoSortedLinkedList_View(){


    string list_str;
    cout << "Please input the list:" ;
    getline(cin, list_str);
    
    LinkedList *list = new LinkedList();
    
    
    int listLength = 0;
    int myNumber = 0;
    stringstream list1Stream(list_str);
    
    
    while(list1Stream >> myNumber) {
        
        
        Node* newHeaderNode = new Node();
        newHeaderNode->setData(myNumber);
        
        
        //Insert from Tail
        
        if(list->getLength() == 0){
            
            list->setHeadPtr(newHeaderNode);
            
            list->setTailPtr(newHeaderNode);
            
        }
        
        
        
        list->getTailPtr()->setLink(newHeaderNode);
        list->setTailPtr(newHeaderNode);
        
        
        listLength++;
        list->setLength(listLength);
        
        
        
        //Insert from Head
        
        //            newHeaderNode->setLink(list1.getHeadPtr());
        //
        //
        //            list1.setHeadPtr(newHeaderNode);
        //            list1.setTailPtr(list1.getHeadPtr());
        
        
    }
    
    
    cout << "List: " << endl;
    
    
    for (Node* cursor = list->getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
        
        cout << cursor->getData() << endl;
        
    }
    
    cout << "   " << endl;
    

    
    
    string newData_str;
    cout << "Please input the value:" ;
    getline(cin, newData_str);
    

    int newData = 0;
    stringstream newDataStream(newData_str);
    while (newDataStream >> newData){
        
            cout << newData << endl;
        
    };
    
    

    
    
    
    insertIntoSortedLinkedList(list, newData);
    

//    cout << "The outcome is:" << endl;
//    
//
//    for (Node* cursor = list.getHeadPtr(); cursor !=NULL; cursor = cursor->getLink()){
//        
//        cout << cursor->getData() << endl;
//        
//    }
    
    

}



int main() {
    
    string option;
    
    cout << "Please tell me what to do: concatenate(C), insert(I), median(M), reverse(R), end(E)? " ;
    
    getline (cin, option);
    

        
    if(option == "C"){
    concatenateLinkedLists_View();
        
    main();
        
    }
    
    if(option == "I"){
        
    insertIntoSortedLinkedList_View();
        
    main();
        
    }
    if(option == "M"){
        
        getMedian_View();
        
        main();
        
    }
    if(option == "R"){
        
        insertIntoSortedLinkedList_View();
        
    }
    if(option == "E"){
        
        return 0;
        
    }
    else {
        
        cout << "Please enter a valid option. " <<endl;

       main();
        
    }


    
}


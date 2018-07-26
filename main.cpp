//  Louie Shi's Doubly Linked List Implementation
//
//  main.cpp
//  AddTwoNumbers
//
//  Created by Louie Shi on 7/24/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList* sumList(ListNode* ln1, ListNode* ln2)
{
    LinkedList* resultList = new LinkedList();
    int sum = 0;    //Holds the sum of 2 nodes
    int insertedVal = 0;
    int carry = 0; //Either 0 or 1
    
    while(ln1 || ln2)
    {
        if(ln1 && !ln2)
        {
            while(ln1)
            {
                insertedVal = ln1->getData() + carry;
                if(insertedVal > 9)
                {
                    insertedVal = insertedVal % 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                
                ListNode* inserted = new ListNode(insertedVal);
                resultList->insertEnd(inserted);
                ln1 = ln1->getNext();
            }
        }
        else if(!ln1 && ln2)
        {
            while(ln2)
            {
                insertedVal = ln2->getData() + carry;
                if(insertedVal > 9)
                {
                    insertedVal = insertedVal % 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                
                ListNode* inserted = new ListNode(insertedVal);
                resultList->insertEnd(inserted);
                ln2 = ln2->getNext();
            }
        }
        else
        {
            sum = ln1->getData() + ln2->getData() + carry;
            
            if(sum > 9)
            {
                insertedVal = (sum % 10);
                carry = 1;
            }
            else
            {
                insertedVal = sum;
                carry = 0;
            }
            
            ListNode* inserted = new ListNode(insertedVal);
            resultList->insertEnd(inserted);
            ln1 = ln1->getNext();
            ln2 = ln2->getNext();
            sum = 0;
        }
    }
    
    if((!ln1 && !ln2) && (carry == 1))
    {
        ListNode* inserted = new ListNode(1);
        resultList->insertEnd(inserted);
    }
    
    return resultList;
}

int main(int argc, const char * argv[])
{
//Case 1
    LinkedList* l1 = new LinkedList();
    LinkedList* l2 = new LinkedList();
    LinkedList* result = new LinkedList();    
    
    ListNode* ln1 = new ListNode(6);
    ListNode* ln2 = new ListNode(1);
    ListNode* ln3 = new ListNode(7);
    
    ListNode* ln4 = new ListNode(2);
    ListNode* ln5 = new ListNode(9);
    ListNode* ln6 = new ListNode(5);
    
    cout << "List1:" << endl;
    
    l1->insertEnd(ln1);
    l1->insertEnd(ln2);
    l1->insertEnd(ln3);
    
    l1->print();
    cout << endl;

    cout << "List2:" << endl;
    l2->insertEnd(ln4);
    l2->insertEnd(ln5);
    l2->insertEnd(ln6);
    
    l2->print();
    cout << endl;

    
    ListNode* l1head = l1->head;
    ListNode* l2head = l2->head;
    result = sumList(l1head, l2head);
    
    cout << "Result:" << endl;
    result->print();
    cout << endl;
    
    return 0;
}

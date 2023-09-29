#include <iostream>
#include <list>

struct ListNode{
    ListNode(int val): m_val{val}, next{nullptr} {}
    

    //We should define a copy constructor,
    //copy assignment operator and destructor

    /*copy ctor
    ListNode(const ListNode& rhs){
        ...                         //deep copying
    }
    */

   /*copy assignment opoerator
    const listNode& operator=(const ListNode& rhs){
        ...                                         //preventing self assignment
        ...                                         //deep copying
        ...                                         //returning reference to *this
    }
    */

   /*destructor
        ~ListNode(){
            ...                                     //deleting dynamically allocated memory
        }
   */


    int m_val;
    ListNode* next;
};

//returns pointer to the node where the cycle begins,
//if there is no cycle, returns nullptr

ListNode* cycle_detector(ListNode* head){
    ListNode* hare{head};
    ListNode* turtoise{head};

    
    while((hare != nullptr) && (hare -> next != nullptr)){
        hare = hare -> next -> next;
        turtoise = turtoise -> next;

        if(hare == turtoise){
            turtoise = head;
            while(hare != turtoise){
                hare = hare -> next;
                turtoise = turtoise -> next;
            }

            return turtoise;
        }
    }

    return nullptr;
}

int main(){
    //creating linked list with cycle
    ListNode* head = new ListNode(10);
    ListNode* tmp = head;
    for(int i = 0;i < 5;++i){
        tmp -> next = new ListNode(i);
        tmp = tmp -> next;
    }

    tmp -> next = head;

    ListNode* cycleStarter = cycle_detector(head);

    std::cout<<"Address of head "<<head<<std::endl;
    if(cycleStarter != nullptr){
        std::cout<<"\nThe cycle starts at node with the address "<<cycleStarter;
    }else{
        std::cout<<"\nThe list does not have a cycle!\n";
    }

    //destroying the cycle
    tmp -> next = nullptr;

    cycleStarter = cycle_detector(head);
    if(cycleStarter != nullptr){
        std::cout<<"\nThe cycle starts at node with the address "<<cycleStarter;
    }else{
        std::cout<<"\nThe list does not have a cycle!\n";
    }

    tmp = head;
    //deallocating the allocated memory
    while(tmp != nullptr){
        head = tmp -> next;
        delete tmp;
        tmp = head;
    }
}
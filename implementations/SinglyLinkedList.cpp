#include <bits/stdc++.h>
using namespace std;

template <class T>
class SinglyLinkedListNode{
    public:
        T value;
        SinglyLinkedListNode* next;    
        SinglyLinkedListNode(T x){
            value = x;
            next = NULL;
        }
};

template <class T>
class SinglyLinkedList{
    SinglyLinkedListNode<T>* head = NULL;
    public:
        void insertion(T val){
            SinglyLinkedListNode<T>* newNode = new SinglyLinkedListNode<T>(val);
            newNode->next = head;
            head = newNode;
            return ;
        }
        void deletion(T val){
            if(head == NULL)
                return ;
            if(head->value == val){
                head = head->next;
                return ;
            }
            bool isDeleted = false;
            SinglyLinkedListNode<T>* previous = head;
            SinglyLinkedListNode<T>* traversal = head->next;
            while(traversal != NULL){
                if(traversal -> value == val){
                    previous->next = traversal->next;
                    delete traversal;
                    isDeleted = true;
                    break;
                }
                traversal = traversal->next;
                previous = previous->next;
            }
            if(!isDeleted)
                cout << "Node not found!" << endl;
            return ;
        }

        bool find(T val){
            SinglyLinkedListNode<T>* traversal = head;
            while(traversal != NULL){
                if(traversal -> value == val){                    
                    return true;
                }
                traversal = traversal->next;
            }
            return false;
        }

        SinglyLinkedListNode<T>* getHead(){
            return head;
        }

        void display(){
            string arrow = "->";
            SinglyLinkedListNode<T>* traversal = head;
            while(traversal != NULL){
                cout << traversal->value;
                if(traversal->next != NULL)
                    cout << " " << arrow << " ";
                traversal = traversal->next;
            }
            cout << endl;
            return ;
        }
};


int main(){
    SinglyLinkedList<int> list;
    list.insertion(5);
    list.insertion(2);
    list.insertion(3);
    // 3->2->5
    list.display();
    list.deletion(2);
    // 3->5
    list.display();
    cout << list.find(2) << endl; // false
    cout << list.find(5) << endl; // true
    return 0;
}
#include <iostream>

using namespace std;

class List{
private:
    struct Node{
        int data;
        Node* next;
    };
    
    typedef struct Node* nodePtr;
    
    nodePtr head;
    nodePtr temp;
    nodePtr curr;
    
public:
    List();
    void addNode(int data);
    void display();
    void findMiddle();
    int countLinks();
};

List::List(){
    head = NULL;
    temp = NULL;
    curr = NULL;
}

void List::addNode(int data){
    nodePtr n = new Node;
    n->data = data;
    n->next = NULL;
    
    if(head != NULL){
        curr = head;
        while(curr->next !=NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
    else{
        head = n;
    }
}

void List::display(){
    if(head != NULL){
        curr = head;
        while(curr != NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    else{
        cout<<"List is EMPTY"<<endl;
    }
}

int List::countLinks(){
     int count =0;
    if(head != NULL){
        curr = head;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }
    else{
        return 0;
    }
}

void List::findMiddle(){
    int middle;
    if(countLinks()%2==0){
        middle = countLinks()/2;
        int init = 1;
        curr=head;
        while(init<=middle){
            curr=curr->next;
            init++;
        }
        cout<<"The middle element in the list is "<<curr->data<<endl;
    }
    else{
        middle = countLinks()/2+0.5;
        int init = 1;
        curr=head;
        while(init<=middle){
            curr=curr->next;
            init++;
        }
        cout<<"The middle element in the list is "<<curr->data<<endl;
    }
    
}

int main(){
    List L;
    L.addNode(0);
    L.addNode(1);
    L.addNode(2);
    L.addNode(3);
    L.addNode(4);
    L.addNode(5);
    L.addNode(6);
    L.addNode(7);
    L.addNode(8);
    L.addNode(9);
    L.addNode(10);
    
    
    L.display();
    
    cout<<L.countLinks()<<endl;
    
    L.findMiddle();
    
    return 0;
}





















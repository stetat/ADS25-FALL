#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
    public:
    int data;
    
    int index;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        this->index = -1;
        this->next = NULL;
        this->prev = NULL;
    }
};


class linked_list {
    public:
    int sz;
    Node *front;
    Node *back;

    linked_list() {
        sz = 0;
        front = back = NULL;
    }

    void insert(int x, int y) {
        Node *n = new Node(x);
        
        if (sz == 0) {

            front = back = n;
            sz++;
            return;
        }

        else if (y == 0) {
            front->prev = n;
            n->next = front;
            front = n;
           


            sz++;
            return;

        }

        else if(y == sz) {
            back->next = n;
            n->prev = back;
            back = n;
            
            sz++;
            return;
        }

        else {
            int pos = 0;
            Node *cur = front;
            while(pos != y) {
                cur = cur->next;
                pos++;
            }

            cur->prev->next = n;
            n->prev= cur->prev;
            n->next = cur;
            cur->prev = n;
            sz++;


        }

    }

    void reverse() {

        if(sz == 1) {
            return;
        }
       
        Node *cur = front;
        Node *temp = front;

        front = back;
        back = temp;

        while(cur) {
            Node *temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }

        if (front) front->prev = NULL;
        if (back) back->next = NULL;

    }


    void remove(int x) {
        if(x == 0) {
            front->next->prev = NULL;
            front = front->next;
            sz--;
        }

        else if (x == sz-1) {
            back->prev->next = NULL;
            back = back->prev;
            sz--;
        }

        else {
            int pos = 0;
            Node *cur = front;

            while(pos != x) {
                cur = cur->next;
                pos++;
            }

            
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            sz--;



        }

    }

    



    void cyclic_right(int x) {


        for(int i = 0; i<x; i++) {
            Node *temp = back;
            back->prev->next = NULL;
            back = back->prev;
            
            temp->next = front;
            front->prev = temp;
            front = temp;
        }


    }

    void cyclic_left(int x) {


        for(int i = 0; i<x; i++) {
            Node *temp = front;
            front->next->prev = NULL;
            front = front->next;
            
            temp->prev = back;
            back->next = temp;
            temp->next = NULL;
            back = temp;
        }


    }

    void pop_front() {
        Node *temp = front->prev;
        front = front->next;
        front->prev = temp;
        temp->next = front;
        sz--;

        Node *temp2 = front;

        


    }


    vector<string> print() {

        vector<string> result;
        Node *cur = front;
       
        while( cur ) {
            result.push_back(to_string(cur->data));
            cur = cur->next;
            
        }

        

        return result;

        
    }
    


    void replace(int x, int y) {
        int pos = 0;
        Node *cur = front;

        if( x == sz-1) {
            cur = back;
        } 

        else {

            while(pos != x) {
                cur = cur->next;
                pos++;
            }

        }   

        remove(x);
        insert(cur->data, y);
        

    }








};


int main() {

    linked_list numbers;
    vector<string> result;

    
    int act;

    while(true) {
        cin >> act;

        if(act == 0) {
            break;
        }

        if(act == 1) {
            int n,k;
            cin >> n >> k;
            numbers.insert(n, k);
        }

        if(act == 2) {
            int p;
            cin>>p;
            numbers.remove(p);
        }

        if(act == 3) {
            if(numbers.sz == 0) {
                cout << -1 << endl;
                continue;
                
                
            
            }

            vector<string> bunch = numbers.print();
            result.insert(result.end(), bunch.begin(), bunch.end());

            
            cout<<endl;

        }

        if(act == 4) {
            int n, k;
            cin >> n >> k;

            numbers.replace(n, k);

        }

        if(act == 5) {
            numbers.reverse();
        }

        if(act == 6) {
            int n;
            cin>>n;
            numbers.cyclic_left(n);

        }

        if(act == 7) {
            int n;
            cin >> n;
            numbers.cyclic_right(n);
        }

    }


    for(int i = 0; i<result.size(); i++) {
        if(result[i] == "S") {
            cout << endl;
            continue;
        }

        cout << result[i] << " ";
    }
   
   
   

   


    



    return 0;
}
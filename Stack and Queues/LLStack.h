template <typename T>

class Node {
public:
    T data;
    Node<T> *next;

    //Constructor
    Node(T data){
        this->data = data;
        next = NULL;
    }
};


template <typename T> 

class Stack {
    Node<T> *head;
    int size; //no of elements present in stack

public:
    //Constructor
    Stack(){
       head = NULL;
       size = 0; 
    }

    //Size Function
    int getSize(){
        return size;
    }

    //Is Empty Function
    bool isEmpty(){
        return size == 0;
    }

    //Push Function
    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    //Pop Function
    T pop() {
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return 0;
        } 
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete[] temp;
        size--;
        return ans;
    }

    //Top Function
    T top(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return head->data;
    }
};
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

class Stack{
    private:
    vector<int> items;

    public:
    void push(int item){
        items.push_back(item);
    }
    int pop(){
        if(!items.empty()){
            int item = items.back();
            items.pop_back();
            return -1;
        }
        bool isEmpty() {
            return items.empty();
        }
    };
    struct Node{
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr){}
    };

    class Queue{
        private:
        Node* front;
        Node* rear;

        public:
        Queue(){
            front = nullptr;
            rear = nullptr;
        }
        ~Queue(){
            while (front){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
}
        void enqueue(int item){
            Node* newNode = new Node(item);
            if(isEmpty()){
                front = rear = newNode;
            }else{
                rear->next = newNode;
                rear = newNode;
            }
        }
        int dequeue(){
            if(!isEmpty()){
                int item = front->data;
                Node*temp = front;
                front = front->next;
                delete temp;
                return item;
            }
            return -1;
        }
        bool isEmpty(){
            return front == nullptr;
        }
    };
    int main(){
        Stack positiveStack;
        Queue negativeQueue;

        cout << "请输入若干非0整数(用空格隔开，输入0结束）："；
            string input;
        getline(cin,input);

        istringstream stream(input);
        int num;

        while(stream >> num){
            if(num == 0){
                break;
            }
            if(num > 0){
                positiveStack.push(num);
            }else{
                negativeQueue.enqueue(num);
            }
        }
        cout <<"逆序输出所有保证的正整数:"<<endl;
        while(!positiveStack.isEmpty()){
            cout<<setw(5) << positiveStack.pop();
        }
        cout<<endl;

        cout << "同序输出所有保证的负整数:"<<endl;
        while(!negetiveQueue.isEmpty()){
            cout << setw(5)<<negativeQueue.dequeue();
        }
        cout << endl;

        return 0;
    }

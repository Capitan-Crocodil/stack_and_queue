#include <iostream>

using namespace std;

// Структура узла стека
struct Node {
    int data;
    Node* next;
};

class stack {
private:
    Node* top;  // Указатель на верхний элемент стека

public:
    // Конструктор
    stack() : top(nullptr) {}


    // Метод для проверки, пуст ли стек
    bool sempty() const {
        return top == nullptr;
    }

    // Метод для добавления элемента в стек
    void spush(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;

    }

    // Метод для извлечения элемента из стека
    int spop() {
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Метод для просмотра верхнего элемента стека 
    int speek() const {
        return top->data;
    }

    // Метод для вывода содержимого стека
    void sprint() const {
        if (sempty()) {
            cout << "Стек пуст.\n";
            return;
        }
        Node* current = top;
        cout << "Стек: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class queue {
private:
    Node* top; // Указатель на первый элемент
    Node* bot; // Указатель на последний элемнет 
public: // Конструктор
    queue() : top(nullptr), bot(nullptr) {}
    
    // Метод для проверки пуста ли очередь
    bool qempty() {
        return top == nullptr;
    }

    // Метод добавления элемента в очередь 
    void qpush(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (qempty()) {
            top = newNode;
            bot = newNode;
        }
        else {
            bot->next = newNode;
            bot = newNode;
        }
    }

    // Метод удаления элемента из стека
    int qpop() {
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        if (qempty()) {
            bot = nullptr;
        }
        return val;
    }

    // Метод для просмотра первого элемента очереди
    int qpeek() {
        if (qempty()) {
            ;
            return -1;
        }
        return top->data;
    }

    // Метод вывода элементов очереди
    void qprint() {
        if (qempty()) {
            cout << "Очередь пуста" << endl;
        }
        Node* res = top;
        while (res != nullptr) {
            cout << res->data << " ";
            res = res->next;
        }
        cout << "/n";
    }
};

int main() {
    stack s1;
    stack s2;
    queue q1;
    queue q2;

    int begin = -20, finish = 60;
    int j;

    for (j = begin; j <= finish; ++j) {
        s1.spush(j);
        q1.qpush(j);

    }
    for (j = begin; j <= finish; ++j) {
        if (s1.speek() % 7 != 0) {
            int n = s1.speek();
            s2.spush(n);

        }
        s1.spop();
        if (q1.qpeek() % 7 == 0) {
            int n = q1.qpeek();
            q2.qpush(n);
        }
        q1.qpop();

    }

    cout << "Стек s2:" << endl;
    while (!s2.sempty()) {
        cout << s2.speek() << ' ';
        s2.spop();
    }

    cout << endl << "Очередь q2:" << endl;
    while (!q2.qempty()) {
        cout << q2.qpeek() << ' ';
        q2.qpop();
    }
}

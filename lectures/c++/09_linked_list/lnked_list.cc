#include <iostream>
#include <memory>
#include <stdexcept>

enum class method{push_back, push_front};

template <class T>
class list{

    struct node{
        T val;
        std::unique_ptr<node> next;
        node(const T& v, node* n): val{v}, next{n} {}
        ~node() = default;
    };

std::unique_ptr<node> head;
void push_front(const T& t){
    // auto old = head.release();
    // auto tmp = new node{t,old};
    // head.reset(tmp);
    head.reset(new node{t, head.release()});
}

template <typename T>
void list<T>::push_back(const T& t){
    auto tmp = head.get();
    while(tmp->next != nullptr){
        tmp = tmp->next.get();
    }
    tmp->next.reset(new node{t, nullptr});
}

public:
    list() = default;
    void push(const T& t, method m){
        if (head == nullptr){
            //node * tmp = new node{t,nullptr};
            //head.reset(tmp);
            head.reset(new node{t,nullptr});
            return;
        }
        switch (m){
            case method::push_back:
            push_back(t);
            break;
            case method::push_front:
            push_front(t);
            break;
            throw std::runtime_error{"unknown method\n"};
        }
    }

};

int main()
{
    list<int> list;
    list.push(3, method::push_back);
    list.push(5, method::push_front);
    
    return 0;
}
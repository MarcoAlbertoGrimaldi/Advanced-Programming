#include <iostream>
#include <memory>

template <class T>
class Vector{

    std::unique_ptr<T[]> elem;
    std::size_t _size;
    std::size_t _free_slots = 0;

public:

    Vector(const std::size_t lenght):
        elem {new T[lenght]}, _size {lenght} {}

    T& operator[](const std::size_t i) noexcept {return elem[i];}
    const T& operator[](const std::size_t i) const noexcept {return elem[i];}

    auto size() const noexcept { return _size; }

    void push_b(const T& e);
    void push_b(const T&& e);

    template <class... Args>
    void emplace_b(Args&& ...args){
        push_b( T{std::forward<Args>(args)... } );
    }

};

template <class T>
void Vector<T>::push_b(const T& e) {

    if(_free_slots==0) {
        auto tmp = new T[_size*2];
        _free_slots = size();
    
    for(auto i=0llu; i<size(); ++i)
        tmp[i] = std::move( (*this)[i] );

    elem.reset(tmp);
    }

    (*this)[size()] = e;
    _size++;
    _free_slots--;
}

template <class T>
void Vector<T>::push_b(const T&& e) {

    if(_free_slots==0) {
        auto tmp = new T[_size*2];
        _free_slots = size();
    
    for(auto i=0llu; i<size(); ++i)
        tmp[i] = std::move( (*this)[i] );

    elem.reset(tmp);
    }

    (*this)[size()] = std::move(e);
    _size++;
    _free_slots--;
}

template <class T>
auto& operator <<(std::ostream &os, const Vector<T>& v) {
    for (auto i = 0llu; i<v.size(); ++i) {
        os << v[i] << " ";
    }
    os << std::endl;
    return os;
}

class Date{
    int d,m,y;
public:
    Date(const int day, const int month, const int year):
    d{day}, m{month}, y{year}{}
    Date()=default;
auto day() const noexcept {return d;}
auto month() const noexcept {return m;}
auto year() const noexcept {return y;}
};

int main(){
    Vector<int> v{4};
    {
        auto i = v.size();
        while(--i)
            v[i] = i;
    }

    v.push_b(5);
    
    std::cout << v;

    Vector<Date> vd{2};

    vd.push_b(Date{1,2,3});
    vd.emplace_b(1,2,33);

    std::cout << vd[3].year << std::endl;

return 0;
}
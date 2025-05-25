#include <iostream>
#include <vector>
#include <functional>
#include <list>
template<typename T, typename K>
T begin(K _tab){
    return _tab.begin();
 }
template<typename T, typename K>
 T end(K _tab){
    return _tab.end();
 }
void f1(  int  first){
    std::cout<<first<<" ";
};


void f2( int  first){
    if(first%2==0)
    std::cout<<first<<" ";
};

template<typename T, typename K>
void print_to_if(std::ostream &o, T first, T last , K fun)
{  
    while(first!=last){
        fun(*first);
        first++;
    }
    o<<std::endl;
}

struct f3{
    f3(int value):_value(value){}

    template<typename T>
    void operator()(T& ptr){
        ptr+=_value;
    }
    private:
    int _value;
};
template<typename T, typename K>
void change( T first, T last, K fun){
    while(first!=last){
        fun(*first);
        first++;
    }
}

int main(){
    const auto cl = {1,2,3,4,5,6,7};

    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f1);
    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f2);
    int add_value{-1};
    std::list<int> cl2 = {7,6,5,4,3,2,1};
    change(begin(cl2), end(cl2), f3{add_value});
    print_to_if(std::cout << "All  ", begin(cl2), end(cl2), f1);                                                                     
}
/*
All: 1 2 3 4 5 6 7 
All: 2 4 6 
All  6 5 4 3 2 1 0 
*/                                                                                      
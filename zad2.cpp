#include <iostream>
using  std::cout;
using  std::endl;

class A{
    public:
    A(int a,int b):_a(a),_b(b){
        cout<<__PRETTY_FUNCTION__;
        cout<<": _a="<<_a<<",_b="<<_b<<endl;
        
    
    }
    A():A(0,0){
        cout<<__PRETTY_FUNCTION__;
        cout<<": _a="<<_a<<",_b="<<_b<<endl;
    }
    explicit A(int a): A(a,0){
        cout<<__PRETTY_FUNCTION__;
        cout<<": _a="<<_a<<",_b="<<_b<<endl;
    }
    A(A&& obj){
        _a=std::move(obj._a);
        _b=std::move(obj._b);
        cout<<__PRETTY_FUNCTION__;
        cout<<": _a="<<_a<<",_b="<<_b<<endl;
    }
    A(const A& obj)=delete;

    //    explicit A(int a):_a(a),_b(0){
//         cout<<__PRETTY_FUNCTION__;
//         cout<<": _a="<<b

    private:
    int _a;
    int _b;
};

int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    // A e = c;
    // A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/
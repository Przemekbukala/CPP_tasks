#include <iostream>
#include <string>
class is_printable{
    public:
    virtual std::string get_value() const=0; 
};
class A:public is_printable{
    public:
    // friend std::ostream &operator<<(std::ostream &o,const A& obj);
    A(std::string text):_tekst(text){
    }
    std::string get_value() const{
        return _tekst;
    }

private:
    std::string _tekst;
};
class B: public is_printable{
    public:
    B(int value):_number(value){}
    std::string get_value() const{
        return std::to_string(_number);
    }
    private:
    int _number;
};
std::ostream &operator<<(std::ostream &o,const is_printable& obj){
    return o<<obj.get_value();
}
int main()
{
  A a ("Tekst"); B b {123};
  std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
  const is_printable & a_r = a; const is_printable & b_r = b;
   std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}

/*
a:      Tekst; b:       123
a_r:    Tekst; b_r:     123
*/
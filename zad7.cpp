#include <iostream>
class Obj{
  public:
  void virtual Draw() const=0 ;
};

template<typename T>
class Box : public Obj{
  public:
  friend std::ostream &operator<<(std::ostream &o,const Box <double>&obj);
  friend std::ostream &operator<<(std::ostream &o,const Box <int>&obj);
   Box(T a):_a(a){}
  void Draw() const{
    std::cout<<__PRETTY_FUNCTION__<<" --> "<<_a<<std::endl;
  }

  operator int(){
    return _a;
  }
  operator double(){
    return _a;
  }
  operator Box<int>(){
    return _a;
  }
  operator  Box<double>(){
    return _a;
  }
  private:
  T _a;
};
std::ostream &operator<<(std::ostream &o,const Box <int>&obj){
  return o<<obj._a;
}
std::ostream &operator<<(std::ostream &o,const Box <double>&obj){
  return o<<obj._a;
}
int main()
{
    Box<int> b_i {3};        
    Obj& r_1 = b_i; 
    r_1.Draw(); 
    int i = b_i;
    Box<double> b_d {3.4} ;
    Obj& r_2 = b_d;
    r_2.Draw(); 
    double d = b_d;
    Box<Box<int>> bb_i {3};
    const Obj& r_3 = bb_i;
    r_3.Draw(); 
    Box<int> br_i = bb_i;
    Box<Box<double>> bb_d {3.4} ; 
    const Obj& r_4 = bb_d;
    r_4.Draw();
    Box<double> b_a = bb_d;

    // Box<int> _ = 1;// Odkomentowanie powoduje błąd kompilacji

}
/*
void Box<T>::Draw() const [with T = int] --> 3
void Box<T>::Draw() const [with T = double] --> 3.4
void Box<Box<K> >::Draw() const [with T = int] --> 3
void Box<Box<K> >::Draw() const [with T = double] --> 3.4
*/
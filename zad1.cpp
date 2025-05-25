#include <iostream>
#include <string>

// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu
    class B{
        public:
        virtual std::ostream &printOn(std::ostream& o) const=0;
    };
    std::ostream &B::printOn(std::ostream& o) const{
          o<<__PRETTY_FUNCTION__<<std::endl;
         return o;
    }
    class D1: public B {
        public:
         virtual std::ostream &printOn(std::ostream& o) const{
         o<<__PRETTY_FUNCTION__<<std::endl;
         return o;
        }
       
     };

    
    std::ostream &operator<<(std::ostream &o,const B &obj )
    {
        return obj.printOn(o);
        
    }
    class D2: public D1{
        public:
        virtual std::ostream &printOn(std::ostream& o) const{
            this->D1::printOn(o);
            return o;
           }
    };
    class D3:public D1{
        public:
        virtual std::ostream &printOn(std::ostream& o) const{
         o<<__PRETTY_FUNCTION__<<std::endl;
         return o;
        }
        
     
    };
    class D4:public D3{
        public:
        virtual std::ostream &printOn(std::ostream& o) const{
        //  o<<__PRETTY_FUNCTION__<<std::endl;
    B::printOn(o);
    D1::printOn(o);
        // B *obj=&this;
      D3::printOn(o);
       o<<__PRETTY_FUNCTION__<<std::endl;

         return o;
        }
        
        
    };



    
int main(int argc, char *argv[]) {
//   B b; odkomentowanie powoduje błąd kompilacji
  D1 d1;
 D2 d2;
 D3 d3; 
const D4 d4;
  std::cout << "d1: " << d1 << "d2: " << d2<< "d3: " << d3<< "d4: " << d4;
}

/* Output:
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/
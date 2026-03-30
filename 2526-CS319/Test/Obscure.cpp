// Some obscure C++ code that Niall "borrowed" from Gabriel Fleseriu on
// CodeGuru.
// It is just a way of testing if you can compile and run a C++ program.

#include <iostream>
#include <string>

class base
{
public:
    base(char c = 0x48):c_(c){b_ = new base(*this);}
    base(const base& rhs)
    {
        int d[] = {-29, -7, 0, -3, 79, -87, 8, -3, 6, 8, 67, 23};
        c_ = rhs.c_ - d[i++];        
        b_ = (i-12)?new base(*this):0;
    }
    ~base()
    {
        using namespace std;
        cout<<c_;
        delete b_;
    }
private:
    char c_;
    base *b_;
    static int i;
};

int base::i = 0;

int main()  
{
    base b;
    return 0;
}

#include <iostream>
#include <string>

struct execute {
    
};

template<class _D,int _S>
struct pipeline 
{
    _D _data[_S>>4<<4];
    size_t _index;
    
    pipeline() {
        _index=0;
    }
    
    virtual pipeline& operator<<(pipeline& p) {
        return *this;
    }
    
    virtual pipeline& operator<<(execute& e) {
        return *this;
    }
    
    virtual pipeline& operator<<(_D& d) {
        _data[_index]=d;
        return *this;
    }
   
    
};

int main()
{
  pipeline<double,16> p;
  ;
}

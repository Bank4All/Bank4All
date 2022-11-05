#include <iostream>
#include <string>

struct execute {
    
};

struct pipeline
{
    size_t _index;
    size_t _cursor;
    vector<pipeline> _child;
    
    operator()() {
        while(_cursor<_index)
    }
    
};

template<class _D,int _S>
struct pipeline_t 
{
    _D _data[_S>>4<<4];
    
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
   
    virtual pipeline& operator--() {
        return *this;
    }
    virtual pipeline& operator|(pipeline& p) {
        return *this;
    }
    virtual pipeline& operator-(pipeline& p) {
        return *this;
    }
    virtual pipeline& operator+(pipeline& p) {
        return *this;
    }
    virtual pipeline& operator<(pipeline& p) {
        return *this;
    }
    virtual pipeline& operator>(pipeline& p) {
        return *this;
    }
    
};

int main()
{
  pipeline<double,16> p;
  
  
}

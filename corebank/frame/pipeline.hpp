#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct executor {
    virtual executor& operator()()=0;
    virtual void onBefore() {}
    virtual void onAfter() {}
     
};

template <class _T>
struct data : _T {
    int _level;
    
};

template<class _D,int _S>
struct pipeline : executor
{
    int _index;
    _D _data[_S>>4<<4];
    vector<executor*> _child;
    
    pipeline() {
        _index=0;
    }
    
    ~pipeline() {}
    
    virtual executor& operator<<(executor& p) {
        return *this;
    }
    
    virtual executor& operator<<(_D& d) {
        _data[_index]=d;
        return *this;
    }
   
    virtual executor& operator--() {
        return *this;
    }
    virtual executor& operator()() {
        return *this;
    }    
};

int main()
{
  pipeline<double,16> p,q,s,t;
  
  
}

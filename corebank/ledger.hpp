/******************************************************************************
2^64 integer where 2^33 is guaranteed to be a bijective relation of all humans, firms and groups

2^64 YYYY encoded on 2^16 * MMDD encoded in 2^9 * 2^31 number of operations per day

2^64 for any amount

2^8 for currency code

2^16 type of compliance and version

2^48 origin of operations ( economical code , country , sector, ... )
*******************************************************************************/

#include <iostream>
#include <vector>
#include<deque>
#include <ctime>
#include <algorithm>

using namespace std;

struct digital_operation {
    int_fast64_t    ownershipid;
    int_fast64_t    ledgertokenseqid;
    
};

class central_ledger_token_sequence {
    static  int_fast64_t    sequence ;
    deque<int_fast64_t>       token4access;

    public:    
    int_fast64_t   getTokenAccess() {
        int_fast64_t ret;
        std::srand(std::time(nullptr));
        deque<int_fast64_t>::iterator it = token4access.begin();
        while( it != token4access.end()) {
            ret = std::rand();
            it = find(token4access.begin(), token4access.end(), ret);
        }
        token4access.push_back(ret);
        return ret;
    }
    
    int_fast64_t    getSequenceId(int_fast64_t foreign_token) {
        deque<int_fast64_t>::iterator it = find(token4access.begin(), token4access.end(), foreign_token);
        if(it!=token4access.end()) {
            it = token4access.erase(it); 
            return sequence = sequence + 1;
        }
        return 0;
    }
};
int_fast64_t central_ledger_token_sequence::sequence=1;

int unit_test()
{
    central_ledger_token_sequence clts;
    
    auto req = clts.getTokenAccess();
    
    cout<< "first" << endl;
    cout<< clts.getSequenceId(req)<< endl;
    cout<< "next"<< endl;
    cout<< clts.getSequenceId(req)<< endl;

    return 0;
}

int main() {
  unit_test();
}

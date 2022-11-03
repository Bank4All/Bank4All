
# Core Banking Exchange

##  Exchange Header Only

[![](https://mermaid.ink/img/pako:eNpNkM-KAjEMxl8l5KSs8wJzEOYPC3sQllVPUw-lE7XrTuq26UEc332jI7INhNJ8v-8jvaILPWGJh2jPR9i0hkFP1VUc-DKEnHZQFMvxi34zJYEmMJMTH3iEerYJJ2I4EFO0EuJ8gus7Ac2s9t-TtISXGxQP5qlsHt4rG08ksGWvGfDRE4vfe-2wTRRHaLtPij4JsaO3FUn0Lu3-G6wpJY15oZZlhPfu6Vs5p3MFpgLABQ4UB-t73ft6fzEoRxrIYKnXXjGDhm-qs1nC-sIOS4mZFpjPvRVqvdXvGrDc259Etz_c-G2j?type=png)](https://mermaid.live/edit#pako:eNpNkM-KAjEMxl8l5KSs8wJzEOYPC3sQllVPUw-lE7XrTuq26UEc332jI7INhNJ8v-8jvaILPWGJh2jPR9i0hkFP1VUc-DKEnHZQFMvxi34zJYEmMJMTH3iEerYJJ2I4EFO0EuJ8gus7Ac2s9t-TtISXGxQP5qlsHt4rG08ksGWvGfDRE4vfe-2wTRRHaLtPij4JsaO3FUn0Lu3-G6wpJY15oZZlhPfu6Vs5p3MFpgLABQ4UB-t73ft6fzEoRxrIYKnXXjGDhm-qs1nC-sIOS4mZFpjPvRVqvdXvGrDc259Etz_c-G2j)

### Market Connection 

We are going to create a small common interface for any market that hold configuration parameters.

```
struct marketConfig {
```

  this market kernel will at least hold a configuration of a maximum of connections;
  
```  
usigned int MAX_connection ;
```

  so whenever we a building a market we will size our maximum connection

``` 
    marketConfig(int defaultMaxconnection = 65536) : MAX_connection(defaultMaxconnection) {
        initErrorDisplay();
    }
``` 

  we will also centralise our error message per language/local
```  
    enum enERROR {
        ERROR_MSG=1
    };
    map<enERROR,string> local_msg;

    void initErrorDisplay() {
        local_msg[ERROR_MSG]="Error Message";
    }
```   

};

As we are planning to create low latency system, we will try to use as much direct access possible

now we need to create a market extension that allow user to connect/ disconnect 

``` 
struct MarketDealerConnector : MarketConfig {
 
    map<string,long long> _con_dealers;
    vector<Dealer>  _dealers;

    MarketDealerConnector() {
        _dealers.reserve(256);
        _dealers.resize(1);
        _dealers[0].dealerId = 0;
    }
```

   now we are going to implement a token mechanism

```
    double _muliplex[2];
    
    MarketDealerConnector() {
        srand(time(0));
        
        do { _muliplex[0] = rand();
        } while ( _muliplex[0] > MAX_connection*256);
        do { _muliplex[1] = rand() ;
        } while ( _muliplex[1] < MAX_connection*256);     
    }
```
  and now we can request a token from our login name

```
    pair<bool, Dealer> login(const string& login_name) {
        auto id = _con_dealers.find(login_name);
        unsigned long long re = 0;
        int npos ;
        if ( id == _con_dealers.end()) {
            npos = (long long)_dealers.size();
            re = npos * _muliplex[0] + _muliplex[1];
            _con_dealers[login_name] = re;
            _dealers.resize(npos+1);
            _dealers[npos].dealerId = re;
            
            return pair<bool, Dealer>(true,_dealers[npos]);
        } else {
            return pair<bool, Dealer>(false,_dealers[0]);
        }
    }
```

  get object from a connected dealer
  
```
    Dealer& getDealer(const unsigned long long& toksee) {
        long c = (toksee - _muliplex[1]) / _muliplex[0];
        if( _dealers[c].dealerId == toksee ) return _dealers[c];
        else {
            return _dealers[0]
        }
    }
};
``` 

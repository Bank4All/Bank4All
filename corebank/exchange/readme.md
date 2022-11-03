
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


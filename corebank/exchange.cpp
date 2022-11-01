// ---------------------------------------------------------------------------------
// {S} ~  ..  _
// {S} ScaIIneT company
// (C) Copyright 2022
// [L] License : Free of for french domain only
// #M# Military limitation : Forbidden for missile and drone information processing
// ---------------------------------------------------------------------------------

#include <iostream>
#include<ctime>
#include <vector>
#include<cstdlib>
#include <string>
#include <map>

using namespace std;

struct Order 
{
    double outstanding;
    double limit;
};

struct Dealer 
{
    long dealerId;
    double balance;

    vector<pair<long,double> > _orders;
    
};

struct Asset 
{
    long assetId;
    string name;

    vector<pair<Dealer,double> > _quantity;
   
};


struct MarketConfig {
    const int MAX_connection = 65536;
    enum enERROR {
        ERROR_MSG=1
    };
    double _muliplex[2];
    
    MarketConfig() {
        srand(time(0));
        
        do { _muliplex[0] = rand();
        } while ( _muliplex[0] > 65536*256);
        do { _muliplex[1] = rand() ;
        } while ( _muliplex[1] < 65536*256);
        
        local_msg[ERROR_MSG]="Error Message";
    }
    
    map<enERROR,string> local_msg;
};

struct MarketDealerConnector : MarketConfig {
 
    MarketDealerConnector() {
        _dealers.reserve(256);
        _dealers.resize(1);
        _dealers[0].dealerId = 0;
    }
    map<string,long long> _con_dealers;
    vector<Dealer>  _dealers;
    
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
    
    long invert_token(const unsigned long long& toksee ) {
        long c = (toksee - _muliplex[1]) / _muliplex[0];
        if( _dealers[c].dealerId == toksee ) return c;
        else {
            // ban connection user
        }
        return 0;
    }
    
    
};

struct MarketAssetStorage : MarketDealerConnector {
    vector<Asset>  _assets;
    map<string,long> _market_assets;
    
    MarketAssetStorage() {
        _assets.reserve(1024);
        _market_assets[local_msg[ERROR_MSG]]=0;
        _assets.resize(1);
    }
    long getSymbolCode(const string& symbol) {
        auto id = _market_assets.find(symbol);
        
        return ( id == _market_assets.end()) ? _assets[ERROR_MSG].assetId  : id->second;     
    }
    
    const Asset& getAsset(const string& symbol)
    {
        auto id = _market_assets.find(symbol);
        if ( id == _market_assets.end()) { return _assets[ERROR_MSG];  }
        else {
            return _assets[MAX_connection - id->second];
        }
    }
    
    void addQuantity(const Dealer& fromWho,const string& symbol, double quantity) {
        auto id = _market_assets.find(symbol);
        if ( id != _market_assets.end()) {
            _assets[MAX_connection - id->second]._quantity.push_back(pair<Dealer,double>(fromWho,quantity));
        }
    
    }
    
};

Asset& createAsset(MarketAssetStorage& mks, const string& symbol)
{
    int npos ;
    auto id = mks._market_assets.find(symbol);
    if ( id == mks._market_assets.end()) {
        npos = mks._assets.size();
        mks._assets.resize(npos+1);
        mks._market_assets[symbol]=mks.MAX_connection - npos;
        mks._assets[npos].name = symbol;
        mks._assets[npos].assetId = mks.MAX_connection - npos;

      return mks._assets[npos];
    }else 
        return mks._assets[mks.MAX_connection - id->second];
}

int main()
{
    MarketAssetStorage mkt;
    
    auto con0 = mkt.login("daniel");
    auto con = mkt.login("danielle");
    
    cout<<"Hello " << con.second.dealerId << endl;
    
    // error , protection, yet managed
    cout << "symbolcode:" << mkt.getSymbolCode("ACCP.PA") << endl;
    mkt.addQuantity(con.second, "ACCP.PA", 23.6);
    mkt.addQuantity(con0.second, "ACCP.PA", 22.6);
    auto as = mkt.getAsset("ACCP.PA");
    for( int v =0; v<as._quantity.size(); v++)
        cout << as._quantity[v].second << "+";
    
    // active , protection, yet managed
    createAsset(mkt,"ACCP.PA");
    createAsset(mkt,"BNPP.PA");
    cout << "symbolcode:" << mkt.getSymbolCode("ACCP.PA") << endl;
    mkt.addQuantity(con.second, "ACCP.PA", 23.6);
    mkt.addQuantity(con0.second, "ACCP.PA", 22.6);

    as = mkt.getAsset("ACCP.PA");
    for( int v =0; v<as._quantity.size(); v++)
        cout << as._quantity[v].second << "+";
    
    return 0;
}

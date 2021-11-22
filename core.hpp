#include <taskflow.hpp>
#define ASIO_STANDALONE
#include <httplib.h>  // https://bestofcpp.com/repo/yhirose-cpp-httplib-cpp-network
#include <iostream>
#include <regex>

using namespace std;

struct country {
  
}

int main(void)
{
  // static ISO URL ( could be from web persisted page )
  httplib::Client cli("https://www.iso.org", 80);

  if (auto res = cli.Get("/obp/ui/#iso:pub:PUB500001:en")) {
    if (res->status == 200) {
      string content = res->body ;
      
      // looking for <td class="grs-status1" title="France"><a href="#iso:code:3166:FR" target="_blank">FR</a></td>
      // form regex to parse iso_code
      // form dynamic regex 
      string dyregisocountry = "\s+([\S]+\W+)France(\W\S+\s+\S+)3166:FR\W";
      smatch parse_elements;
      regex_match (content
                   ,parse_elements
                   ,dyregisocountry);
      
      if(parse_elements.size() > 2 ) // we are ready to parse
      {
        // create the up to date regex code extractor
        string isocountry_extract = "\s+"+dyregisocountry[1]+"([\s\w]+)"+dyregisocountry[2]+"\d+\S(\w+)";
        smatch country_datas;
        
        // print data extracted for role = data compliance controller
        for (unsigned i=0; i<country_datas.size(); ++i) {
          cout << "[" << country_datas[i] << "] ";
          // FORCED console action 
          
        }
        cout << "[ TASK OF RECEIVED DATA COMPLETED, PLEASE PROCEED TO CHECK AND VALID ]";
        
        // SWITCH OFF NETWORK 
        // Add console level of confirmation
        // SWITCH ON NETWORK 
        
        
        
      }
    }
  } else {
    auto err = res.error();
    
  }
}

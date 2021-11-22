#include <taskflow.hpp>
#define ASIO_STANDALONE
#include <httplib.h>  // https://bestofcpp.com/repo/yhirose-cpp-httplib-cpp-network
#include <iostream>
#include <regex>
#include <cstdint>

using namespace std;

// we do not create a memory binded/aligned tuple structure for country and counterparty

// 1. Decentralized methods will create mostly a non aligned view of what a country is
//   Example of different level of country misleading : France, Adeleide, Martinique
//       IsoCountry France = FR, IsoCountry Terre Adélie = blank , IsoCountry Martinique = MQ
//       Transaction BNP Martinique Iso Country = FR
//       Transaction SG Martinique Iso Country = MQ
//       Transaction Martinique Collectivity Territorial IsoCountryCode = MQ
//       Transaction Martinique IEDOM IsoCountryCode = FR
//       Transaction Terre Adelie IsoCountryCode = TAFF
//       Transaction Mission Orga Terre Adelie IsoCountryCode = FR
// 2. To avoid externalisation of rules from country, we choose to enrich counterparty by anonymous property
//       consensus for property name will be done outside of coding, hence generic way of represent a country will
//       be leaded by an external dictionnary 
// 3. Clustering 
//  3.1 Country are data typed [Write by History], as such we propose to shuffle by alphqbetic order id into the vector host
//  3.2 Trade off between intrinsec performance ( direct access property ) versus ( carried indexation ), we accept to loose speed
//    3.2.1 Experience show that country code and impact on rules are run few times, they can be cached strongly and fully decentralised
//    3.2.2 Limit by country are Barrier type ( MIN , MAX , exception Listed )
//    3.2.3 Limit by orga , association and else are as far as today cumulated value , we don't suffer problem of integration accross of tree within a context of decentralisation
// 4. Acceptance of proposal model
//   4.1 Iso Country 2 CHAR and 3 CHAR are consistent and used by everyone
//   4.2 For finance and insurance, FIX use Iso Code 2 CHAR 
//   4.3 To create a fast order operator we propose [\t2] and [\t3] for ISO CODE -2 and ISO CODE -3 property name, and no acceptance of any property name starting with \t but those 2
//      It will insure ISO CODE are always first property in the data list of property
//      country crv; crv.data[0] = ISOCODE-2 and crv.data[1] = ISOCODE-3
// 5. In case of serious performance issue ( mostly to run a full FCB-LB and a Stress TEST )
//   5.1 changing vector<string> into char[max length known+1][nb counterparties know]; is still possible
//   5.2 optimization by tupling ( render country fully serialisable is same as creating a type of string wrapping an array of char)
//      We then refrain to use as much as possible STL algorithm convenient operator of std::string whenever it is possible in header
// 6. To avoid unecssary extra work later, we include the remarks that a fully serialised country data should fit into FIX message
//   6.1 After debat we still reject to use FAST protocole for country and counterparty data bulk mode for several reason, versatility and programmed obsolete features
//   6.2 Most FIX actor use PRAGMA POP and PRAGMA PUSH to align data, as we push toward a shuffled by alphatic order structure, we also imply non fixed size
//   6.3 Arabic alphabet revese order, Kanji and Cyrilic could lead to catastrophic effect for pure aligned serialized message, hence we conclude that google proto will be used
//     among participant to exchange data with their own cluster
//  7. BSON format and its father JSON should be accepted as an entry , mostly vanilla JSON 
//   7.1 Example : https://github.com/samayo/country-json/blob/master/src/country-by-abbreviation.json
//   7.2 BSON or JSON validated at least by /[^,:{}\[\]0-9.\-+Eaeflnr-u \n\r\t]  ** RFC4627, section 6 should be of minimal code


#ifndef COUNTRY_SERIALISED_4FAST_USAGE
typedef vector<string> country_property;
#endif

struct country {
  country_property data;
  static map<string, uint_fast16_t> property_name;
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

// --- Core Banking Structure for High Frequency Data Manipulation ---
// Author : Daniel BOUTRIN
// Date : 01 DEC 2021
// Version : 1.0

// 1. Business Case / Test pattern / Unit Test
// Market Data Auction Timeseries structure

// For High Frequency Trading , pattern to be used
// Market Server - Authentification - Agreement - Transfert - Save SEQ - Ack SEQ - Discard false missing - Completed Data

// SLA : Fast Relaunch = Memory organised by Business Bloc Dump and Reload
//   Example : Auction market = N x Block [ Asset Symbol , Order Book ID, Last Settled Value, Last Settled Quantity ]
//     Upon reception Symbol will generate a hash computation to find Order Book handler
//     To avoid a tremendous waste of time, we add the Vector Position into the block [ Asset Market Position ID ]
//     a Fixed allocation allow both agent to reduce their footprint on network and on cpu farm
//     at any given time we can now dump the memory to have 100% uptime + delta sequence 
// SLA : No Lost ACK
//    Our network client / server / peer need to follow ACID transaction regardless of NMI , NMN events
//    Persistent on SSD with battery backup can speed up the DUMP and prevent NMI
//    Using a chorum of server with Null Cable modem can prevent NMN
//    as such best pratice is to use a Chorum that run all 3 services ( RAM Persistency , Dump Pooler, ACK/NACK receiver )
//    Warning !!! A Naive approach is to delegate everything to a persisted queue ( that will only lead you to a catastrophy later )
//      Apache KAFKA without having setting up a Chorum is a very example of what you shouldn't do
//      MSMQ with a SSD another bad example
//      Tibco Rendez-Vous without a RAM server another one
//        No third party will take responsabilities to insure an ACID technical transaction
//        You can test it with Oracle Server how far it goes to realized a full ACK/NACK from network to safe queing
//        Most of the time, queue rely on Database mechanism for persistancy, so save yourself time and effort 
//        Do not hesitate to directly access your harddrive or use sqlite or any database with local ACID transaction
//
// SLA : Non Planned access
//    One of the harddest part of low latency is to remove parrallel process doing a RAI out of nowhere
//    Example : Plannified batch with the Zero Level Access Account, clear the cache of Harddrive
//    Example worst : Emergency and forced KB from Microsoft that will halt all processes if not reboot the server

// In general , SLA means trust no third party nor technologist who claim a lot but delivery poorly
//   Sign your own statement as you face a prosecuror to defend yourself
//   As such ADA is far more superior when explaining in Court Case of failure in Code , Automate or Business impact
//   Automate for Trading send you to court, so be smart and serious

#include <boost/endian/buffers.hpp>  


namespace highfrequency
{

template<char[4]>
struct char_symbol{
}
  
}




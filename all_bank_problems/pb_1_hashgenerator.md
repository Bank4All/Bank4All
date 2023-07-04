# List of problems for Banking Industry
## Horizon + Vertical Key management
### How to store large data set with volatile or persisted existence
#### Referential Cross Problem

> ## Referential Central Key
>
> Decentralized or not, all bank services will need at one point to receive notification
> of key modification
>> ### SELECT last version
>>> - Scheduled Batches
>>> - Scheduled Reports
>> ### ON INSERT BEFORE
>>> - Desactivate Caches
>>> - Alert impact Tracer
>> ### ON INSERT AFTER
>>> - Recompute real time system
>>> - Recompute Keys dependancies

> ## Data Quality manangement
>
> Data has multipurpose and as countrary as Google, need to be handle strictly,
> requiring different strategy of rendering
>> ## Input Data strategy & Technics
>>> - Auto FEED : Official and Legal published data are usually scheduled
>>> - Auto DEDUCT : Surrounded Report hold a huge amount of published data
>>> - High Probability around static data accross different sources
>>> - Internally supervised static data : Human factorisation
>>> - Externally supervised static data : Reverse Human factorisation
>>> - Surrounding real time data : Reverse auto feed
>>> - Real time data reoffseted : Auto feed
>>> - Static data completion Feed Logger
>>> - Real time data feed
>>> - Auto correctness
>>> - Auto qualification
>> ## Horizontal Key technics
>>> - Generate a general purpose HASH
>>> - generate on the fly LZH key over a incremental but distriubed dictionnary
>>> - reGenerate all key for ZIPHASH
>> ## Vertical Key Technics
>>> - add versioning windows and cross reference BEFORE and AFTER ( Linked List )
>>> - store vertical vector by timestamp
 
> ## Organisation  of a anonymous Market 
>> - Authorized Actor by Vernam cryptography and synchronisation technics
>> - Authorized by Speed capacity
>> - Authorized by Storage capacity
>> - Market Asset Descriptor
>> - Order Book Management and Limit
>> - Compliance strategy
>> - KYC / TRACFIN / NETTING / WALL 
>> - FEES computation
>> - Settlement
>> - Loan Asset Pool
>> - Cash Pool
>> - Dark Pool
>> - Outside market Futures



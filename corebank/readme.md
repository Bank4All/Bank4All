## About Core Banking Content

###  Core Bank Element

[![](https://mermaid.ink/img/pako:eNp1k02zmjAUhv_KGVbtzPV276IzClqZ-lXRuwkucuGAaSFxQuLUiv-9hwiKt1M2hOR9n_ORw8VLVIre0Ms1Px5gG8QS6BmxMEVphDmDT2_NC_EH9R4Gg6_1VtvKwAZzUdGBEUrWMP50188xzVF_vnHGjQP8y1j8xMSIE8JGFXi9HfoON7MlJ0LAMj7M-MBWqGGVZSKh91hoc9j31QtFudQw6dSSmLpq4q50zqWoXEIwn4RPtgBPBARYa3USlUt52iIyURgK1Soi1IIXsLTlO9XbR5C1qQGmVqaY1rBp_WeUcFuh1QpeX4lRZDDm8hemLSFwBF8jN_glEjmFn7FIJU2oXRi0qplTrbTIBQlCNkoSZaVpTyc3RkHNp3SpwBq-M9cOgDuiv-P0I5sK06Q7_4D7R7lB6vypkS7Ylv_GCp4NU9Y1sXPcmykb15JNhS6hS_Ce0pK9CW1NPxRtGNtc44qYicaSRofOn-Mtn6U_WCj_J52D037TXJoa1sxXRcHfqTyjdK-_azeM4e1j4yzuqtppqyFikT1SE0SlegVED-WCS55j2oWvYcvIXB2Ufmzu-3y_2dHnR4id6-0DvrtlrmiKJZcJ1vDGOtNCSWE-oGPpvXgl6pKLlP7aS0OJPXOgxsTekJYpZtwWJvZieSUpt0ZFZ5l4Q6Mtvnj2mNIMBoLT_156NLVFhde_aJ1TtA?type=png)](https://mermaid.live/edit#pako:eNp1k02zmjAUhv_KGVbtzPV276IzClqZ-lXRuwkucuGAaSFxQuLUiv-9hwiKt1M2hOR9n_ORw8VLVIre0Ms1Px5gG8QS6BmxMEVphDmDT2_NC_EH9R4Gg6_1VtvKwAZzUdGBEUrWMP50188xzVF_vnHGjQP8y1j8xMSIE8JGFXi9HfoON7MlJ0LAMj7M-MBWqGGVZSKh91hoc9j31QtFudQw6dSSmLpq4q50zqWoXEIwn4RPtgBPBARYa3USlUt52iIyURgK1Soi1IIXsLTlO9XbR5C1qQGmVqaY1rBp_WeUcFuh1QpeX4lRZDDm8hemLSFwBF8jN_glEjmFn7FIJU2oXRi0qplTrbTIBQlCNkoSZaVpTyc3RkHNp3SpwBq-M9cOgDuiv-P0I5sK06Q7_4D7R7lB6vypkS7Ylv_GCp4NU9Y1sXPcmykb15JNhS6hS_Ce0pK9CW1NPxRtGNtc44qYicaSRofOn-Mtn6U_WCj_J52D037TXJoa1sxXRcHfqTyjdK-_azeM4e1j4yzuqtppqyFikT1SE0SlegVED-WCS55j2oWvYcvIXB2Ufmzu-3y_2dHnR4id6-0DvrtlrmiKJZcJ1vDGOtNCSWE-oGPpvXgl6pKLlP7aS0OJPXOgxsTekJYpZtwWJvZieSUpt0ZFZ5l4Q6Mtvnj2mNIMBoLT_156NLVFhde_aJ1TtA)

### Built With

* [Lua](https://fr.wikipedia.org/wiki/Lua)
* [C++](https://en.wikipedia.org/wiki/C%2B%2B17)

#### Design by relation

Identity of any kind need to be hosted and securised, a flawless design will be to create a self hosted central repository with write only. 

Write only ledger give advantage on secure transfered data from a trust storage. 
It doesn't give a 100% security against the fraudster of identity

Let's analyse our banking problem without any assumption first.

An identity is brought to bank account manager, we create a ledger account and give access to it to our client.
Client is allowed to  substrat,deposit,create loan/borrow structuration, etc
Account manager is  allowed  to open/create/suspend/resume/refund
Law enforced manager is allowed to audit/analyse/reject/authorised/freeze/unfreeze/apply judgement fees

We can use a forced-directed graph to display our problem

https://bl.ocks.org/mbostock/raw/1062288/?raw=true

Another approach will be to attack by frequency  on each link between nodes 

without surprise our graph can be oriented althought our first design reveal a lot of flaws

[![](https://mermaid.ink/img/pako:eNpdUk1vwjAM_StWTpsE4t7DJGj5kpiQCtsOLYeodduMNumSdBMj_PeZNrBpuSTye89-tnNmmcqRBazUvK1gH6US6EyTdY7SCnuCkG7Na_GN-gDj8ZPb685YiLEUhgArlHQwe7jzN5iXqB-HPDOv4NIUqO0kxo8OjXUQnmfiHTMrPhFiVePlLz-sMDtOXlGL4uRgMUBhDy20asBeHWAOO6s0L9FBlBQ8KPi4M6jhTQuLoGSGh0EZDUk18mv8S6I2lWgdzJNplqlOWnhZR547HwyrI0ogFI2BEknBqZSDTTJ0B17oRYt7omcuyZAflNcvqXvqeO65PRQjLwpq38Ey2V4d_cu4vNn49eFgdaveKzxz1TO3LQ6rMG7Tx9mINagbLnLa7fkaSpmtsMGUBfTMseBdbVOWygtReWfV7iQzFtBoccS6NqdZRYLTr2gYTbY2ePkBRyy5vg?type=png)](https://mermaid.live/edit#pako:eNpdUk1vwjAM_StWTpsE4t7DJGj5kpiQCtsOLYeodduMNumSdBMj_PeZNrBpuSTye89-tnNmmcqRBazUvK1gH6US6EyTdY7SCnuCkG7Na_GN-gDj8ZPb685YiLEUhgArlHQwe7jzN5iXqB-HPDOv4NIUqO0kxo8OjXUQnmfiHTMrPhFiVePlLz-sMDtOXlGL4uRgMUBhDy20asBeHWAOO6s0L9FBlBQ8KPi4M6jhTQuLoGSGh0EZDUk18mv8S6I2lWgdzJNplqlOWnhZR547HwyrI0ogFI2BEknBqZSDTTJ0B17oRYt7omcuyZAflNcvqXvqeO65PRQjLwpq38Ey2V4d_cu4vNn49eFgdaveKzxz1TO3LQ6rMG7Tx9mINagbLnLa7fkaSpmtsMGUBfTMseBdbVOWygtReWfV7iQzFtBoccS6NqdZRYLTr2gYTbY2ePkBRyy5vg)

- we are not protected against a birth certificat fraud
- we are not protected against middle man from governement officer
- we can not protect against false claim
- we can not protect against foreign and alien identity

But we will tune our running the bank once core design is setup.

####  Implementation based on frequency analysis

##### Cluster banking

https://github.com/chronoxor/CppTrader

We run a bank that will  cease to exist once the project is  finished,  accross  multiple countries with temporary but  purpose regulator/governor

1. Governor/Regulator will operate as a centralise identity holder, no workers and no account should exist without proof of seed of ID from regulator
2. Given identity ledger for multiple entity and roles each delegator will issue power of  act  for  role  manager and account  manager
3. role  manager will receive a provisionned account to create
4. Account manager will fill owner access to provisionned account
5. User/customer/worker will operate their account until total depletion

Oil/Gaz offshore platform for 30 years of exploitation
Country : France, Angola , Republique du  Congo,  RDC, Gabon
Dotation : 250 billion CFA
Workers : 4500,  repartion by countries: 15%, 35%, 25%, 25%
Central Bank : BCAO, Banque de France, FMI

To manage this operation, we clearly multple issues arising

To secure the project we will then propose a bank architecture as follow
Oil/Gaz offshore platform for 30 years of exploitation
Country : France, Angola , Republique du  Congo,  RDC, Gabon
Cluster Bank initial deposit : 250 billion CFA
Workers : 4500,  repartion by countries: 15%, 35%, 25%, 25%

##### Cluster banking Implementation

Due to heavy corruption, fraud, data leak, etc... we will now define a language.

We can not use scripting language for core operation as internal fraud might leak seed or core method operation. 

We will run black box code ( compiled + aggressive optimisation ) to insure a few  people are capable

We also need to address  horizontal  and  vertical problem of audit.

Horizontal problem  : client, trader, audit, supervisor, risk analysis will need to capture  the total exposition of all assets engaged as well as provisionned future exposure.

Vertical problem: On each exposure  we  need to run deep into timeline to replay scenario and find worst case scenario to prevent future crisis

Persistence and performance imply

- Central = critical  server maintenance
- Decentralised = Network coherency
- Cloud/Host = Randsome & warfare
- Multisite = Competences ressources

##### High Frequency Trading Fund Implementation

- Frequency problem: ns decison for a large set of exposures as well as low latency and fast data transfert from market central serve
- Horizontal problem : Maintain large order within an OMS
- Vertical problem: Guarantee exposure betwee orders  and  positions
- Sequence problem: Order position receive unique ordered sequence

          
## Technology choice and argue

First question would be, how to start ?

Persistence over event  :

- NMI energy on cold storage, behind ondulator : 1   / 100 ans
- NMI catastrophic failure on cold storage , water flood,storm,fire : 1 / 20 ans
- NMI corruption, malfunction on cold storage, EMC, warfare, manufacture MTBF : 1 / 10 ans
- NMI software on cold storage, virus, attack, loss of integrity :1/5 ans
- NMI logic on cold storage, wrong release, encoding loss, encryption or upgrade 1/2 ans
- NMI business on cold storage, audit, balance, seal

Solution : Hard Drive, Disque Magnetoptic, EEPROM, microfiche, micrograve

- NMI energy on hot storage, behind null modem cable : 1 / 2 ans
- NMI catastrophic failure on hot storage , water flood,storm,fire : 1 / 100 ans
- NMI corruption, malfunction on hot storage, EMC, warfare, manufacture MTBF : 1 / 100 ans
- NMI software on hot storage, virus, attack, loss of integrity :1/100 ans
- NMI logic on hot storage, wrong release, encoding loss, encryption or upgrade 1/2 ans
- NMI business on hot storage, audit, balance, seal

Solution :Chorum of ramdisk over null modem, Chorum of server master/slave, Duplicata over node + Most present

Final choice:

[Flatbuffer](https://google.github.io/flatbuffers/)

[SQLite](https://www.sqlite.org/index.html)

[ETL C++](https://www.etlcpp.com)

[Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)

References :

https://bazel.build/start/cpp

https://github.com/Haivision/srt

https://kb.b2bits.com/

https://flatbuffers.ar.je


We need a universal format to store regulated data, allowing multiple technology to access and read
We need a fast write method on harddrive
We need a fast read method on ramdisk
We need a vertical solution portable
We need a horizontale solution portable
We need data transfert easy and scalable
We need low latency
We need fastest way to aggregate column and rows

Step by step, we disqualify fake progressive technology ( Java, C#, Pascal, Lisp) as well as too old technology ( Fortran), too niche ( ADA, Haskel, Julia) or too dangerous( Javascript, R,  Python )

We isolate and qualify C++, Rust and Lua for their binding to LLVM, hence allowing Podman docker to pack all binaries and ship module.

C++ because of its ability to do aggressive optimization and high performance
Lua for its high perforamce for running dynamic rule and conditionnal expressive branch
Rust for safety execution 

#### Account management

Naive approache would be to create a simple ledger and allow direct operation such as 

Create an account, make a deposit, extract cash, close account, give current sold.

However there is time we will need to suspend all operations of an account , resume it, freeze a partial amount, also high frequency trading can create millions of transactions per day, where some account can be dormant ,also we want multiple level of access and security.

We propose to rigidify mininal definition of accont

An account carry a unique ID, a token access reader, a token access writer, a status holder and a vector of cash flow
it does support operation as : make a deposit, extract a limited deposit, accept transaction, locked cash, limits and properties 

account <>- accountuid, seed reader, seed writer, status, balance uid, last balance result, asofdate_status
balance <>- database dynamic list of cash flow operations, 

In order to generate our object we are going to use flatbuffer IDL


[![](https://mermaid.ink/img/pako:eNpNkU2OwjAMha9iZTUjwQW6GKm0_MwCCcHsWhZWYtqINimpMxpEufuENpXIynr6nv3sPIS0ikQiKoddDT95aSC8tDg4q7wkd4bl8mvIqbMMad8TD7D62KO7EkPP1mFFn5Nn9SIhe4zUc9Ky0f1tNMPBaUkD5EXqJWtrzu_EEU1FM7IuYv89XkOAd26j_0jN3KY4UuUbDCkilE_N6OapZ7hYBzk1-pfcfYBtMdcwtY-e7ejJrGGHkt8Mu2IW55HRsY4nQdVoQ3DzlvG1UZgxAZsROMmalG8oymIhWnItahWu_XgppeCaWipFEkoVMpWiNM_AoWd7uhspEnaeFsJ3CplyjeGTWpFcsOnp-Q-1x5DT?type=png)](https://mermaid.live/edit#pako:eNpNkU2OwjAMha9iZTUjwQW6GKm0_MwCCcHsWhZWYtqINimpMxpEufuENpXIynr6nv3sPIS0ikQiKoddDT95aSC8tDg4q7wkd4bl8mvIqbMMad8TD7D62KO7EkPP1mFFn5Nn9SIhe4zUc9Ky0f1tNMPBaUkD5EXqJWtrzu_EEU1FM7IuYv89XkOAd26j_0jN3KY4UuUbDCkilE_N6OapZ7hYBzk1-pfcfYBtMdcwtY-e7ejJrGGHkt8Mu2IW55HRsY4nQdVoQ3DzlvG1UZgxAZsROMmalG8oymIhWnItahWu_XgppeCaWipFEkoVMpWiNM_AoWd7uhspEnaeFsJ3CplyjeGTWpFcsOnp-Q-1x5DT)


## Politic risk and war risk : resilient over crisis

### Society built over social peace

We can not distinguish individus from their context of crisis, from point of view as banker, a individu carry on his own weight of choice and misfortune.
Over his own effort two layers carrying their own crisis, those layers are attach to individus by their inability to extract himself from society and his adaptability to overcome global crisis

### Society built over social war

While in conflict zone, secure transaction is meaningfull over secure primary asset and logistic force. A banker need to lower value of trust in storing pivot valuation of asset over relay and faciliate asset distribution and logistic. Hence capital values are shifted from asset storage to logistic flow.

### Modelizing political risk

Valuation of an asset regardless of existance of a bank

Owner of initial non liquid asset : $O_1$
Owner of final usage of asset or transformed result : $O_2$

At t=0, O2 want to obtain during futures dates $t_i$ a result of $C_i$, i move from 1 to N
$$Valuation of Asset O_2 = \sum_{i=1}^N { Acquisition of Asset O_1 \over N } * C_i * ( N - t_i ) * Depreciation of O_1(N) $$

Political decision will have an impact on Depreciation and delay or acceleration

Hence including political risk impact into agnostic model can be done by adding a event shift delay

$$Valuation of Asset O_2 =  \sum_{i=1}^N { Acquisition of Asset O_1 \over N } C_i * ( N - t_i - p_i ) * Depreciation of O_1(N -p_i) $$

Obsolescence, deprecation, forbid, exclusivity, subvention are forces that will result either in p_i be positive or negative

### Ledger under constraint of carrying value and transition

We can define a ledger of pivot currency transforming future value of a deposit but it will not survive regime change, devaluation/inflation, war and major crisis or we can create a ledger of value allowing smooth transition between regime and crisis

Hence our ledger $L$ would be summarize as :

$$ \left( L = \sum_{k=1}^n D_k  \right) $$

### Collaterised Asset Backed Bond and Funding tresory cash

We introduce a new way of selling trust for pivot currency management.
By default a banker will always lend money on a risk default curve :

* Accept cash ( buy zero default credit risk )
* Lend it with small reward ( sell our credit default risk )
* Borrow money ( buy zero default over our reward )
* Lend overnight ( sell our transformation of credit risk )

Those 4 steps are building insurrance and default cash pool of a bank

Rather than integrate all those operations and publish only a simple ledger of cash and transaction we will publish a true running ledger
$D_i$ deposite at date $t_i$  
$F_i$ funding at date $t_i$ rewarding interest or fees or insurance premium $Ir_i$ : $F_i = F_i + Ir_i$
$B_i$ borrowed cash for multiplying Ir at date $t_i$ paying $Br_i$ : $B_i = Ir_i * ( 1 + Rb_{i+j})$ 
$Lo_i$ lended cash overnight 

$$  L = \left( \sum_{i=1}^N D_i - F_i + B_i - Lo_i \right) $$


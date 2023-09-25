# IBAN-GUARD :guard: :dog:

This is CLI application allowing users to validate the European IBAN numbers[^1].

[^1]:Following countries are supported:
    - Andorra {AD}
    - Albania {AL}
    - Austria {AT}
    - Belgium {BE}
    - Bulgaria {BG}
    - Switzerland {CH}
    - Cyprus {CY}
    - Czech Republic {CZ}
    - Germany {DE}
    - Denmark {DK}
    - Estonia {EE}
    - Spain {ES}
    - Finland {FI}
    - France {FR}
    - United Kingdom {GB}
    - Greece {GR}
    - Croatia {HR}
    - Hungary {HU}
    - Ireland {IE}
    - Iceland {IS}
    - Italy {IT}
    - Lithuania {LT}
    - Luxembourg {LU}
    - Latvia {LV}
    - Monaco {MC}
    - Malta {MT}
    - Netherlands {NL}
    - Norway {NO}
    - Poland {PL}
    - Portugal {PT}
    - Romania {RO}
    - Sweden {SE}
    - Slovenia {SI}
    - Slovakia {SK}


# Installation
1. Clone the repo
```
git clone https://github.com/OleynikovNikolay/IBAN-Guard
cd IBAN-Guard
```
2. Compile with CMake 
``` 
cmake .
make
```
3. Change directory for binary file path
```
cd bin
```


# Usage 
## Navigation Page
```
./IBAN-GUARD --help
```

## IBAN Validation
```
./IBAN-GUARD --valdate-iban "iban number"
```

# License 
MIT License 



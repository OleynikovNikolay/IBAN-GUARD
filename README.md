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
## CMake MacOS
1. Clone the repo
```
git clone https://github.com/OleynikovNikolay/IBAN-GUARD
cd IBAN-GUARD
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

## Docker MacOS {Apple Silicon M1 (and M2) chip having AArch64} / Linux (ARM64)
Check you architecture on MacOS 
```
arch
```
If it has `arm64` then you macOS is suitable for this image. 


1. Clone the repo
```
git clone https://github.com/OleynikovNikolay/IBAN-GUARD
cd IBAN-GUARD
```
2. Build docker image
```
docker build -t iban-guard .
```
3. Check if the image has been successfully built
```
docker images | grep iban-guard
```
4. Run docker in iteractive terminal session 
```
docker run -it iban-guard
docker run iban-guard /app/bin/mac/IBAN-GUARD --help
docker run iban-guard /app/bin/mac/IBAN-GUARD --validate-iban [IBAN]
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



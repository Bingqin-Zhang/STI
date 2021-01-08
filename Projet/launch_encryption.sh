RED='\033[0;31m'
NC='\033[0m' # No Color


# Compilation et exécution en C:
echo "${RED} Compilation du code source en C ${NC}"

make

echo "${RED} Exécution du main ${NC}"
./main

echo "${RED} Nettoyage ${NC}"
make clean


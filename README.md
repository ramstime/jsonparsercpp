

#generate the cpp header files for json files with fallowing command

./generateCode.py --jsonpath ./jsonfiles/def/ --stjsonpath ./StaticJSON/ --incpath ./inc/

# generate shared library for staticjson 

g++ -fPIC src/staticjson.cpp -shared -o libstaticjson.so -I rapidjson-1.1.0/include/ -I include/ -std=c++11

# compile the sample parser with fallowing command

g++ src/jsonparser.cpp -g -std=c++11 -Wall -L StaticJSON -lstaticjson -I StaticJSON/rapidjson-1.1.0/include/ -I StaticJSON/include/  -I inc/ -I inc_common  -o bin/jsonparser


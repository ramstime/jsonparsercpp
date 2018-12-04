#generate the cpp header files for json with fallowing command

./generateCode.py --jsonpath ./jsonfiles/def/ --stjsonpath ./StaticJSON/ --incpath ./inc/

# generate shared library for staticjson 

g++ -fPIC staticjson.cpp -shared -o libstaticjson.so -I ../rapidjson/include/ -I ../include/ -std=c++11

# compile the sample parser with fallowing command
#
g++ src/jsonparser.cpp -g -std=c++11 -Wall -L StaticJSON/sharedlib/ -lstaticjson -I rapidjson/include/ -I StaticJSON/include/  -I inc/ -I inc_common  -o bin/jsonparser

#define AUTOJSONCXX_MODERN_COMPILER 1
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include "staticjson/document.hpp"
#include "EmployeeDataRequest.h"
#include "EmployeeDataResponse.h"
#include <string>

using namespace std;

template<typename T>
int loadjson(string jsonFile, T *datatPtr);

template<typename T>
int parsejson(T *datatPtr, string jsonFile);


int main(int argc , char ** argv )                                                                                                             
{
    
    auto* datarequestPtr = new apiDataMsp::EmployeeDataRequest;
    std::string jsonFile = "../jsonfiles/EmployeeDataRequest_schema.json";
    cout<<"Trying to parse datarequest:"<<endl;
    loadjson<apiDataMsp::EmployeeDataRequest>(jsonFile, datarequestPtr );
    jsonFile = "../jsonfiles/EmployeeDataRequest.json";
    parsejson<apiDataMsp::EmployeeDataRequest>(datarequestPtr, jsonFile);


    auto* datarespPtr = new apiDataMsp::EmployeeDataResponse;
    jsonFile = "../jsonfiles/EmployeeDataResponse_schema.json";
    cout<<"Trying to parse dataresp:"<<endl;
    loadjson<apiDataMsp::EmployeeDataResponse>(jsonFile, datarespPtr );
    jsonFile = "../jsonfiles/EmployeeDataResponse.json";
    parsejson<apiDataMsp::EmployeeDataResponse>(datarespPtr, jsonFile);


  return 0;
}

template<typename T>
int parsejson(T *datatPtr, string jsonFile)
{
     std::string jsonBuffer;
    staticjson::ParseStatus result;
    MsgPacker::JsonParser<T>::readJsonFile(jsonFile.c_str(), jsonBuffer);

     MsgPacker::JsonParseStatus *parseStatus = new MsgPacker::JsonParseStatus;
        if (0 != datatPtr->decode(jsonBuffer, result, parseStatus    )  )
        {
            cout<<"Decoding application data failed result:" << result.description()<<endl;
            cout<<"Error desc:"<<*parseStatus<<endl;
            return 1;
        }
/*
    if(datatPtr->decode(jsonBuffer, result))
    {
        cout<<"parse Failed:"<<endl;
        
        return 1;
    }
  */  
    cout<<"\nparse successfully:"<<endl;
    std::cout<<*datatPtr<<endl;
    return 1;
}
template<typename T>
int loadjson(string jsonFile, T *datatPtr)
{
    staticjson::ParseStatus result;
    std::string jsonBuffer;
    MsgPacker::JsonParser<T>::readJsonFile(jsonFile.c_str(), jsonBuffer);
    if (1 == MsgPacker::JsonParser<T>::loadSchemaValidator(jsonBuffer, result))
    {
        cout<<"Not able to load schema: " << jsonFile << " because of " << result.description();
        std::string errMsg = "Not able to load schema: " + jsonFile;
        return 1;
    }
    cout<<"Load schema success: " << jsonFile << endl;
    return 0;
}



#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include "staticjson/document.hpp"
#include "staticjson/staticjson.hpp"

#include "rapidjson/schema.h"
#include "rapidjson/prettywriter.h"

namespace MsgPacker
{


class JsonParseStatus
{
public:
    std::string              mSchemaViolationReport;
    std::string              mInvalidSchema;
    std::string              mInvalidSchemaKeyWord;
    std::string              mInvalidDocument;

    void reset()
    {
        mSchemaViolationReport.clear();
        mInvalidSchema.clear();
        mInvalidSchemaKeyWord.clear();
        mInvalidDocument.clear();
    }
    friend std::ostream& operator<<(std::ostream& o, const JsonParseStatus & obj) {
        o<<"mSchemaViolationReport:"<<obj.mSchemaViolationReport<<std::endl;
        o<<"mInvalidSchema:"<<obj.mInvalidSchema<<std::endl;
        o<<"mInvalidSchemaKeyWord:"<<obj.mInvalidSchemaKeyWord<<std::endl;
        o<<"mInvalidDocument:"<<obj.mInvalidDocument<<std::endl;

        return o;

    }
};



/**
 * This class is base for all application message classes.
 * it will be providing all necessary json parsing and validation functionality.
 *
 */

template<typename DerivedT>
class JsonParser
{

private:

    static rapidjson::SchemaValidator* schemaValidator;
    static rapidjson::SchemaDocument* schemaDocument;

public:
    /*
          * FUNCTION:JsonParser()
          *
          * @param[in]
          * @param[out]
          *
       */
    explicit JsonParser() { }

    /*
         * FUNCTION:~JsonParser()
         *
         * @param[in]
         * @param[out]
         *
      */
    ~JsonParser()
    {

    }

    /*
         * FUNCTION:readJsonFile()
         *
         * @return           void
         *
         * @param[in]     filename - json file name to be read
         * @param[out]   jsonBuffer - json buffer loaded from file
         *
         * @Usage          call this method to read the json file and load buffer in string
    */
    static void readJsonFile(const std::string& filename, std::string& jsonBuffer)
    {
        std::cout<<"trying to open file: "<<filename<<std::endl;
        std::ifstream infile(filename);
        getline(infile, jsonBuffer, std::string::traits_type::to_char_type(
                    std::string::traits_type::eof()));
        //std::cout<<"Content in json schema file:"<<jsonBuffer<<std::endl;
    }
    /*
         * FUNCTION:encode()
         *
         * @return        void
         *
         * @param[in]    json buffer to be filled
         *
         * @Usage        call this method to encode the json data into the jsonBuffer
    */
    void encode(std::string& jsonBuffer)
    {
        auto derived = static_cast<DerivedT*>(this);
        jsonBuffer = staticjson::to_json_string(*derived);

    }
    /*
         * FUNCTION:loadSchemaValidator()
         *
         * @return           boolean
         *
         * @param[in]     jsonBuffer - json schema buffer
         * @param[out]   ParseStatus- schema parse result
         *
         * @Usage          call this method to load the json schema into validator
    */
    static int loadSchemaValidator(const std::string& jsonSchema, staticjson::ParseStatus& result)
    {
        rapidjson::Document tempDoc;
        if (!staticjson::from_json_string(jsonSchema.c_str(), &tempDoc, &result))
        {
            return 1;
        }
        schemaDocument = new(rapidjson::SchemaDocument)(tempDoc);
        schemaValidator = new(rapidjson::SchemaValidator)(*schemaDocument);
        return 0;
    }
    /*
        * FUNCTION:deleteSchemaValidator()
        *
        * @return
        *
        * @param[in]
        * @param[out]
        *
        * @Usage          call this method to delete the json schema validators
    */
    static void deleteSchemaValidator()
    {
        if (nullptr != schemaValidator)
        {
            //std::cout << "Deleting schemaValidator" << std::endl;
            delete schemaValidator;
            schemaValidator = nullptr;
        }
        if (nullptr != schemaDocument)
        {
            //std::cout << "Deleting schemaDocument" << std::endl;
            delete schemaDocument;
            schemaDocument = nullptr;
        }
    }

    /*
         * FUNCTION:decode()
         *
         * @return        
         *
         * @param[in]     jsonBuffer - input json buffer
         * @param[out]     ParseStatus - result of parsing
         *
         * @Usage         call this method to decode the json bufer into the c++ class data structure
    */
    int decode(const std::string& jsonBuffer,
                         staticjson::ParseStatus& result,
                        JsonParseStatus *parseStatus 
                         )
    {

        auto derived = static_cast<DerivedT*>(this);
        if (NULL == schemaValidator)
        {
            if (!staticjson::from_json_string(jsonBuffer.c_str(), derived, &result))
            {
                return 1;
            }

            return 0;
        }
        rapidjson::Document d;
        schemaValidator->Reset();
        if (!staticjson::from_json_string(jsonBuffer.c_str(), &d, &result))
        {
            std::cout<<"json to string failed"<<std::endl;
            return 1;
        }
        if (!d.Accept(*schemaValidator))
        {
            
            //populate schema violation errors from rapid json error object
            // and schemaValidator
            
            if (nullptr != parseStatus)
            {
                std::cout<<"filling reason of failure"<<std::endl;
                rapidjson::StringBuffer sb;
                schemaValidator->GetInvalidSchemaPointer().StringifyUriFragment(sb);
                parseStatus->mInvalidSchema = sb.GetString();
                parseStatus->mInvalidSchemaKeyWord = schemaValidator->GetInvalidSchemaKeyword();
                sb.Clear();
                schemaValidator->GetInvalidDocumentPointer().StringifyUriFragment(sb);
                parseStatus->mInvalidDocument = sb.GetString();

                // Detailed violation report is available as a JSON value
                //sb.Clear();
                //rapidjson::PrettyWriter<rapidjson::StringBuffer> w(sb);
                //schemaValidator->GetError().Accept(w);
                //parseStatus->mSchemaViolationReport = sb.GetString();

            }
            std::cout<<"json Accept failed"<<std::endl;
            return 1;
        }
        if (!staticjson::from_json_document(d, derived, &result))
        {
            std::cout<<"json to string failed"<<std::endl;
            return 1;
        }
        return 0;
    }

};

template <typename T> rapidjson::SchemaValidator* JsonParser<T>::schemaValidator = NULL;
template <typename T> rapidjson::SchemaDocument* JsonParser<T>::schemaDocument = NULL;

}
#endif


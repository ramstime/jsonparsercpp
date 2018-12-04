/**
 * © 2018 OpenSource.
 */

#ifndef EMPLOYEEDATAREQUEST_H
#define EMPLOYEEDATAREQUEST_H

#include "JsonParser.h"
namespace apiDataMsp {
class EmployeeDataRequest: public MsgPacker::JsonParser<EmployeeDataRequest> {
public:
    std::string mRequesterId;
    std::string mRequesterType;
    std::string mEmpId;

    explicit EmployeeDataRequest():mRequesterId(), mRequesterType(), mEmpId() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("RequesterId", &this->mRequesterId, staticjson::Flags::Default);
        h->add_property("RequesterType", &this->mRequesterType, staticjson::Flags::Default);
        h->add_property("EmpId", &this->mEmpId, staticjson::Flags::Optional);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const EmployeeDataRequest & obj) {
        o<<"RequesterId:"<<obj.mRequesterId<<std::endl;
        o<<"RequesterType:"<<obj.mRequesterType<<std::endl;
        o<<"EmpId:"<<obj.mEmpId<<std::endl;

        return o;

    }
};
}

#endif
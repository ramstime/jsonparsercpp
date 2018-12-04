/**
 * © 2018 OpenSource.
 */

#ifndef EMPLOYEEDATARESPONSE_H
#define EMPLOYEEDATARESPONSE_H

#include "JsonParser.h"
namespace apiDataMsp {
class TeamContacts {
public:
    std::string mName;
    std::string mMobile;
    std::string mDesignation;

    explicit TeamContacts():mName(), mMobile(), mDesignation() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("Name", &this->mName, staticjson::Flags::Default);
        h->add_property("Mobile", &this->mMobile, staticjson::Flags::Optional);
        h->add_property("Designation", &this->mDesignation, staticjson::Flags::Default);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const TeamContacts & obj) {
        o<<"Name:"<<obj.mName<<std::endl;
        o<<"Mobile:"<<obj.mMobile<<std::endl;
        o<<"Designation:"<<obj.mDesignation<<std::endl;

        return o;

    }
};
}

namespace apiDataMsp {
class TeamDetails {
public:
    std::string mTeamName;
    std::vector<TeamContacts> mTeamContacts;

    explicit TeamDetails():mTeamName(), mTeamContacts() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("TeamName", &this->mTeamName, staticjson::Flags::Default);
        h->add_property("TeamContacts", &this->mTeamContacts, staticjson::Flags::Default);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const TeamDetails & obj) {
        o<<"TeamName:"<<obj.mTeamName<<std::endl;
        for (auto& id : obj.mTeamContacts)
            o<<"TeamContacts:"<<id<<std::endl;

        return o;

    }
};
}

namespace apiDataMsp {
class ContactDetails {
public:
    std::string mSkypeId;
    std::string mMailId;

    explicit ContactDetails():mSkypeId(), mMailId() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("SkypeId", &this->mSkypeId, staticjson::Flags::Default);
        h->add_property("MailId", &this->mMailId, staticjson::Flags::Default);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const ContactDetails & obj) {
        o<<"SkypeId:"<<obj.mSkypeId<<std::endl;
        o<<"MailId:"<<obj.mMailId<<std::endl;

        return o;

    }
};
}

namespace apiDataMsp {
class JobDetails {
public:
    std::string mProjectName;
    std::string mDesignation;
    uint32_t mDesignationCode;
    bool mManager;
    int mGradeLevel;
    std::string mIpAddress;
    TeamDetails mTeamDetails;
    bool mWorkFromHomeAllowed;
    std::string mWebsite;
    std::string mMeetingURL;
    ContactDetails mContactDetails;

    explicit JobDetails():mProjectName(), mDesignation(), mDesignationCode(), mManager(), mGradeLevel(), mIpAddress(), mTeamDetails(), mWorkFromHomeAllowed(), mWebsite(), mMeetingURL(), mContactDetails() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("ProjectName", &this->mProjectName, staticjson::Flags::Default);
        h->add_property("Designation", &this->mDesignation, staticjson::Flags::Default);
        h->add_property("DesignationCode", &this->mDesignationCode, staticjson::Flags::Default);
        h->add_property("Manager", &this->mManager, staticjson::Flags::Default);
        h->add_property("GradeLevel", &this->mGradeLevel, staticjson::Flags::Default);
        h->add_property("IpAddress", &this->mIpAddress, staticjson::Flags::Default);
        h->add_property("TeamDetails", &this->mTeamDetails, staticjson::Flags::Default);
        h->add_property("WorkFromHomeAllowed", &this->mWorkFromHomeAllowed, staticjson::Flags::Default);
        h->add_property("Website", &this->mWebsite, staticjson::Flags::Optional);
        h->add_property("MeetingURL", &this->mMeetingURL, staticjson::Flags::Optional);
        h->add_property("ContactDetails", &this->mContactDetails, staticjson::Flags::Default);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const JobDetails & obj) {
        o<<"ProjectName:"<<obj.mProjectName<<std::endl;
        o<<"Designation:"<<obj.mDesignation<<std::endl;
        o<<"DesignationCode:"<<obj.mDesignationCode<<std::endl;
        o<<"Manager:"<<obj.mManager<<std::endl;
        o<<"GradeLevel:"<<obj.mGradeLevel<<std::endl;
        o<<"IpAddress:"<<obj.mIpAddress<<std::endl;
        o<<"TeamDetails:"<<obj.mTeamDetails<<std::endl;
        o<<"WorkFromHomeAllowed:"<<obj.mWorkFromHomeAllowed<<std::endl;
        o<<"Website:"<<obj.mWebsite<<std::endl;
        o<<"MeetingURL:"<<obj.mMeetingURL<<std::endl;
        o<<"ContactDetails:"<<obj.mContactDetails<<std::endl;

        return o;

    }
};
}

namespace apiDataMsp {
class Skills {
public:
    std::vector<std::string> mProgramming;
    std::vector<std::string> mManagement;

    explicit Skills():mProgramming(), mManagement() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("Programming", &this->mProgramming, staticjson::Flags::Default);
        h->add_property("Management", &this->mManagement, staticjson::Flags::Default);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const Skills & obj) {
        for (auto& id : obj.mProgramming)
            o<<"Programming:"<<id<<std::endl;
        for (auto& id : obj.mManagement)
            o<<"Management:"<<id<<std::endl;

        return o;

    }
};
}

namespace apiDataMsp {
class SkillSet {
public:
    Skills mSkills;
    std::vector<std::string> mProjects;

    explicit SkillSet():mSkills(), mProjects() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("Skills", &this->mSkills, staticjson::Flags::Default);
        h->add_property("Projects", &this->mProjects, staticjson::Flags::Optional);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const SkillSet & obj) {
        o<<"Skills:"<<obj.mSkills<<std::endl;
        for (auto& id : obj.mProjects)
            o<<"Projects:"<<id<<std::endl;

        return o;

    }
};
}

namespace apiDataMsp {
class EmployeeDataResponse: public MsgPacker::JsonParser<EmployeeDataResponse> {
public:
    std::string mEmpId;
    JobDetails mJobDetails;
    SkillSet mSkillSet;

    explicit EmployeeDataResponse():mEmpId(), mJobDetails(), mSkillSet() {  }


    void staticjson_init(staticjson::ObjectHandler* h) {
        h->add_property("EmpId", &this->mEmpId, staticjson::Flags::Default);
        h->add_property("JobDetails", &this->mJobDetails, staticjson::Flags::Default);
        h->add_property("SkillSet", &this->mSkillSet, staticjson::Flags::Default);

        h->set_flags(staticjson::Flags::Default | staticjson::Flags::DisallowUnknownKey);
    }


    friend std::ostream& operator<<(std::ostream& o, const EmployeeDataResponse & obj) {
        o<<"EmpId:"<<obj.mEmpId<<std::endl;
        o<<"JobDetails:"<<obj.mJobDetails<<std::endl;
        o<<"SkillSet:"<<obj.mSkillSet<<std::endl;

        return o;

    }
};
}

#endif
#include "member.h"

Member::Member()
{
    this->idMember = 0;
    this->lastName = "DEFAULT";
    this->firstName = "DEFAULT";
    this->email = "DEFAULT";
    this->status = AUTRE;
}

std::string Member::getStatus()
{
    switch(status)
    {
    case L1:
        return "L1";
    case L2I:
        return "L2I";
    case L2M:
        return "L2M";
    case L3I:
        return "L3I";
    case L3M:
        return "L3M";
    case M1I:
        return "M1I";
    case M1M:
        return "M1M";
    case M2I:
        return "M2I";
    case M2M:
        return "M2M";
    case DOC:
        return "DOC";
    case PROF:
        return "PROF";
    case AUTRE:
        return "AUTRE";
    default:
        return "ERROR";
    }
}

std::string Member::statusToString(Status s)
{
    switch(s)
    {
    case L1:
        return "L1";
    case L2I:
        return "L2I";
    case L2M:
        return "L2M";
    case L3I:
        return "L3I";
    case L3M:
        return "L3M";
    case M1I:
        return "M1I";
    case M1M:
        return "M1M";
    case M2I:
        return "M2I";
    case M2M:
        return "M2M";
    case DOC:
        return "DOC";
    case PROF:
        return "PROF";
    case AUTRE:
        return "AUTRE";
    default:
        return "ERROR";
    }
}

Status Member::stringToStatus(std::string s)
{
    if(s.compare("L1")==0)
        return L1;
    if(s.compare("L2I")==0)
        return L2I;
    if(s.compare("L2M")==0)
        return L2M;
    if(s.compare("L3I")==0)
        return L3I;
    if(s.compare("L3M")==0)
        return L3M;
    if(s.compare("M1I")==0)
        return M1I;
    if(s.compare("M1M")==0)
        return M1M;
    if(s.compare("M2I")==0)
        return M2I;
    if(s.compare("M2M")==0)
        return M2M;
}

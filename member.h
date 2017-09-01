#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

typedef enum Status_
{
    L1      = 0x10,
    L2I     = 0x21,
    L2M     = 0x22,
    L3I     = 0x31,
    L3M     = 0x32,
    M1I     = 0x41,
    M1M     = 0x42,
    M2I     = 0x51,
    M2M     = 0x52,
    DOC     = 0x60,
    PROF    = 0x70,
    AUTRE   = 0xF0
} Status;

class Member
{
public:
    Member();

    int idMember;
    std::string lastName;
    std::string firstName;
    std::string email;
    Status status;

    std::string getStatus();
    std::string statusToString(Status s);
    Status stringToStatus(std::string s);
};

#endif // MEMBER_H

#include "passwordgenerator.h"

/******* PUBLIC **********/

PasswordGenerator::PasswordGenerator(const int &inputStrong, const int &inputLength)
{
    resetArguments();
    setArguments(inputStrong, inputLength);

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    srand((time_t)ts.tv_nsec);
    generatePassword();
}

void PasswordGenerator::setArguments(const int &inputStrong, const int &inputLength)
{
    this->strong = inputStrong;
    this->length = inputLength;
}

std::string PasswordGenerator::getPassword() const
{
    return this->password;
}

int PasswordGenerator::getStrong() const
{
    return this->strong;
}

int PasswordGenerator::getLength() const
{
    return this->length;
}

/******* PRIVATE **********/

void PasswordGenerator::resetArguments()
{
    this->password = "";
    this->strong = 0;
    this->length = 0;
}

void PasswordGenerator::generatePassword()
{
    int tempStrong = getStrong();
    std::string tempPassword = "";

    if(tempStrong <= COUNT_HSYMBOL)
    {
        tempPassword = createPasswordShort();
    }
    else if(tempStrong <= COUNT_HNSYMBOL)
    {
        tempPassword = createPassword();
    }
    else if(tempStrong <= COUNT_HNLSYMBOL)
    {
        tempPassword = createPasswordLong();
    }

    setPassword(tempPassword);
}

void PasswordGenerator::setPassword(const std::string &inputPassword)
{
    this->password = inputPassword;
}

std::string PasswordGenerator::createPasswordShort()
{
    std::string tempPassword = "";
    int tempStrong = getStrong();
    int tempLength = getLength();

    int intervalHighLimit = MIN_HSYMBOL + tempStrong;

    for(int i = 0; i < tempLength; i++)
    {
        int characterValue = getRandInt(MIN_HSYMBOL, intervalHighLimit);
        std::string characterBuffer(1, characterValue);

        tempPassword += characterBuffer;
    }

    return tempPassword;
}

std::string PasswordGenerator::createPassword()
{
    std::string tempPassword = "";
    int tempStrong = getStrong();
    int tempLength = getLength();

    int intervalNumberHighLimit = MIN_NSYMBOL + tempStrong - COUNT_HSYMBOL;

    for(int i = 0; i < tempLength; i++)
    {
        int isCharacter = rand () % 2 + 1;
        int characterValue = 0;

        if(isCharacter == 1)
            characterValue = getRandInt(MIN_HSYMBOL, MAX_HSYMBOL);
        else if(isCharacter == 2)
            characterValue = getRandInt(MIN_NSYMBOL, intervalNumberHighLimit);

        std::string characterBuffer(1, characterValue);

        tempPassword += characterBuffer;
    }

    return tempPassword;
}

std::string PasswordGenerator::createPasswordLong()
{
    std::string tempPassword = "";
    int tempStrong = getStrong();
    int tempLength = getLength();

    int intervalLowerHighLimit = MIN_LSYMBOL + tempStrong - COUNT_HNSYMBOL;

    for(int i = 0; i < tempLength; i++)
    {
        int isCharacter = rand () % 3 + 1;
        int characterValue = 0;

        if(isCharacter == 1)
            characterValue = getRandInt(MIN_HSYMBOL, MAX_HSYMBOL);
        else if(isCharacter == 2)
            characterValue = getRandInt(MIN_NSYMBOL, MAX_NSYMBOL);
        else if(isCharacter == 3)
            characterValue = getRandInt(MIN_LSYMBOL, intervalLowerHighLimit);

        std::string characterBuffer(1, characterValue);

        tempPassword += characterBuffer;
    }

    return tempPassword;
}

int PasswordGenerator::getRandInt(const int &intervalMIN, const int &intervalMAX)
{
    int randValue = intervalMIN + rand() % (intervalMAX - intervalMIN);

    return randValue;
}






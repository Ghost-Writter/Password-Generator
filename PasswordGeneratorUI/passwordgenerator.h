#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#define MIN_HSYMBOL 65        //Первый заглавный символ
#define MAX_HSYMBOL 90        //Последний заглавный символ
#define MIN_NSYMBOL 48        //Первый символ-число
#define MAX_NSYMBOL 57        //Последний символ-число
#define MIN_LSYMBOL 97        //Первый строчной символ
#define MAX_LSYMBOL 122       //Последний строчной символ

#define COUNT_HSYMBOL 26        //Количество заглавных символов
#define COUNT_HNSYMBOL 35       //Количество заглавных и цифр символов
#define COUNT_HNLSYMBOL 61      //Количество заглавных, цифр и прописных символов

#include <string>
#include <cstdlib>
#include <ctime>

class PasswordGenerator
{
public:

    PasswordGenerator(const int &inputStrong, const int &inputLength);

    void setArguments(const int &inputStrong, const int &inputLength);

    std::string getPassword() const;
    int getStrong() const;
    int getLength() const;

private:

    std::string password;
    int strong;
    int length;

    void resetArguments();
    void generatePassword();
    void setPassword(const std::string &inputPassword);

    std::string createPasswordShort();
    std::string createPassword();
    std::string createPasswordLong();

    int getRandInt(const int &intervalMIN, const int &intervalMAX);
};

#endif // PASSWORDGENERATOR_H

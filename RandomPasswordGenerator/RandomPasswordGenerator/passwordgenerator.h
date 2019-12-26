#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#define min_smallLetter 97
#define max_smallLetter 122

#define min_capitalLetter 65
#define max_capitalLetter 90

#define min_number 48
#define max_number 57

#define min_character 33
#define max_character 47

#include <map>
#include <list>
#include <QString>

using namespace std;


class PasswordGenerator
{
public:
    PasswordGenerator(int plength, int slength, int clength=0, int nlength=0, int chlength=0);

    int getPasswordLength();
    int getSmallLetterLength();
    int getCapitalLetterLength();
    int getNumberLength();
    int getCharacterLength();

    void setPasswordLength(int plength);
    void setSmallLetterLength(int slength);
    void setCapitalLetterLength(int clength);
    void setNumberLength(int nlength);
    void setCharacterLength(int clength);

    void printIdList();

    QString convertPasswordMapToString();

private:
    int password_length = 0;
    int smallLetter_length = 0;
    int capitalLetter_length = 0;
    int number_length = 0;
    int character_length = 0;

    list<int> *id_list = nullptr;
    map<int, int> *password_map = nullptr;

private:
    void setIdList(int plength);
    int getRandomFromIdList();

    int getRandomCharacter(int type);
    void getPassword(int length, int small_letter, int capital_letter=0, int number=0, int character=0);
};

#endif // PASSWORDGENERATOR_H

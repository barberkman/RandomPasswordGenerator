#include "passwordgenerator.h"

#include <QDebug>
#include <QRandomGenerator>

PasswordGenerator::PasswordGenerator(int plength, int slength, int clength, int nlength, int chlength):
    id_list(new list<int>),
    password_map(new map<int, int>)
{
    setPasswordLength(plength);
    setSmallLetterLength(slength);

    if (clength != 0){
        setCapitalLetterLength(clength);
    }

    if (nlength != 0){
        setNumberLength(nlength);
    }

    if (chlength != 0){
        setCharacterLength(chlength);
    }

    setIdList(getPasswordLength());

    getPassword(getPasswordLength(), getSmallLetterLength(),
                getCapitalLetterLength(), getNumberLength(), getCharacterLength());

}

int PasswordGenerator::getPasswordLength()
{
    return password_length;
}

int PasswordGenerator::getSmallLetterLength()
{
    return smallLetter_length;
}

int PasswordGenerator::getCapitalLetterLength()
{
    return capitalLetter_length;
}

int PasswordGenerator::getNumberLength()
{
    return number_length;
}

int PasswordGenerator::getCharacterLength()
{
    return character_length;
}

void PasswordGenerator::printIdList()
{
    list<int> :: iterator it;
    for (it = id_list->begin(); it != id_list->end(); ++it){
        qDebug() << *it;
    }
}

QString PasswordGenerator::convertPasswordMapToString()
{
    QString password = "";
    char c;
    map<int, int> :: iterator it;
    for(it = password_map->begin(); it != password_map->end(); ++it){
        c = static_cast<char>(it->second);
        password.push_back(c);
    }

    return password;
}

void PasswordGenerator::setPasswordLength(int plength)
{
    password_length = plength;
}

void PasswordGenerator::setSmallLetterLength(int slength)
{
    smallLetter_length = slength;
}

void PasswordGenerator::setCapitalLetterLength(int clength)
{
    capitalLetter_length = clength;
}

void PasswordGenerator::setNumberLength(int nlength)
{
    number_length = nlength;
}

void PasswordGenerator::setCharacterLength(int clength)
{
    character_length = clength;
}

void PasswordGenerator::setIdList(int plength)
{
    for (int i = 0; i < plength; i++){
        id_list->push_back(i);
    }
}

int PasswordGenerator::getRandomFromIdList()
{
    list<int> :: iterator it = id_list->begin();
    int index = QRandomGenerator::global()->generate() % id_list->size();
    advance(it, index);
    int value = *it;
    id_list->erase(it);
    return value;
}

int PasswordGenerator::getRandomCharacter(int type)
{
    /*
       Type = 0: small_leter
       Type = 1: capital_letter
       Type = 2: number
       Type = 3: character
    */
    int temp_character = 0;
    int range = 0;

    switch (type) {
    case 0:
        range = max_smallLetter - min_smallLetter + 1;
        temp_character = QRandomGenerator::global()->generate() % range + min_smallLetter;
        break;
    case 1:
        range = max_capitalLetter - min_capitalLetter + 1;
        temp_character = QRandomGenerator::global()->generate() % range + min_capitalLetter;
        break;
    case 2:
        range = max_number - min_number + 1;
        temp_character = QRandomGenerator::global()->generate() % range + min_number;
        break;
    case 3:
        range = max_character - min_character + 1;
        temp_character = QRandomGenerator::global()->generate() % range + min_character;
        break;
    default:
        qDebug() << "getRandomCharacter(int type): Type not in range";
        break;
    }

    return temp_character;
}

void PasswordGenerator::getPassword(int length, int small_letter, int capital_letter, int number, int character)
{
    int id = -1;
    int value = -1;
    QString thePassword = "";

    if(length != (small_letter + capital_letter + number + character)){
        qDebug() << "getPassword(): Error sum doesnt add up";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < small_letter; i++){
        id = getRandomFromIdList();
        value = getRandomCharacter(0);
        password_map->insert(pair<int, int>(id, value));
    }

    if(capital_letter != 0){
        for (int i = 0; i < capital_letter; i++){
            id = getRandomFromIdList();
            value = getRandomCharacter(1);
            password_map->insert(pair<int, int>(id, value));
        }
    }

    if(number != 0){
        for (int i = 0; i < number; i++){
            id = getRandomFromIdList();
            value = getRandomCharacter(2);
            password_map->insert(pair<int, int>(id, value));
        }
    }

    if(character != 0){
        for (int i = 0; i < character; i++){
            id = getRandomFromIdList();
            value = getRandomCharacter(3);
            password_map->insert(pair<int, int>(id, value));
        }
    }

    qDebug() << "Done creating password";
}


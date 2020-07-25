
#ifndef CONTACTLISTPROVIDER_H
#define CONTACTLISTPROVIDER_H
#include <iostream>
#include <QVector>
#include <QObject>
#include <string>
#include "info.h"

using namespace std;


class ContactListProvider : public QObject
{
    Q_OBJECT
private:
    QVector<info*> list;
    QVector<info*> FavoriteList;

    static ContactListProvider* p_instance;
    ContactListProvider(QObject* parent = nullptr) : QObject(parent)
    {
        AddContact("Maksym", "Bezuhlyi", 380960556);
        AddContact("Vladyslav", "Ischenko", 546565464);
        AddContact("Ekateryna", "Ohbaidze", 5676565);
        AddContact("Anna", "Pereschkura", 345433);
        AddContact("Aleksandra", "Neklesa", 56565);
        AddContact("Olya", "Anal", 56565);
    };
    ContactListProvider(const ContactListProvider& obj) = delete;
    ContactListProvider(const ContactListProvider&& obj) = delete;

public:

    //Pattern Singleton
    static ContactListProvider* getInstance() {if(!p_instance)
         p_instance = new ContactListProvider();
        return p_instance;}

    ~ContactListProvider() {for(int i =0; i < list.size(); i++) {delete list[i];} p_instance = nullptr; delete p_instance; };
   //Functions

    void AddContact(string name, string surname, int number);
   info* ShowContacts(int id) const;
    void DeleteContact(int id);
    void MakeFavorite(int id);
    void DeleteFromFavorite(int id);
   info* ShowFavorite(int id) const; //get const
   void SortContactsByName();
    bool MakeCa1ll() const;

    //HelpFunctions
     int RightSymbolInput();

    //Accessors

    inline QVector<info*> getList() const {return this->list;}
    inline QVector<info*> getFavoriteList() const {return this->FavoriteList;}


};

#endif // CONTACTLISTPROVIDER_H


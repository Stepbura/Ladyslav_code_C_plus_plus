#include "contactlistprovider.h"
#include <QString>
#include <QCoreApplication>
#include <QVector>
#include <QTextStream>

ContactListProvider* ContactListProvider::p_instance = 0;

void ContactListProvider::AddContact(string name, string surname, int number)
{
    info* object = new info();
    object->name = QString::fromUtf8(name.c_str());
    object->surname = QString::fromUtf8(surname.c_str());
    object->number = number;
    object->id = 1 + rand()%1000;
    this->list.push_back(object);
}

info* ContactListProvider::ShowContacts(int id) const
{
    if(this->list.empty())
    {
        throw "List is empty!";
    }
    for(int i = 0; i < this->list.size(); i++)
    {
        if(id == this->list[i]->id)
        {
            return this->list[i];
        }
    }
    throw "Not found";
}

void ContactListProvider::DeleteContact(int id)
{
    if(list.empty())
        throw "Buffer is empty";

    for(int i = 0; i < list.size(); i++)
    {
        if(id == this->list[i]->id)
        {
            delete this->list[i];
            this->list.erase(list.begin() + i);
        }

    }

}

void ContactListProvider::MakeFavorite(int id)
{
    if(this->list.empty())
        throw "List is Empty!";
    else
    {
        for(int i = 0; i < list.size(); i++)
        {
         if(id == list[i]->id && !list[i]->favorite)
         {
             list[i]->favorite = true;
             this->FavoriteList.push_back(list[i]);
         }
    }
}
}

void ContactListProvider::DeleteFromFavorite(int id)
{
    if(this->FavoriteList.empty())
        throw "List is Empty!";
    else
    {
        for(int i = 0; i < this->FavoriteList.size(); i++)
        {
            if(id == this->FavoriteList[i]->id)
            {
                this->list.erase(list.begin() + i);
            }
        }

    }
}

info* ContactListProvider::ShowFavorite(int id) const
{
    if(this->FavoriteList.empty())
        throw "List is Empty!";
    else
    {
        for(int i = 0; i < this->FavoriteList.size(); i++)
        {
            if(id == this->FavoriteList[i]->id)
            {
                return this->FavoriteList[i];
            }
        }
        throw"Not Found";

    }
}

void ContactListProvider::SortContactsByName()
{
   /* sort(this->list.begin(), this->list.end(), [](const info& obj1, const info& obj2)
    {
        return obj1.name < obj2.name;
    });
   */
}

/*int ContactListProvider::RightSymbolInput()
{
    int i = 0;
    cin >> i;
    while (cin.fail())
    {
        system("cls");
        cout << "Faulty input" << "\n";
        cin.clear();
        cin.ignore(100, '\n');

        cout << endl << "Wtite Number Again: ";
        cin >> i;
    }
    return i;
}
*/

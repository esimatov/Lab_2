/// в этом файле описывается всё, указанное в book.h
#include <iostream> ///библиотека ввода-вывода
#include "Book.h"   ///наша бибиллиотека класса книга
#include <string>   ///бибилиотека строк
#include <cstring>  ///библиотека функций работающих со строками

using namespace std;
    Book :: Book()  ///конструктор
    {
        setCountPage(0);
    }
    Book :: Book(const string &author, const string &name, const int &countPage)
    {
        this -> author = author;
        this -> name = name;
        if( countPage >=0 )
            this -> countPage = countPage;
        else
            this -> countPage = 0;
    }

    Book :: Book (const Book &otherBook)    ///конструктор копирования
    {
        this -> author = otherBook.author;
        this -> name = otherBook.name;
        this -> countPage = otherBook.countPage;
    }
    void Book :: print()const   ///вывод всей информации о книге
    {   cout << "\nAuthor: " << author << "\nName: " << name << "\nCount of pages: " << countPage << endl;    }

    void Book :: setName(const string &name)    ///установка имя книги
    {   this -> name = name;  }

    void Book :: setAuthor(const string &author)    ///установка автора книги
    {   this -> author = author;  }

    void Book :: setCountPage(const int &countPage) ///установка числа страниц в книге
    {
        if(countPage >= 0)                  ///число страниц не меньше 0
            this -> countPage = countPage;
    }

    const string& Book :: getName()const    ///взятие имени книги из объекта класса
    {
        return name;
    }

    const string& Book :: getAuthor()const  ///взятие автора книги из объекта класса
    {
        return author;
    }

   const int Book :: getCountPage()const   ///взятие числа страниц из объекта класса
    {
        return countPage;
    }





    Book& Book :: operator = (const Book &book)
    {
        this -> author = book.author;
        this -> name = book.name;
        this -> countPage = book.countPage;
        return *this;
    }

    const bool Book :: operator == (const Book &book)
    {
        return ((this -> name == book.name)&&(this -> author == book.author)&&(this -> countPage == book.countPage));
    }

    const bool Book :: operator != (const Book &book)
    {
        return (!(*this == book));
    }

    const bool Book :: operator > (const Book &book)
    {
        if (this -> author > book.author)
        {
            return true;
        }else{
            if ((this -> author == book.author)&&(this -> name > book.name))
            {
                return true;
            }else{
                if ((this -> author == book.author)&&(this -> name == book.name)&&(this -> countPage > book.countPage))
                    return true;
            }
        }
        return false;
    }

    const bool Book :: operator < (const Book &book)
    {
        return (!((*this > book)||(*this == book)));
    }

    const bool Book :: operator <= (const Book &book)
    {
        return (!(*this > book));
    }

    const bool Book :: operator >= (const Book &book)
    {
        return (!(*this < book));
    }

    ostream& operator << (ostream &out, const Book &book)
    {
        out << "Author:\t" << book.author << "\tName:\t" << book.name << "\tColor:\t" << book.countPage;
        return out;
    }

    istream& operator >> (istream &in, Book &book)
    {
        in >> book.author;
        in >> book.name;
        in >> book.countPage;
        return in;
    }

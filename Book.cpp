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
    Book :: Book(const string *author, const string *name, const int &countPage)//конструктор с параметрами
    {
        this -> author = *(author);
        this -> name = *(name);
        this -> countPage = countPage;
    }

    Book :: Book (const Book &otherBook)    ///конструктор копирования
    {
        this -> author = otherBook.author;
        this -> name = otherBook.name;
        this -> countPage = otherBook.countPage;
    }
    void Book :: print()   ///вывод всей информации о книге
    {   cout << "\nAuthor: " << author << "\nName: " << name << "\nCount of pages: " << countPage << endl;    }

    void Book :: setName(const string *name)    ///установка имя книги
    {   this -> name = *(name);  }

    void Book :: setAuthor(const string *author)    ///установка автора книги
    {   this -> author = *(author);  }

    void Book :: setCountPage(const int &countPage) ///установка числа страниц в книге
    {   this -> countPage = countPage;  }

    string Book :: getName()    ///взятие имени книги из объекта класса
    {
        return name;
    }

    string Book :: getAuthor()  ///взятие автора книги из объекта класса
    {
        return author;
    }

   int Book :: getCountPage()   ///взятие числа страниц из объекта класса
    {
        return countPage;
    }





    Book& Book :: operator = (const Book &book)//перегрузка оператора присваивания
    {
        this -> author = book.author;//присваивает поля текущему объекту из другого
        this -> name = book.name;
        this -> countPage = book.countPage;
        return *this;//при помощи указателя возвращает присвоенные поля объекту
    }

    bool Book :: operator == (const Book &book)//перегрузка оператора равно
    {
        return ((this -> name == book.name)&&(this -> author == book.author)&&(this -> countPage == book.countPage));//сравнивание объектов при помощи сравнения каждого поля
    }

    bool Book :: operator != (const Book &book)//перегрузка оператора не равно
    {
        return ((this -> name != book.name)&&(this -> author != book.author)&&(this -> countPage != book.countPage));//как и в операторе равно сравнение объектов при помощи сравнения каждого поля
    }

    bool Book :: operator > (const Book &book)//перегрузка оператора больше
    {
        if (this -> author > book.author)//приоритет отдал полю автора
        {
            return true;
        }
        else
            {
            if ((this -> author == book.author)&&(this -> name > book.name))//затем имя книги
            {
                return true;
            }
        else
            {
                if ((this -> author == book.author)&&(this -> name == book.name)&&(this -> countPage > book.countPage))//самый низкий приоритет у количества страниц
                    return true;
            }
        }
        return false;
    }

    bool Book :: operator < (const Book &book)//перегрузка оператора меньше схожа с оператором больше
    {
        if (this -> author < book.author)
        {
            return true;
        }
        else
            {
            if ((this -> author == book.author)&&(this -> name < book.name))
            {
                return true;
            }
        else
            {
                if ((this -> author == book.author)&&(this -> name == book.name)&&(this -> countPage < book.countPage))
                    return true;
            }
        }
        return false;
    }

    bool Book :: operator <= (const Book &book)//перегрузка оператора меньше либо равно
    {
        if (this -> author > book.author)//поочередное сравнение полей
        {
            return false;
        }
        else
            {
            if ((this -> author == book.author)&&(this -> name > book.name))
            {
                return false;
            }
        else
            {
                if ((this -> author == book.author)&&(this -> name == book.name)&&(this -> countPage > book.countPage))
                    return false;
            }
        }
        return true;
    }

    bool Book :: operator >= (const Book &book)//перегрузка оператора больше либо равно по тому же принципу
    {
        if (this -> author < book.author)
        {
            return false;
        }
        else
            {
            if ((this -> author == book.author)&&(this -> name < book.name))
            {
                return false;
            }
        else
            {
                if ((this -> author == book.author)&&(this -> name == book.name)&&(this -> countPage < book.countPage))
                    return false;
            }
        }
        return true;
    }

    ostream& operator << (ostream &out, const Book &book)//перегрузка оператора вывода
    {
        out << "Author:\t" << book.author << "\tName:\t" << book.name << "\tColor:\t" << book.countPage;
        return out;
    }

    istream& operator >> (istream &in, Book &book)//перегрузка оператора ввода
    {
        in >> book.author;
        in >> book.name;
        in >> book.countPage;
        return in;
    }

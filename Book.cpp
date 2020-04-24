/// � ���� ����� ����������� ��, ��������� � book.h
#include <iostream> ///���������� �����-������
#include "Book.h"   ///���� ������������ ������ �����
#include <string>   ///����������� �����
#include <cstring>  ///���������� ������� ���������� �� ��������

using namespace std;
    Book :: Book()  ///�����������
    {
        setCountPage(0);
    }
    Book :: Book(const string *author, const string *name, const int &countPage)//����������� � �����������
    {
        this -> author = *(author);
        this -> name = *(name);
        this -> countPage = countPage;
    }

    Book :: Book (const Book &otherBook)    ///����������� �����������
    {
        this -> author = otherBook.author;
        this -> name = otherBook.name;
        this -> countPage = otherBook.countPage;
    }
    void Book :: print()   ///����� ���� ���������� � �����
    {   cout << "\nAuthor: " << author << "\nName: " << name << "\nCount of pages: " << countPage << endl;    }

    void Book :: setName(const string *name)    ///��������� ��� �����
    {   this -> name = *(name);  }

    void Book :: setAuthor(const string *author)    ///��������� ������ �����
    {   this -> author = *(author);  }

    void Book :: setCountPage(const int &countPage) ///��������� ����� ������� � �����
    {   this -> countPage = countPage;  }

    string Book :: getName()    ///������ ����� ����� �� ������� ������
    {
        return name;
    }

    string Book :: getAuthor()  ///������ ������ ����� �� ������� ������
    {
        return author;
    }

   int Book :: getCountPage()   ///������ ����� ������� �� ������� ������
    {
        return countPage;
    }





    Book& Book :: operator = (const Book &book)//���������� ��������� ������������
    {
        this -> author = book.author;//����������� ���� �������� ������� �� �������
        this -> name = book.name;
        this -> countPage = book.countPage;
        return *this;//��� ������ ��������� ���������� ����������� ���� �������
    }

    bool Book :: operator == (const Book &book)//���������� ��������� �����
    {
        return ((this -> name == book.name)&&(this -> author == book.author)&&(this -> countPage == book.countPage));//����������� �������� ��� ������ ��������� ������� ����
    }

    bool Book :: operator != (const Book &book)//���������� ��������� �� �����
    {
        return ((this -> name != book.name)&&(this -> author != book.author)&&(this -> countPage != book.countPage));//��� � � ��������� ����� ��������� �������� ��� ������ ��������� ������� ����
    }

    bool Book :: operator > (const Book &book)//���������� ��������� ������
    {
        if (this -> author > book.author)//��������� ����� ���� ������
        {
            return true;
        }
        else
            {
            if ((this -> author == book.author)&&(this -> name > book.name))//����� ��� �����
            {
                return true;
            }
        else
            {
                if ((this -> author == book.author)&&(this -> name == book.name)&&(this -> countPage > book.countPage))//����� ������ ��������� � ���������� �������
                    return true;
            }
        }
        return false;
    }

    bool Book :: operator < (const Book &book)//���������� ��������� ������ ����� � ���������� ������
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

    bool Book :: operator <= (const Book &book)//���������� ��������� ������ ���� �����
    {
        if (this -> author > book.author)//����������� ��������� �����
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

    bool Book :: operator >= (const Book &book)//���������� ��������� ������ ���� ����� �� ���� �� ��������
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

    ostream& operator << (ostream &out, const Book &book)//���������� ��������� ������
    {
        out << "Author:\t" << book.author << "\tName:\t" << book.name << "\tColor:\t" << book.countPage;
        return out;
    }

    istream& operator >> (istream &in, Book &book)//���������� ��������� �����
    {
        in >> book.author;
        in >> book.name;
        in >> book.countPage;
        return in;
    }

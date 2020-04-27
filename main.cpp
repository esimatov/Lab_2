#include <iostream>
#include "Book.h"
#include <string>
#include <stdlib.h>


using namespace std;


void Interface()
{
    cout << "Control keys:" << endl;
    cout << "Setting fields: 1-To set the title of the book; 2-To set the author of the book; 3-To set the count page of the book" << endl;
    cout << "Getting fields: 4-To get the title of the book; 5-To get the author of the book; 6-To get the count page of the book" << endl;
    cout << "Actions with the book:" << endl;
    cout << "7-To show all book's fields; 8-To copy book; 9-To delete book; " << endl;
}

void showAllBooks(short countOfBook, Book *Books)
{
    for (short i = 0; i < countOfBook; i++)
    {
        cout << i+1 << ")";
        Books[i].print();
    }
}

int main()
{
    string tmpName, tmpAuthor;
    short var = 0, countOfBook = 1, y = 0, addcount = 0;
    int tmpCountPage = 0, i;
    Book *Books = new Book[1], *tmpBooks;
    while (1)
    {
        for (short x = countOfBook-1; x > 0; --x)
        {
            for (i = x-1; i >= 0; --i)
            {
                if (Books[i] > Books[i+1])
                {
                    Book tmp(Books[i]);
                    Books[i] = Books[i+1];
                    Books[i+1] = tmp;
                }
            }
        }
        cout << "\nSelect book or close program(input 0)\n" << endl;
        showAllBooks(countOfBook, Books);
        cin >> i;
        if (i == 0)
        {
            delete Books;
            return 0;
        }
        Interface();


        while (i != 0)
        {
            cin >> var;
            switch (var)
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    cout << "\nEntry name of book:" << endl;
                    cin >> tmpName;
                    Books[i-1].setName(&tmpName);
                    break;
                case 2:
                    cout << "\nEntry author of this book:" << endl;
                    cin >> tmpAuthor;
                    Books[i-1].setAuthor(&tmpAuthor);
                    break;
                case 3:
                    cout << "\nEntry count of page of this book:" << endl;
                    cin >> tmpCountPage;
                    if (tmpCountPage >= 0)
                    {
                        Books[i-1].setCountPage(tmpCountPage);
                    }else{
                        cout << "\nUncorrect count of page input. Cancel." << endl;
                        }//неприсваивание нового значения числа страниц при отрицательном аргументе
                    break;
                case 4:
                    cout << "\nTaken book's name:\t" << (tmpName = Books[i-1].getName()) << endl;
                    break;
                case 5:
                    cout << "\nTaken book's author:\t" << (tmpAuthor = Books[i-1].getAuthor()) << endl;
                    break;
                case 6:
                    cout << "\nTaken count of pages:\t" << (tmpCountPage = Books[i-1].getCountPage()) << endl;
                    break;
                case 7:
                    cout << Books[i-1];
                    break;
                case 8:{
                    countOfBook++;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook-1; y++)
                    {
                        tmpBooks[y] = Books[y];
                        delete &(Books[y]);
                    }
                    delete Books;
                    Books = tmpBooks;
                    Book newBook(Books[i-1]);
                    Books[countOfBook-1] = newBook;
                    break;}
                case 9:{
                    Books[i-1] = Books[countOfBook-1];
                    delete &(Books[countOfBook-1]);
                    countOfBook --;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook; y++)
                    {
                        tmpBooks[y] = Books[y];
                        delete &(Books[y]);
                    }
                    delete Books;
                    Books = tmpBooks;
                    i = 0;
                    break;}
                case 10:{
                    while (addcount < 1)
                    {
                        cout << "How many book add?" << endl;
                        cin >> addcount;
                    }
                    countOfBook += addcount;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook-addcount; y++)
                    {
                        tmpBooks[y] = Books[y];
                    }
                    delete [] Books;
                    Books = tmpBooks;
                    for (; y < countOfBook; y++)
                    {
                        cout << "Entry book's author, name and count of page:" << endl;
                        Book newBook;
                        cin >> newBook;
                        Books[y] = newBook;
                    }
                }

            }
        }
    }
}

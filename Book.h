///� ���� ����� ������������� ��� ���� ������ � ������� ��� ������ � �������, � ��� �� ������������ � ����������
#include <string>

using namespace std;
class Book
{
private:
    string author;
    string name;
    int countPage;
public:
    Book();
    Book(const string *author, const string *name, const int &countPage);
    Book(const Book &book);
    void print();
    void setName(const string *name);
    void setAuthor(const string *author);
    void setCountPage(const int &countPage);
    string getName();
    string getAuthor();
    int getCountPage();
//���������� ���������, ������� ���� ������
    Book& operator = (const Book &book);
    bool operator == (const Book &book);
    bool operator != (const Book &book);
    bool operator > (const Book &book);
    bool operator < (const Book &book);
    bool operator <= (const Book &book);
    bool operator >= (const Book &book);
    friend ostream& operator << (ostream &out, const Book &book);
    friend istream& operator >> (istream &in, Book &book);
};

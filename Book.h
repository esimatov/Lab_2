///в этом файле перечислаются все поля класса и функции для работы с классом, а так же коснтрукторы и деструктор
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
    Book(const string &author, const string &name, const int &countPage);
    Book(const Book &book);
    void print() const;
    void setName(const string &name);
    void setAuthor(const string &author);
    void setCountPage(const int &countPage);
    const string& getName()const;
    const string& getAuthor()const;
    const int getCountPage()const;

    Book& operator = (const Book &book);
    const bool operator == (const Book &book);
    const bool operator != (const Book &book);
    const bool operator > (const Book &book);
    const bool operator < (const Book &book);
    const bool operator <= (const Book &book);
    const bool operator >= (const Book &book);
    friend ostream& operator << (ostream &out, const Book &book);
    friend istream& operator >> (istream &in, Book &book);
};

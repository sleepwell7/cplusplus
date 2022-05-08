#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


class bookInfo
{
private:
    /* data */
    struct bookstruct{
        string bookname;
        string bookchapters;
        string libraryname;
    };
    int count = 0;
    bookstruct scriptures[500];

    void readlibrary(){
        ifstream booklist("books_and_chapters.txt");
        if (booklist.is_open())
        {
            string book, chaptercount, library, lines;
            while (getline (booklist, lines)){
                stringstream ss(lines);
                getline(ss, book,','); 
                scriptures[count].bookname = book;
                getline(ss, chaptercount, ',');
                scriptures[count].bookchapters = chaptercount;
                getline(ss, library, ',');
                scriptures[count].libraryname = library;
                count++;
            }
        booklist.close();
        }
    }
public:
    void writeToLibrary(){
        string bookin, chaptersin, libraryin;
        cin.ignore(1,'\n');
        cout << "What is the name of the book that you would like to add? \n";
        getline (cin, bookin);
        cout << "How many chapters are in the Book? \n";
        getline (cin, chaptersin);
        cout << "Does this book belong to a Particular Library? \n";
        getline (cin, libraryin);
        fstream booklist;
        booklist.open("books_and_chapters.txt",ios::app);
        if (booklist.is_open())
        {
            string bookinput = '\n' + bookin + ',' + chaptersin + ',' + libraryin;
            booklist << bookinput;
        }
        booklist.close();
    }
    void printLibrary(){
        readlibrary();
        for (int i = 0; i < count; i++)
            {
               cout << "Book: " << scriptures[i].bookname << "    Chapters: " << scriptures[i].bookchapters << "    Library: " << scriptures[i].libraryname << endl;
            }   
    }
};


int main(){
    cout << "<----------------------------------------------->\n";
    cout << "        Welcome to your library recorder!\n";
    cout << "<----------------------------------------------->\n";
    int userinput = -1;
    bookInfo bi;
    while (userinput != 0)
    {
        cout << "\nPlease Select and Option:\n";
        cout << "1. List all books\n";
        cout << "2. Add a record to Library\n";
        cout << "0. Quit\n\n";
        cin >> userinput;

        if (userinput == 1)
        {
            bi.printLibrary();
        }else if (userinput == 2)
        {   
           bi.writeToLibrary();
        }else{
            cout << "\nGoodbye\n";
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

/* class for listing and appending to book list*/
class bookInfo
{
private:
    /* structure used for formating the book list */
    struct bookstruct{
        string bookname;
        string bookchapters;
        string libraryname;
    };

    int count = 0;
    bookstruct scriptures[500]; //call to create structure

    /* function to read the items in the list*/
    void readlibrary(){
        ifstream booklist("books_and_chapters.txt");// opens the list
        if (booklist.is_open())
        {
            string book, chaptercount, library, lines;
            /*iterate through the list and retrieve a single line at a time and then store it in the book structure*/
            while (getline (booklist, lines)){ 
                stringstream ss(lines);
                getline(ss, book,','); //separate lines by comma and store segment in variable
                scriptures[count].bookname = book; //set a structure item equal to variable
                getline(ss, chaptercount, ',');//separate lines by comma and store segment in variable
                scriptures[count].bookchapters = chaptercount; //set a structure item equal to variable
                getline(ss, library, ',');//separate lines by comma and store segment in variable
                scriptures[count].libraryname = library; //set a structure item equal to variable
                count++;
            }
        booklist.close();// close the file
        }
    }
public:
    /*Function to append a line from user input into the end of the file*/
    void writeToLibrary(){
        string bookin, chaptersin, libraryin;
        cin.ignore(1,'\n');//ignore new line characters in the cin queue
        cout << "What is the name of the book that you would like to add? \n"; //get user input
        getline (cin, bookin);  // set the variable equal to user input
        cout << "How many chapters are in the Book? \n"; //get user input
        getline (cin, chaptersin);// set the variable equal to user input
        cout << "Does this book belong to a Particular Library? \n"; //get user input
        getline (cin, libraryin);// set the variable equal to user input
        fstream booklist; //start file open process
        booklist.open("books_and_chapters.txt",ios::app); //open the file
        if (booklist.is_open()) //check if file is open
        {
            string bookinput = '\n' + bookin + ',' + chaptersin + ',' + libraryin; //condense variables into single input string and set that string equall to new variable
            booklist << bookinput; //append variable to file
        }
        booklist.close(); // close the list file
    }
    /*Function to call the read file function and iterate through the structure after it is created*/
    void printLibrary(){ 
        readlibrary(); // call the read file function
        for (int i = 0; i < count; i++) //Iterate through structure
            {
               cout << "Book: " << scriptures[i].bookname << "    Chapters: " << scriptures[i].bookchapters << "    Library: " << scriptures[i].libraryname << endl; // Print out structure items
            }   
    }
};

/*Main function to provide a menu, create class item, and call function for program usage*/
int main(){
    cout << "<----------------------------------------------->\n";
    cout << "        Welcome to your library recorder!\n";
    cout << "<----------------------------------------------->\n";
    int userinput = -1;
    bookInfo bi; //create class item 
    while (userinput != 0) // main menu content
    {
        cout << "\nPlease Select and Option:\n";
        cout << "1. List all books\n";
        cout << "2. Add a record to Library\n";
        cout << "0. Quit\n\n";
        cin >> userinput;
        /* provide logic for menu option and to call necessary class functions*/
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
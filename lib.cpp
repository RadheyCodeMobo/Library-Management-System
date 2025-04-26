#include <iostream>
#include <fstream>
using namespace std;

class Libtemplate
{
  string bookId, bookName, bookAuthor, search;
  fstream file;

public:
  void addBook();
  void displayBook();
  void selectBook();
} obj;

int main()
{
  char yourChoice;
  cout << ".................................\n";
  cout << "1- Display All Books\n";
  cout << "2- Select Book\n";
  cout << "3- Add Book(ADMIN)\n";
  cout << "4- Exit\n";
  cout << ".................................\n";

  cout << "Enter Your Choice: ";
  cin >> yourChoice;

  switch (yourChoice)
  {
  case '1':
    cin.ignore();
    obj.displayBook();
    break;
  case '2':
    cin.ignore();
    obj.selectBook();
    break;
  case '3':
    cin.ignore();
    obj.addBook();
    break;
  case '4':
    return 0;
    break;
  default:
    cout << "Invalid Choice...\n";
  }

  return 0;
}

void Libtemplate ::addBook()
{
  cout << "\nWrite Book ID: ";
  getline(cin, bookId);
  cout << "\nWrite Book Name: ";
  getline(cin, bookName);
  cout << "\nWrite Author Name: ";
  getline(cin, bookAuthor);

  file.open("bookData.txt", ios ::out | ios ::app);
  file << bookId << "*" << bookName << "*" << bookAuthor << endl;
  file.close();
}

void Libtemplate ::displayBook()
{
  file.open("bookData.txt", ios ::in);
  getline(file, bookId, '*');
  getline(file, bookName, '*');
  getline(file, bookAuthor, '\n');
  cout << "\n\n";
  cout << "\t\t Book ID \t\t\t Book Name \t\t\t Author's Name" << endl;

  while (!file.eof())
  {
    cout << "\t\t " << bookId << " \t\t\t " << bookName << " \t\t\t " << bookAuthor << endl;
  }
  file.close();
}

void Libtemplate ::selectBook()
{
  displayBook();
  cout << "Write Book ID: ";
  getline(cin, search);

  file.open("bookData.txt", ios ::in);
  getline(file, bookId, '*');
  getline(file, bookName, '*');
  getline(file, bookAuthor, '\n');

  cout << "\n\n";
  cout << "\t\t Book ID \t\t\t Book Name \t\t\t Author's Name" << endl;
  while (!file.eof())
  {
    if (search == bookId)
    {
      cout << "\t\t " << bookId << " \t\t\t " << bookName << " \t\t\t " << bookAuthor << endl;
      cout << "Book Selected Successfully...!";

      getline(file, bookId, '*');
      getline(file, bookName, '*');
      getline(file, bookAuthor, '\n');
    }

    file.close();
  }
}

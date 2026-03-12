#include <iostream>
using namespace std;

class LibraryItem{
public:
    virtual void display() = 0;
};

class Book : public LibraryItem{
private:
    string title;
    string author;
    int pages;

public:
    Book(){}
    Book(string t,string a,int p){
        title=t;
        author=a;
        pages=p;
    }

    string getTitle(){
        return title;
    }

    int getPages(){
        return pages;
    }

    void display(){
        cout<<"Book: "<<title<<" Author: "<<author<<" Pages: "<<pages<<endl;
    }
};

class Newspaper : public LibraryItem{
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(){}
    Newspaper(string n,string d,string e){
        name=n;
        date=d;
        edition=e;
    }

    string getName(){
        return name;
    }

    string getEdition(){
        return edition;
    }

    void display(){
        cout<<"Newspaper: "<<name<<" Date: "<<date<<" Edition: "<<edition<<endl;
    }
};

class Library{
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount=0;
    int newsCount=0;

public:
    void addBook(Book b){
        books[bookCount++]=b;
    }

    void addNewspaper(Newspaper n){
        newspapers[newsCount++]=n;
    }

    void displayCollection(){
        for(int i=0;i<bookCount;i++)
            books[i].display();
        for(int i=0;i<newsCount;i++)
            newspapers[i].display();
    }

    void sortBooksByPages(){
        for(int i=0;i<bookCount-1;i++)
            for(int j=i+1;j<bookCount;j++)
                if(books[i].getPages()>books[j].getPages()){
                    Book temp=books[i];
                    books[i]=books[j];
                    books[j]=temp;
                }
    }

    void sortNewspapersByEdition(){
        for(int i=0;i<newsCount-1;i++)
            for(int j=i+1;j<newsCount;j++)
                if(newspapers[i].getEdition()>newspapers[j].getEdition()){
                    Newspaper temp=newspapers[i];
                    newspapers[i]=newspapers[j];
                    newspapers[j]=temp;
                }
    }

    Book* searchBookByTitle(string t){
        for(int i=0;i<bookCount;i++)
            if(books[i].getTitle()==t)
                return &books[i];
        return NULL;
    }

    Newspaper* searchNewspaperByName(string n){
        for(int i=0;i<newsCount;i++)
            if(newspapers[i].getName()==n)
                return &newspapers[i];
        return NULL;
    }
};

int main(){

    Book book1("The Catcher in the Rye","J.D. Salinger",277);
    Book book2("To Kill a Mockingbird","Harper Lee",324);

    Newspaper newspaper1("Washington Post","2024-10-13","Morning Edition");
    Newspaper newspaper2("The Times","2024-10-12","Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout<<"Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout<<"\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook=library.searchBookByTitle("The Catcher in the Rye");
    if(foundBook){
        cout<<"\nFound Book:\n";
        foundBook->display();
    }else{
        cout<<"\nBook not found.\n";
    }

    Newspaper* foundNewspaper=library.searchNewspaperByName("The Times");
    if(foundNewspaper){
        cout<<"\nFound Newspaper:\n";
        foundNewspaper->display();
    }else{
        cout<<"\nNewspaper not found.\n";
    }

    return 0;
}
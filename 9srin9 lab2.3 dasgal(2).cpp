#include <iostream>
#include <string>
using namespace std;

//edit xiib
class Book {
protected:
    string title;
    string author;
private:
    double price;  // inkupsulytsi
public:
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    // price-iin setter/getter
    void setPrice(double p) { price = p; }
    double getPrice() { return price; }

    // Nomiin medeellig xewlex
    virtual void displayInfo() {
        cout << "Printed Book -> Title: " << title
             << ", Author: " << author
             << ", Price: $" << price << endl;
    }
};

// Ded class: EBook
class EBook : public Book {
private:
    double fileSize;   // MB
    string format;     // PDF, EPUB gex met
public:
    EBook(string t, string a, double p, double fSize, string fmt)
        : Book(t, a, p), fileSize(fSize), format(fmt) {}

    // displayInfo() argiig daxin todorxoilox
    void displayInfo() override {
        cout << "E-Book -> Title: " << title
             << ", Author: " << author
             << ", Price: $" << getPrice()
             << ", File Size: " << fileSize << "MB"
             << ", Format: " << format << endl;
    }
};

int main() {
    // Engiin xewlemel nom obect
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", 15.99);
    
    // Tsaxim nom obect
    EBook eb1("Digital Fortress", "Dan Brown", 9.99, 2.5, "PDF");

    cout << "--- Printed Book ---" << endl;
    b1.displayInfo();

    cout << "\n--- E-Book ---" << endl;
    eb1.displayInfo();

    return 0;
}


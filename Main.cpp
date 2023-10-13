#include "Library.h"
#include "User.h"
#include "Book.h"
#include "ComicBook.h"
#include "Periodical.h"
#include <iostream>
#include <stdexcept>


#pragma warning(disable : 4996)

int main() {
    try {

    Book myBook;
    myBook.setAuthorName("Ivan Ivanov");
    myBook.setCharacteristic(ROMANCE);
    myBook.setTitle("Kniga");
    myBook.setTargetAudience(TEENS);
    myBook.setDescription("Tva e lubovna kniga.");
    myBook.setType(POEM);
    myBook.setId(1);
    myBook.setPublisher("Ciela");
    myBook.setYear(2023);

    Periodical period;
    period.setTitle("Spiderman");
    period.setDescription("SpiderMan SpiderMan Does whatever a spider can!!!");
    period.setId(2);
    period.setVolume(1);
    period.setYear(1968);
    period.setPeriod(WEEKLY);

    ComicBook myComic;
    myComic.setAuthorName("Ivan Radostinov");
    myComic.setCharacteristic(SCIENCE_FICTION);
    myComic.Print::setTitle("SpidermanMan");
    myComic.setTargetAudience(TEENS);
    myComic.Print::setDescription("SpiderMan SpiderMan Does whatever a spider can!!!");
    myComic.setType(DRAMA);
    myComic.Print::setId(3);
    myComic.setPublisher("MARVEL");
    myComic.setVolume(1);
    myComic.Print::setYear(1968);
    myComic.setPeriod(WEEKLY);

    User me;
    me.setName("Ivan");
    me += period;
    me += myComic;
    me += myBook;
    me -= myBook;
    me -= period;

    User you;
    you.setName("Petar");

    Library myLibrary;
    myLibrary.addPrint(myBook);
    myLibrary.addPrint(period);
    myLibrary.addPrint(myComic);
    myLibrary.addUser(me);
    myLibrary.addUser(you);
    myLibrary.displayPrints();
    myLibrary.displayBorrowed(3);
    myLibrary.displayUsers();
    }
    catch (const char* erMessage) {
        std::cout << "Error: " << erMessage << std::endl;
    }
}
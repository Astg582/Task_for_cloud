
#include <QCoreApplication>
#include <QDebug>

class Book {
private:
    QString title;
    QString author;
    QString ISBN;

public:

    Book() : title(""), author(""), ISBN("") {}
    Book(const QString& title, const QString& author, const QString& ISBN)
        : title(title), author(author), ISBN(ISBN) {}


    void setTitle(const QString& newTitle) {
        title = newTitle;
    }

    void setAuthor(const QString& newAuthor) {
        author = newAuthor;
    }

    void setISBN(const QString& newISBN) {
        ISBN = newISBN;
    }


    QString getTitle() const {
        return title;
    }

    QString getAuthor() const {
        return author;
    }

    QString getISBN() const {
          return ISBN;
      }
  };




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

      Book myBook("The Great Gatsby", "F. Scott Fitzgerald", "978-3-16-148410-0");

      qDebug() << "Initial Book Details:";
         qDebug() << "Title:" << myBook.getTitle();
         qDebug() << "Author:" << myBook.getAuthor();
         qDebug() << "ISBN:" << myBook.getISBN();


         myBook.setTitle("To Kill a Mockingbird");
            myBook.setAuthor("Ernest Hemingway");
            myBook.setISBN("908-06-108-4");

            qDebug() << "\nUpdated Book Details:";
               qDebug() << "Title:" << myBook.getTitle();
               qDebug() << "Author:" << myBook.getAuthor();
               qDebug() << "ISBN:" << myBook.getISBN();

         return a.exec();
}

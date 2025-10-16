#include <iostream>
#include <string>
using namespace std;

namespace Library {
	namespace Catalog {
		class Book {
		private:
			string title;
			string ISBN;
			bool isAvailable;
			Library::Users::Member* borrower;
		public:
			// default constructor
			Book() {
				this->title = "Unknown Book";
				this->ISBN = "000-0-00-000000-0";
				this->isAvailable = true;
				borrower = nullptr;
			}
			
			// parameterised constructor
			Book(string title, string ISBN) {
				this->title = title;
				this->ISBN = ISBN;
				this->isAvailable = true;
				borrower = nullptr;
			}
			
			// inline checkAvailability
			inline bool checkAvailability() {
				return this->isAvailable;
			}
			
			friend void displayBookDetails(Library::Catalog::Book);
			friend void borrowBook(Library::Catalog::Book&, Library::Users::Member&);
		};
		
		void displayBookDetails(Library::Catalog::Book B) {
			bool bookAvailable = B.checkAvailability();
			cout << "Book ISBN: " << B.ISBN << endl;
			cout << "Book ISBN: " << B.ISBN << endl;
			if (bookAvailable) {
				cout << "Book status: Available" << endl;
			} else {
				cout << "Book status: Borrowed by " << (B.borrower)->name;
			}
		}
		
	}
	namespace Users {
		class Member {
		private:
			static int numberOfMembers = 0;
			string name;
			int borrowingLimit;
			int currentBooks = 0;
			Library::Catalog::Book* borrowedBooks;
		public:
			Member() {
				this->name = "Unknown Member";
				this->borrowingLimit = 5;
				this->borrowedBooks = new Library::catalog::Book[borrowingLimit];
				numberOfMembers++;
			}
			
			Member(string name, int borrowingLimit) {
				this->name = "Unknown Member";
				this->borrowingLimit = borrowingLimit;
				this->borrowedBooks = new Library::catalog::Book[borrowingLimit];
				numberOfMembers++;
			}
			
			~Member() {
				numberOfMembers--;
			}
			
			friend void displayBookDetails(Library::Catalog::Book);
			friend void borrowBook(Library::Catalog::Book&, Member&);
		};
		
		void borrowBook(Library::Catalog::Book& B, Library::Users::Member& M) {
			if (!B.checkAvailability()) {
				cout << "Sorry, the book is already borrowed." << endl;
				return;
			}
			
			if (M.borrowingLimit == M.currentBooks) {
				cout << "Sorry, the member cannot borrow more books." << endl;
				return;
			}
			
			B.borrower = &M;
			B.isAvailable = false;
			M.borrowedBooks[M.currentBooks++] = &B;
		}
		
	}
}

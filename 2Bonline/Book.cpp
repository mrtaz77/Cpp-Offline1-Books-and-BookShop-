/************Topics of Practice*************************/
/* => Dynamic Allocation of objects         		   */
/* => Constructor overloading		        		   */
/* => Copy constructor				        		   */
/* => Passing and returning objects from functions     */
/*******************************************************/

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Book{
	int isbn;
	char* title;
	double price;
	public:
		//Constructor functions
		Book(){//default constructor
		    cout<<"In the default constructor of Book"<<endl;
			isbn=-1;
			price=0.00;
			title=new char [strlen("No title")+1];
			strcpy(title,"No title");
		}

		Book(int isbn, char* title, int price){//constructor with arguments
			cout<<"In the parameterized constructor of Book "<<isbn<<endl;
			this->isbn=isbn;
			this->price=price;
			this->title=new char [strlen(title)+1];
			strcpy(this->title,title);
		}
		Book(const Book &book){//Copy constructor
		    cout<<"In the copy constructor of Book "<<book.isbn<<endl;
			isbn=book.isbn;
			price=book.price;
			title=new char [strlen(book.title)+1];
			strcpy(title,book.title);
		}

		//Destructor function
		~Book(){
		    cout<<"In the destructor of Book "<<isbn<<endl;
			delete [] title;
		}

		//Write the setter functions here
		void set_isbn(int isbn){this->isbn=isbn;}
		void set_price(double price){this->price=price;}
		void set_title(char *title)
		{
			this->title=new char [strlen(title)+1];
			strcpy(this->title,title);
		}


		//Write the getter functions here
		int get_isbn(){return isbn;}
		double get_price(){return price;}
		char*get_title(){return title;}


		//Service functions
		void print(){
			cout<<"ISBN: "<<get_isbn()<<", Title: "<<get_title()<<", Price: "<<get_price()<<endl;
		}

		int isTheSameBook(Book b){
			return(isbn==b.isbn);
		}

		Book generateNewEdition(int isbn, int price){
			return Book(isbn,this->title, price);
		}
		// Book &operator=(Book &book)
		// {
		// 	//cout<<"In Operator =\n";
		// 	isbn=book.isbn;
		// 	price=book.price;
		// 	title=new char [strlen(book.title)+1];
		// 	strcpy(title,book.title);
		// 	return *this;
		// }
};

int main(){
	//To do: Create a book object named b1 with the default constructor
	Book b1;
	//To do: Set the properties of b1 as follows: isbn=101, title="Teach yourself C++", price=230
	b1.set_isbn(101);
	b1.set_title((char*)"Teach yourself C++");
	b1.set_price(230);
	//To do: Print the details of b1
	b1.print();
	//To do: Create a book object named b2 with values initialized as- isbn=102, title="Teach Yourself Java", price=235
	Book b2(102,(char*)"Teach Yourself Java",235);
	//To do: Create a book object b3 and initialize with b2
	Book b3=b2;
	//To do: Check if b2 and b3 represent the same book. Print "Yes" or "No" based on the check result.
	if(b2.isTheSameBook(b3))cout<<"Yes\n";
	else cout<<"No\n";
	//To do: Change the title of b3 to "Teach Yourself Java in Thirty Days"
	b3.set_title((char*)"Teach Yourself Java in Thirty Days");
	//To do: Change the isbn of b3 to 103
	b3.set_isbn(103);
	//To do: Print the details of book b2 and b3
	b2.print();
	b3.print();
	//To do: Create a book b4 as a new edition of b3. Set the isbn and price of the new edition to 104 and 600, respectively
	Book b4=b3.generateNewEdition(104,600);
	b4.print();
	//To do: Create a Book pointer named bp1
	Book *bp1;
	//To do: Allocate a Book object to bp1 initialized as- isbn=104, title="C++ For Dummies", price=400
	bp1=new Book(104,(char*)"C++ For Dummies",400);
	//To do: Print the details of the book pointed by bp1
	bp1->print();
	//To do: Free the memory allocated to bp1
	delete bp1;
	//To do: Create a Book pointer named bl1 and allocate three book objects to it without any initialization
	Book *bl1;
	bl1=new Book [3];
	//To do: Set the properties of the three book objects pointed to by bl1 as follows:
	// <isbn=201, title=Compilers, price=340>,
	// <isbn=202, title=Operating Systems, price=450>,
	// <isbn=203, title=Data Communications, price=600>
	bl1[0].set_isbn(201);
	bl1[0].set_title((char*)"Compilers");
	bl1[0].set_price(340);
	bl1[1].set_isbn(202);
	bl1[1].set_title((char*)"Operating Systems");
	bl1[1].set_price(450);
	bl1[2].set_isbn(203);
	bl1[2].set_title((char*)"Data Communications");
	bl1[2].set_price(600);

	//To do: Print the details of all the three books pointed to by bl1
	for(int i=0;i<3;i++)bl1[i].print();
	//To do: Free the memory allocated to bl1
	delete [] bl1;
}
/*change*/ 

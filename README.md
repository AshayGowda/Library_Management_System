ABSTRACT

This code implements Library Management program in C in . The Data Structures used to do this is linked list. A linked-list is being used to store data whenever required.
The basic functionalities provided within the management system are:-
1> Display books in the library
2>Enter a new book into the library
3> Issue Books to student
4>List of list of issued books to student and the student information to which the book is issued
5> Return of the books by the student

DESCRIPTION OF DATA STRUCTURE, LOGIC AND FUNCTIONALITY 

Functionalities provided within the management system are:-
1)Structures :
We have defined two structures books and student
The book structure book name  , author name,  book version
The book structure student id  ,  students name,  department , semester ,book id
2)Linked lists : 
There are two linked lists in the program book and the student which has the data values specified in the structures.
3)Functions : 
There are 8 functions in the project
display_books()	
  function displays the books in the library
It traverses the linked list and displays the books in the library 	 	
	2.    create_new_book()
This function creates a node by malloc function and inserts the data entered by the user  to the created node
This holds information of the book entered which is mentioned above in the structure 
	3. enter_book() 
	This functions  first asks the user to enter the number of books he want to put I the library
This function uses the create_new_book() and inserts the node created ny it to the books linked list i.e the library
	4. create_new_student_entry() 
This function creates a node by malloc function and inserts the data entered by the user  to the created node
This holds information of the student entered which is mentioned above in the structure

	5. student_information()
This function uses the create_new_student_entry() and inserts the node created by it to the students linked list i.e the library

 6. issue_book()
This function uses the student_information() function to issue the book to the student and book_info() function to display the book’s information being issued to the student with the help of book id.
	7. book_info(int bookid)
This function is used by the issue_book() function to display the book’s information being issued to the student with the help of book id.

	8. return_books()
This function is used to return the book issued by the student back to the library
It deletes the record bookid in the linked list 	of student and also changes the list of books issued.
	8. display_book_details()
It is used to displays the book details such as book name  , author name,  book version of the issued books in the library and also displays the information of the student who issued the book.
It traverses the book linked list and student linked lists compares each id in  the book linked with each student’s  issued book id and displays in the format of  this book is issued to this student 

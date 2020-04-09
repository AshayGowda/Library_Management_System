#include<stdio.h>
#include<stdlib.h>
typedef struct book{
    int bookid;
    char* bookname[100];
    char* authname[100];
    float bookversion;
    struct book* next;
}b1;
typedef struct student{
    int studentid;
    char* studentname[100];
    char* dept[100];
    int sem;
    int bookid;
    struct student* next;
}s1;
b1* root;
s1* node;

void display_books();
void enter_book();
void display_book_details();
void issue_book();
void issued_book();
b1* create_new_book();
s1* create_new_student_entry();
s1* student_information();
void book_info(int bookid);
b1* return_books();
b1* delete_issued_books(int id);
int main()
{
    int d;
    while(1)
    {
        printf("        MAIN MENU       ");
        printf("\n");
        printf("(1) DISPLAY ALL BOOKS ");
        printf("\n");
        printf("(2) ENTER A NEW BOOK ");
        printf("\n");
        printf("(3) ISSUE A BOOK ");
        printf("\n");
        printf("(4) DISPLAY LIST OF  ISSUED BOOKS ");
        printf("\n");
        printf("(5) RETURN THE BOOKS ");
        printf("\n");
        printf("(5) EXIT ");
        printf("\n");
        printf("Please select Your option (1-6):");
        fflush(stdin);
        scanf("%d",&d);
        
        switch(d)
        {
            case 1:display_books();
                break;
            case 2:enter_book();
                break;
            case 3:issue_book();
                break;
            case 4:display_book_details();
                break;
            case 5:return_books();
                break;
            default : return 0;
        }
    }
}
void display_books()
{
    
    struct book*p;
    p=root;
    int i=0;
    if(p==NULL)
    {
        printf("No books\n");
    }
    while(p!=NULL)
    {
        i++;
        printf("\n");
        printf("\n");
        printf("Information related to book  number %d is...",i);
        printf("\n");
        printf("\n");
        printf("book id ->%d",p->bookid);
        printf("\n");
        printf("book name ->%s",p->bookname);
        printf("\n");
        printf("Author name -> %s",p->authname);
        printf("\n");
        printf("Version of the book -> %.2f",p->bookversion);
        printf("\n");
        printf("\n");
        p=p->next;
        printf("\n");
        printf("\n");
        // printf("\n");
    }
    
}

b1* create_new_book()
{
    fflush(stdin);
    b1* temp = NULL;
    temp =(b1*)malloc(sizeof(b1));
    printf("Enter  id of book :");
    scanf("%d",&(temp->bookid));
    printf("Enter the  name of book :");
    scanf("%s",&(temp->bookname));
    printf("Enter author name of book:");
    scanf("%s",&(temp->authname));
    printf("Enter version of the book :");
    scanf("%f",&(temp->bookversion));
    printf("\n");
    temp->next=NULL;
    printf("\n");
    return temp;
    printf("\n");
    printf("\n");
}
void enter_book()
{
    int i=0;
    int n;
    b1*temp=NULL;
    printf("How many books You wanted to enter?");
    scanf("%d",&n);
    b1* p = root;
    for (i = 0 ; i < n ; ++i){
        b1* temp = create_new_book();
        
        if (root == NULL){
            root = temp;
        }
        else{
            p = root;
            while (p->next != NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }
    
    return;
}

s1* create_new_student_entry(){
    fflush(stdin);
    s1* temp = (s1*)malloc(sizeof(s1));
    printf("Enter student ID:");
    fflush(stdin);
    scanf("%d",&(temp->studentid));
    printf("Enter student name:");
    fflush(stdin);
    scanf("%s",&(temp->studentname));
    printf("Enter student department:");
    fflush(stdin);
    scanf("%s",&(temp->dept));
    printf("Enter the current semester: ");
    fflush(stdin);
    scanf("%d",&(temp->sem));
    printf("Enter the book id of book you want?\n");
    fflush(stdin);
    scanf("%d",&(temp->bookid));
    temp->next=NULL;
    return temp;
}
s1* student_information()
{
    s1* temp = create_new_student_entry();
    s1* p = node;
    if (node == NULL){
        node = temp;
    }
    else{
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    
    return temp;
}
void issue_book()
{
    int i;
    s1*s=node;
    s1* inserted_node = student_information();
    book_info(inserted_node->bookid);
    
}
void book_info(int bookid_1)
{
    b1* p = root;
    
    while (p != NULL)
    {
        if (bookid_1==p->bookid)
        {
            printf("The details of the book you issued\n");
            
            printf("\n");
            printf("Book Found.....and issued\n");
            printf("\n");
            printf("Book name is %s",(p->bookname));
            printf("\n");
            printf("Author name is %s",(p->authname));
            printf("\n");
            printf("Updated Version of that book is %.2f",(p->bookversion));
            printf("\n");
            return;
        }
        p = p->next;
    }
    
    
    printf("book not found and not issued\n");
}

b1* return_books()
{
    int i , id;
    int n;
    printf("Enter the student id ");
    scanf("%d",&n);
    s1* p = node;
    b1*q = NULL;
    while (p != NULL && p->studentid!=n){
        p=p->next;
    }
    p->bookid=NULL;
    return 0;
}

void display_book_details()
{
    s1* s = node;
    b1* b = root;
    if(s->bookid==NULL)
    {
        printf("NO BOOKS ARE ISSUED");
        printf("\n");
    }
    else{
        
        while (s != NULL){
            b = root;
            printf("The list of the books issued are...");
            while (b != NULL){
                if (b->bookid == s->bookid){
                    printf("\n");
                    printf("Book id %d",(root->bookid));
                    printf("\n");
                    printf("Book name is %s",(root->bookname));
                    printf("\n");
                    printf("Author name is %s",(root->authname));
                    printf("\n");
                    printf("Updated Version of that book is %.2f",(root->bookversion));
                    printf("\n\n");
                    printf("Is issued to...");
                    printf("\n");
                    printf("\n");
                    printf("Student id %d",(node->studentid));
                    printf("\n");
                    printf("Student name %s",(node->studentname));
                    printf("\n");
                    printf("Student department is %s",(node->dept));
                    printf("\n");
                    printf("Student current semester is %d",(node->sem));
                    printf("\n");
                }
                b = b->next;
            }
            s = s->next;
        }
    }
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>

typedef char string[50] ;
typedef enum { AVAILABLE = 1, BORROWED = 0 }bookstatus;   
typedef struct {string title ; string author ; bookstatus status ; } book ;
book shelf[10] = {{"Ratburger" , "David Walliams" , AVAILABLE }, {"The new anotated Dracula" , "Bram Stoker" , AVAILABLE},{"Don Quixote" ,"Miguel de Cervantes" , AVAILABLE}, {"Alice's Adventures in Wonderland", "Lewis Carroll", AVAILABLE}, {"The Adventures of Huckleberry Finn", "Mark Twain", AVAILABLE}, {"Jane Eyre", "Charlotte Brontë", AVAILABLE}, {"A Tale of Two Cities", " Charles Dickens", AVAILABLE}, {"The Lord of the Rings", "John Ronald", AVAILABLE}, {"1984", " George Orwel", AVAILABLE}, {"Little Women","Louisa May Alcot", AVAILABLE}};
bool still_available = true ;
int left_books = 10 ;

bool update_bookstatus(book arr[]);

int main(void){
    
    int k = 0 ;
    while (still_available){
        update_bookstatus(shelf);
        printf("\nRefreshing library...\n");
        sleep(5);
    }
    printf("\nThere are no book available right now.Please try another time.\n");
    return 0 ;
}

bool update_bookstatus(book arr[]){
    
    int i , d = 0 ;
    int found = 0 ;
    string name ;

    system("clear");
    for (d = 0 ; d < 10 ;d++ ){
        printf("%s by %s\n", shelf[d].title , shelf[d].author);
    }
    printf("\nEnter the title of the book you want:");
    
    fgets(name , sizeof(name), stdin);
    name[strcspn(name, "\n" )] = '\0';
    for (i = 0 ; i < 10 ;i++ ){
        if (strcasecmp(name , arr[i].title) == 0){
            found = 1 ;
            if (arr[i].status == BORROWED ){
                printf("\nThis book has already borrowed.Try another one\n");
            }
            else {
                arr[i].status = BORROWED ;
                left_books-- ;
                printf("\nHere’s your book. Please return it by the due date.\n");
            }
        break ;
        }        
    }
    if (found != 1){
        printf("\nSorry , this book is not here.\n");
    }
    if (left_books == 0){
        return still_available = false ;
        
    } 
    return still_available = true;

}
#include <stdio.h>

struct Inventory {
    int id;
    char name[50];
    char category[50];
    int quantity;
    char location[50];
    char status[50]; // bisa juga int, misal 0 untuk tersedia, 1 untuk habis, dll
};

int main(){
    printf("Hello World\n");
    printf("Tubes pmp keren\n");
    return 0;
}
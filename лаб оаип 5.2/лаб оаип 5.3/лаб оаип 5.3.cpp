#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#pragma warning(disable : 4996)

#define SIZE 10


typedef struct {
    char brand[20]; 
    int max_speed; 
    int year; 
} Car;


int hash(char brand[]) {
    
    int sum = 0;
    for (int i = 0; i < strlen(brand); i++) {
        sum += (int)brand[i];
    }
    return sum % SIZE;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Car cars[6] = { 
        {"BMW", 250, 2018},
        {"Audi", 240, 2019},
        {"Mercedes", 260, 2017},
        {"Toyota", 200, 2015},
        {"Honda", 190, 2014},
        {"Volkswagen", 230, 2016}
    };
    
    Car hashtable[SIZE]; 

  
    for (int i = 0; i < SIZE; i++) {
        strcpy(hashtable[i].brand, "");
        hashtable[i].max_speed = -1;
        hashtable[i].year = -1;
    }
    for (int i = 0; i < 6; i++) {
        int index = hash(cars[i].brand);
        while (strcmp(hashtable[index].brand, "") != 0) {
            index++;
            index %= SIZE;
        }
        strcpy(hashtable[index].brand, cars[i].brand);
        hashtable[index].max_speed = cars[i].max_speed;
        hashtable[index].year = cars[i].year;
    }

  
    char search_key[20];
    printf("Введите марку автомобиля для поиска: ");
    scanf("%s", search_key);
    int search_index = hash(search_key);
    while (strcmp(hashtable[search_index].brand, search_key) != 0) {
        search_index++;
        search_index %= SIZE;
        if (strcmp(hashtable[search_index].brand, "") == 0) {
            printf("Автомобиль не найден\n");
            return 0;
        }
    }


    printf("Исходный массив:\n");
    for (int i = 0; i < 6; i++) {
        printf("%s %d %d\n", cars[i].brand, cars[i].max_speed, cars[i].year);
    }
    printf("Хеш-таблица:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s %d %d\n", hashtable[i].brand, hashtable[i].max_speed, hashtable[i].year);
    }
    printf("Найденный автомобиль:\n");
    printf("%s %d %d\n", hashtable[search_index].brand, hashtable[search_index].max_speed, hashtable[search_index].year);

    return 0;
}
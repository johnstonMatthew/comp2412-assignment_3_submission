#include "HashTable.h"

int main() {
    HashTable hashTable = HashTable(8);

    hashTable.Insert("Toyota", 300);
    hashTable.Insert("Ford", 450);
    hashTable.Insert("BMW", 400);
    hashTable.Insert("Honda", 280);
    hashTable.Insert("Chevrolet", 500);
    hashTable.Insert("Tesla", 670);
    hashTable.Insert("Porsche", 620);
    hashTable.Insert("Lamborghini", 770);
    hashTable.Insert("Ferrari", 800);
    hashTable.Insert("McLaren", 750);
    hashTable.Insert("Bugatti", 1500);
    hashTable.Insert("AstonMartin", 630);
    hashTable.Display();
}
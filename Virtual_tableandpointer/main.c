#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*speak)();
    void (*move)();
}AnimalVTable;

// base animal
typedef struct {
    AnimalVTable* vtable;
    char * name;
}Animal;

// dog
typedef struct {
    Animal base;
    char* breed;
}Dog;

//virtual functions
void animal_speak(){
    printf("The animal makes sound...\n");
}

void animal_move(){
    printf("The animal moves...\n");
}
void dog_speak(){
    printf("The dog barks...\n");
}

void dog_move(){
    printf("The dog runs...\n");
}

// virtual tables for animal and dogs

AnimalVTable animal_vtable = {animal_speak, animal_move};
AnimalVTable dog_vtable = {dog_speak, dog_move};

// Initialize a dog with given name and breed
void animal_init(Animal *animal, char* name){
    animal->vtable = &animal_vtable;
    animal->name = name;
}

void dog_init(Dog *dog, char* name, char* breed){
    animal_init((Animal*)dog, name);
    dog->base.vtable = &dog_vtable;
    dog->breed = breed;
}

//call the speak and move functions for an animal

void animal_do_actions(Animal * animal){
    animal->vtable->speak();
    animal->vtable->move();
}


int main()
{
    // create an animal and a dog
    Animal animal;
    animal_init(&animal, "Generic animal");
    Dog dog;
    dog_init(&dog,"Fido","Labrador");

    // call the virtual functions for the animal and the dog
    printf("%s", animal.name);
    animal_do_actions(&animal);

    printf("%s (%s)", dog.base.name, dog.breed );
    animal_do_actions((Animal*)&dog);
    return 0;



}

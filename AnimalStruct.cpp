
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct Animal
{
   string name;
   Animal *leftAnimal;
   Animal *rightAnimal;
};

bool ask( string question );

void init( Animal *&animal );

void play( Animal *&animal );

int main( )
{

   Animal *root;
   init( root );

   bool answer = true;
   while ( answer == true )
   {
      cout << "Welcome to the program" << endl;
      play( root );
      answer = ask( "Do you want to run again?" );
   }

   return EXIT_SUCCESS;

}

bool ask( string question )
{
   string answer;
   do
   {
      cout << question << " [yes or no]" << endl;
      cin >> answer;
   } while ((answer != "yes") && (answer != "no"));

   //return answer == "yes";

   if ( answer == "yes" )
   {
      return true;
   } else
   {
      return false;
   }
}

void init( Animal *&animal )
{
   animal = new Animal;
   animal->name = "gonchaya";
   animal->leftAnimal = 0;
   animal->rightAnimal = 0;
}

void play( Animal *&startAnimal )
{
   Animal *currentAnimal = startAnimal;

   while ( currentAnimal != 0 )
   {
      bool answer = ask( "Is this " + currentAnimal->name + "?" );
      if ( answer == true )
      {
         if ( currentAnimal->rightAnimal == 0 )
         {
            cout << "I am correct!" << endl;
            return;
         } else
         {
            currentAnimal = currentAnimal->rightAnimal;
         }
      } else
      {
         if ( currentAnimal->leftAnimal == 0 )
         {
            cout << "I am wrong!" << endl;

            //Например форель
            Animal *newAnimal = new Animal;
            newAnimal->leftAnimal = 0;
            newAnimal->rightAnimal = 0;
            cout << "Input new animal:";
            cin >> newAnimal->name;

            //Например рыба. currentAnimal - гончая
            Animal *newAnimalType = new Animal;
            newAnimalType->leftAnimal = currentAnimal;
            newAnimalType->rightAnimal = newAnimal;
            cout << "Input correct answer. Is this:";
            cin >> newAnimalType->name;

            if ( startAnimal == currentAnimal )
            {
               //первый запуск
               startAnimal = newAnimalType;
            } else
            {
               currentAnimal->leftAnimal = newAnimalType;
            }

            return;
         } else
         {
            currentAnimal = currentAnimal->leftAnimal;
         }
      }
   }

}


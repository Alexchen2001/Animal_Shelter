//
// Alexander Chen SU ID #: 4186272
// .cpp
// CPSC 2430 - 01 Assignment 1
// Completed on 10/10/2022

// Purpose: An animal shelter that adds cat/dogs into the shelter and allows the
//people to adopt the oldest cat//dog in the shelter. Utilizing vectors as a storing
// of animals, and using conditionals to perform needed operations.


#include "management.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string user_prompt(){

    int user_task; // Initiate to store values that matches the user's purpose
    string user_adoption_request; // place to store user choice of category
    string animal_name;         //place to store animal name given to put in shelter
    string user_animal_type;    // place to store animal category for adding into shelter
    string output_animal;       // place to store output msg.
    string user_completion_primary; // store input/output of choice of exiting animal shelter
    string user_completion_secondary; //place to store input/output of exiting request of adopting/adding.

    cout << "                       Welcome to the Animal Shelter !               " << "\n";
    cout << "       Animals that you could put in or pick from the shelter are dogs and cats ONLY."<< "\n";
    cout << " You will only be allowed to adopt the desired animal that are most tenured in the shelter !!! << \n";

    cout << endl;
    cout << endl;

    cout << " If we want to make an adoption type the number 1  -> adopt " << "\n";
    cout << " If we ant to send an animal in the shelter type 0 -> foster " << "\n";
    cout << " Enter 1 to adopt animals or enter 0 to foster/add animals !" << "\n";
    cout << endl;

    // until user chooses to exit, it would continue to loop
    while (user_completion_primary != "d"){
        user_completion_secondary = "continue";

        cout << " What are we doing today (adopt: 1/foster: 0) : ";
        cin >> user_task;
        cout << endl;

        // 1 would be to adopt animal 0 to add animal to shelter
        if (user_task == 1){
            //loops until user wants to exit
            while(user_completion_secondary != "e"){
                cout << " Please enter your desired category of Animal (cat/dog/any): ";
                cin >> user_adoption_request;
                cout << endl;

                // retrieving animal infor from management system and storing it
                output_animal = get_Animal_info(user_adoption_request);
                cout << output_animal;
                cout << endl;
                cout << endl;

                // exiting prompt
                cout << " Enter -> yes <- to continue";
                cout << endl;
                cout << " Do you want to continue to adopt animals (enter -> e <-to exit) ";
                cin >> user_completion_secondary;
                cout << endl;
            }

        }else if(user_task == 0){
            //loops until users choose to opt out of adding animal
            while(user_completion_secondary != "e"){

                //storing animal info and adding animals into shelter through functions from management system
                cout << " Please enter the type of the animal(cat/dog): ";
                cin >> user_animal_type;
                cout << endl;


                cout << " Please enter the name of the animal: " ;
                cin >> animal_name;
                cout << endl;

                add_animal(user_animal_type,animal_name);

                // exiting prompt
                cout << " Enter -> yes <- to continue";
                cout << endl;
                cout << " Do you want to continue to shelter animals (enter -> e <-to exit) ";
                cin >> user_completion_secondary;
                cout << endl;
            }
        }

        // Checking whether if user wanted to continue to do tasks in shelter
        cout << " Enter -> No <- to continue";
        cout << endl;
        cout << "Are we done with all agendas (input  .> d <- to finish) : ";
        cin >> user_completion_primary;
        cout << endl;

    }
    //Goodbye message to user
    cout << " Thank you for coming to the animal shelter!" << "\n";
    cout << " See you next time !";


}

int main(){

    user_prompt();

    return 0;
}

//
// Created by Alex Chen on 10/7/22.
//


#include "management.h"
#include <vector>
#include <string>

using namespace std;

vector<Animal> animal_shelter_listing; // Animal storing vector initiation

vector<Animal> add_animal(string animal_category, string name_incoming){
    Animal new_animal; // Initiate to store incoming animal object

    // adjusting the case-sensitive issue of category, lowercasing all category input
    for(int i = 0; i < animal_category.length(); i++){
        animal_category[i] = tolower(animal_category[i]);
    }

    // storing respective info into object
    new_animal.category = animal_category;
    new_animal.name = name_incoming;

    // adds into vector and returns the new vector
    animal_shelter_listing.push_back(new_animal);
    return animal_shelter_listing;

}

string get_Animal_info(string adoption_request){

    // Initiation storage for respective inputs/outputs/ objects
    Animal target_animal;
    string output_msg;
    string error_msg;

    // Implemented to not encounter towards case-sensitive issues from user
    for(int i = 0; i < adoption_request.length(); i++){
        adoption_request[i] = tolower(adoption_request[i]);
    }

    /*
     Matches adoption request then checks the size of vector increments to find the matching category
    goes through the whole vector, if no matching animal found outputs a error message. any category will
     output the first animal in the shelter
     */

    // base case for empty vector
    if(animal_shelter_listing.empty()){
        error_msg = " There is no dog/cat currently in the shelter !";
        return error_msg;

    } else if(adoption_request == "cat"){
        for(int i = 0; i< animal_shelter_listing.size();i++){
            if( animal_shelter_listing.at(i).category == "cat" ){
                target_animal = animal_shelter_listing.at(i);
                animal_shelter_listing.erase(animal_shelter_listing.begin()+ i);
                output_msg = " The Animal for you is : Category: " + target_animal.category + " Name: " + target_animal.name;
                return output_msg;
            }else if (i == animal_shelter_listing.size()-1){
                error_msg = "No cats are available at the shelter !" ;
                return error_msg;
            }
        }
    } else if( adoption_request == "dog"){
        for(int i = 0; i< animal_shelter_listing.size();i++){
            if( animal_shelter_listing.at(i).category == "dog" ){
                target_animal = animal_shelter_listing.at(i);
                animal_shelter_listing.erase(animal_shelter_listing.begin()+i);
                output_msg = " The Animal for you is : Category: " + target_animal.category + " Name: " + target_animal.name;
                return output_msg;

            } else if (i == animal_shelter_listing.size()-1){
                error_msg = " No dogs are available at the shelter !";
                return error_msg;
            }
        }

    } else if( adoption_request == "any"){
        target_animal = animal_shelter_listing.at(0);
        animal_shelter_listing.erase(animal_shelter_listing.begin());
        output_msg = " The Animal for you is : Category: " + target_animal.category + " Name: " + target_animal.name;
        return output_msg;
    } else{
        error_msg = " Animal chosen not available at the facility today !";
        return error_msg;

    }
}



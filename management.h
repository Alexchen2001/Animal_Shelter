//
// Created by Alex Chen on 10/7/22.
//

#ifndef ANIMAL_SHELTER_MANAGEMENT_H
#define ANIMAL_SHELTER_MANAGEMENT_H
#include <string>
#include <vector>
using namespace std;


class Animal {
    public:
    string category;
    string name;;

};

vector<Animal> add_animal(string animal_category, string name_incoming);

string get_Animal_info(string adoption_request);

#endif //ANIMAL_SHELTER_MANAGEMENT_H

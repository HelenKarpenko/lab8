#include "PlanetStorage.h"

#include <FileProcessing.h>

PlanetStorage::PlanetStorage(const string &filePath) {
    this->planets = new map<int,Planet*>();
    this->planets = parse_planets(filePath);
}

PlanetStorage::~PlanetStorage(){
}
map<int, Planet*> *PlanetStorage::parse_planets(const string &filePath){
    FileProcessing f;
    string jsonStr = f.read(filePath);
    json_error_t err;
    json_t *listOfPlanetObj = json_loads(jsonStr.c_str(), 0, &err);
    int id = 1;
    json_t *planetObj = NULL;
    int index = 0;
    json_array_foreach(listOfPlanetObj, index, planetObj){
        Planet *p = parse_planet(planetObj, id);
        (*planets)[id] = p;
        id++;
    }
    json_decref(listOfPlanetObj);
    return planets;
}
Planet * PlanetStorage::parse_planet(json_t *planetObj, int id) {
    string name = json_string_value(json_object_get(planetObj, "name"));
    int rotation_period = atoi(json_string_value(json_object_get(planetObj, "rotation_period")));
    int diameter = atoi(json_string_value(json_object_get(planetObj, "diameter")));
    string climate = json_string_value(json_object_get(planetObj, "climate"));
    string gravity = json_string_value(json_object_get(planetObj, "gravity"));
    string terrain = json_string_value(json_object_get(planetObj, "terrain"));
    int population = atoi(json_string_value(json_object_get(planetObj, "population")));
    Planet *p = new Planet(name, id, rotation_period, diameter, climate, gravity, terrain, population);
    return p;
}

string PlanetStorage::getAllPlanets(){
    json_t *jsonArr = json_array();
    for (auto it = planets->begin(); it != planets->end(); it++) {
        Planet *p = it->second;
        json_array_append_new(jsonArr, p->getJson());
    }
    char *jsonString = json_dumps(jsonArr, JSON_INDENT(2));

    json_decref(jsonArr);
    if(jsonString) {
        string jstr(jsonString);
        free(jsonString);
        return jstr;
    }else{
        return "[]";
    }
}

string PlanetStorage::findPlanetsRotationPeriod(string key){
    int rotation_period = atoi(key.c_str());
    if(rotation_period != 0) {
        json_t *jsonArr = json_array();
        for (auto it = planets->begin(); it != planets->end(); it++) {
            Planet *p = it->second;
            if (p->getRotation_period() == rotation_period) {
                json_array_append_new(jsonArr, p->getJson());
            }
        }
        char *jsonString = json_dumps(jsonArr, JSON_INDENT(2));

        json_decref(jsonArr);
        if (jsonString) {
            string jstr(jsonString);
            free(jsonString);
            return jstr;
        } else {
            return "[]";
        }
    }
    return "";
}

string PlanetStorage::findPlanet(string key) {
    int id = atoi(key.c_str());
    if(id > 0 && id < planets->size()) {
        Planet *p = planets->find(id)->second;
        char *jsonString = json_dumps(p->getJson(), JSON_INDENT(2));
        if (jsonString) {
            string jstr(jsonString);
            delete jsonString;
            return jstr;
        } else {
            return "[]";
        }
    }
    return "";
}
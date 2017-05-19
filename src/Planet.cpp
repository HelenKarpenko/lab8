#include <Planet.h>

Planet::Planet(string name,
               int id,
               int rotation_period,
               int diameter,
               string climate,
               string gravity,
               string terrain,
               int population){
    this->json = json_object();
    setName(name);
    setId(id);
    setRotation_period(rotation_period);
    setDiameter(diameter);
    setClimate(climate);
    setGravity(gravity);
    setTerrain(terrain);
    setPopulation(population);
}
Planet::~Planet(){
    cout << "Planet is destoyed!" << endl;
}

const string &Planet::getName() const {
    return name;
}
int Planet::getId() const {
    return id;
}
int Planet::getRotation_period() const {
    return rotation_period;
}
int Planet::getDiameter() const {
    return diameter;
}
const string &Planet::getClimate() const {
    return temperate;
}
const string &Planet::getGravity() const {
    return gravity;
}
const string &Planet::getTerrain() const {
    return terrain;
}
int Planet::getPopulation() const {
    return population;
}
json_t *Planet::getJson() const {
    auto jclone = json_copy(json);
    return jclone;
}

void Planet::setName(const string &name) {
    auto jrm = json_object_get(json, "name");
    if (!json_is_null(jrm))
        json_decref(jrm);
    json_object_set_new(json,"name",json_string(name.c_str()));
    Planet::name = name;
}
void Planet::setId(int id) {
    if(id <= 0) id = 1;
    auto jrm = json_object_get(json, "id");
    if (!json_is_null(jrm))
        json_decref(jrm);
    json_object_set_new(json, "id", json_integer(id));
    this->id = id;
}
void Planet::setRotation_period(int rotation_period) {
    if(rotation_period >= 0) {
        auto jrm = json_object_get(json, "rotation_period");
        if (!json_is_null(jrm))
            json_decref(jrm);
        json_object_set_new(json, "rotation_period", json_integer(rotation_period));
        this->rotation_period = rotation_period;
    }
}
void Planet::setDiameter(int diameter) {
    if(diameter >= 0) {
        auto jrm = json_object_get(json, "diameter");
        if (!json_is_null(jrm))
            json_decref(jrm);
        json_object_set_new(json, "diameter", json_integer(diameter));
        this->diameter = diameter;
    }
}
void Planet::setClimate(const string &clomate) {
    auto jrm = json_object_get(json, "climate");
    if (!json_is_null(jrm))
        json_decref(jrm);
    json_object_set_new(json,"climate",json_string(clomate.c_str()));
    this->name = name;
}
void Planet::setGravity(const string &gravity) {
    auto jrm = json_object_get(json, "gravity");
    if (!json_is_null(jrm))
        json_decref(jrm);
    json_object_set_new(json,"gravity",json_string(gravity.c_str()));
    this->gravity = gravity;
}
void Planet::setTerrain(const string &terrain) {
    auto jrm = json_object_get(json, "terrain");
    if (!json_is_null(jrm))
        json_decref(jrm);
    json_object_set_new(json,"terrain",json_string(gravity.c_str()));
    this->terrain = terrain;
}
void Planet::setPopulation(int population) {
    if(population >= 0) {
        auto jrm = json_object_get(json, "population");
        if (!json_is_null(jrm))
            json_decref(jrm);
        json_object_set_new(json, "population", json_integer(population));
        this->population = population;
    }
}
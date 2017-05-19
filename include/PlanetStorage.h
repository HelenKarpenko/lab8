/** @file
 *  @brief Class for storing a list of planets
 */
#ifndef LAB8_PLANETSTORAGE_H
#define LAB8_PLANETSTORAGE_H

#include <map>
#include <Planet.h>
#include <string>
using namespace std;

/**
 * @class
 * @brief defines a planet storage
 */
class PlanetStorage {
public:
    /**
     * @brief Planet storage constructor
     * @param filePath - file name
     */
    PlanetStorage(const string &filePath);
    /**
     * @brief Planet storage destructor
     */
    ~PlanetStorage();
    /**
     * @brief Get all planets from the storage
     * @return string with all planets in json format
     */
    string getAllPlanets();
    /**
     * @brief Get all planets with rotation period
     * @param key - planet rotation period
     * @return string with planets in json format
     */
    string findPlanetsRotationPeriod(string key);
    /**
     * @brief Get the planet by id
     * @param key - planet id
     * @return string with planet data in json format
     */
    string findPlanet(string key);

private:
    /**
     * @brief Get all planets from json file
     * @param filePath - file name
     * @return map of planets
     */
    map<int, Planet*> *parse_planets(const string &filePath);
    /**
     * @brief Get planet from json object
     * @param planetObj - json object with planet
     * @param id - unique key for planet
     * @return planet
     */
    Planet *parse_planet(json_t *planetObj, int id);
    map<int, Planet*> *planets;
};


#endif //LAB8_PLANETSTORAGE_H

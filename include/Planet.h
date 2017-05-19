/** @file
 * @brief Class for working with planet
 */
#ifndef LAB8_PLANETS_H
#define LAB8_PLANETS_H

#include <iostream>
#include <jansson.h>
using namespace std;

/**
 * @class
 * @brief defines a planet
 */
class Planet {
    int id;
    string name;
    int rotation_period;
    int diameter;
    string temperate;
    string gravity;
    string terrain;
    int population;
    json_t *json;

public:
    /**
     * @brief Planet constructor
     * @param name - planet name
     * @param id - planet id
     * @param rotation_period - planet rotation period
     * @param diameter - planet diameter
     * @param climate - planet climate
     * @param gravity - planet gravity
     * @param terrain - planet terrain
     * @param population - planet population
     */
    Planet(string name,
           int id,
           int rotation_period,
           int diameter,
           string climate,
           string gravity,
           string terrain,
           int population);
    /**
     * @brief Planet destructor
     */
    ~Planet();

    /**
     * @brief Planet name getter
     * @return planet name
     */
    const string &getName() const;
    /**
     * @brief Planet name setter
     * @param name - planet name
     */
    void setName(const string &name);
    /**
     * @brief Planet id getter
     * @return
     */
    int getId() const;
    /**
     * @brief Planet id setter
     * @param id
     */
    void setId(int id);
    /**
     * @brief Planet rotation_period getter
     * @return planet rotation_period
     */
    int getRotation_period() const;
    /**
     * @brief Planet rotation_period setter
     * @param rotation_period - planet rotation period
     */
    void setRotation_period(int rotation_period);
    /**
     * @brief Planet diameter getter
     * @return planet diameter
     */
    int getDiameter() const;
    /**
     * @brief Planet diameter setter
     * @param diameter
     */
    void setDiameter(int diameter);
    /**
     * @brief Planet climate getter
     * @return planet climate
     */
    const string &getClimate() const;
    /**
     * @brief Planet climate setter
     * @param planet climate
     */
    void setClimate(const string &gravity);
    /**
     * @brief Planet gravity getter
     * @return planet gravity
     */
    const string &getGravity() const;
    /**
     * @brief Planet gravity setter
     * @param gravity - planet gravity
     */
    void setGravity(const string &gravity);
    /**
     * @brief Planet terrain getter
     * @return planet terrain
     */
    const string &getTerrain() const;
    /**
     * @brief Planet terrain setter
     * @param terrain - planet terrain
     */
    void setTerrain(const string &terrain);
    /**
     * @brief Planet population getter
     * @return planet population
     */
    int getPopulation() const;
    /**
     * @brief Planet population getter
     * @param population - planet population
     */
    void setPopulation(int population);
    /**
     * @brief Planet in json format getter
     * @return Planet in json format
     */
    json_t *getJson() const;
};

#endif //LAB8_PLANETS_H

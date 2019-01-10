//
//  CarMap.cpp
//  map
//
//  Created by Abhishek Naik on 1/22/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include "CarMap.h"
#include "Map.h"
#include <iostream>
using namespace std;

CarMap::CarMap()
{
}

bool CarMap::addCar(std::string license)
{
    if(map.contains(license))
        return false;
    else if(map.size() != DEFAULT_MAX_ITEMS)
        map.insert(license, 0);
    return true;
}

double CarMap::gas(std::string license) const
{
    ValueType v = 0.0;
    if(map.contains(license))
        map.get(license, v);
    return v;
}

bool CarMap::addGas(std::string license, double gallons)
{
    ValueType v;
    if((map.contains(license)) && (gallons > 0))
    {
        map.get(license, v);
        v+=gallons;
        map.update(license, v);
        return true;
    }
    return false;
}

bool CarMap::useGas(std::string license, double gallons)
{
    ValueType v;
    if(map.contains(license) && gallons > 0 && gallons < gas(license))
    {
        map.get(license, v);
        v -= gallons;
        map.update(license, v);
        return true;
    }
    return false;
}

int CarMap::fleetSize() const
{
    return map.size();
}

void CarMap::print() const
{
    for(int i = 0; i < map.size(); i++)
    {
        KeyType k;
        ValueType v;
        map.get(i, k, v);
        cout<<k<<" "<<v<<endl;
    }
}

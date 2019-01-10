//
//  main.cpp
//  CarMap
//
//  Created by Abhishek Naik on 1/23/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include <iostream>
#include "CarMap.h"
#include "Map.h"
#include <cassert>

using namespace std;



int main()
{
    CarMap cm;
    cm.addCar("XZYZG");
    cm.addGas("XZYZG", 45.5);
    assert(!cm.useGas("XZYZG", 50.0));
    cm.useGas("XZYZG", 15.0);
    assert(cm.gas("XZYZG") == 45.5-15.0);
    
    cm.addCar("DANIEL");
    cm.addGas("DANIEL", 34.5);
    
    assert(cm.gas("DANIEL") == 34.5);
    
    cm.addCar("ALEXA");
    cm.addCar("ALEX");
    
    assert(cm.fleetSize() == 4);
    
    
    

    
    cout<<"All tests passed."<<endl;
}

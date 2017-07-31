//
// Created by Xiaochen Wang on 2017-07-12.
//

#ifndef MS3_STREAMABLE_H
#define MS3_STREAMABLE_H

#include <iostream>
#include <fstream>
//#include "MyFile.h"

using namespace std;

namespace sict{
    class Streamable{
        // pure virutal function
    public:
         virtual fstream& store(fstream&, bool addNewLine = true)const=0;
         virtual fstream& load(fstream&)=0;
         virtual ostream& write(ostream&, bool)const=0;
         virtual istream& read(istream&)=0;
    };

}

#endif //MS3_STREAMABLE_H

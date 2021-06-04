#ifndef STUDENTNAME_H
#define STUDENTNAME_H
#include <string>
#include <iostream>
#include<string.h>
using namespace std;
class StudentName
{

private:
    string name;

public:
    StudentName(string name)
    {
        int numOfSpaces=0 ,index;
        for(int i=0;i< name.size();i++){
            if(name[i]==' '){
                numOfSpaces++;
                index=i;

            }
        }

        if(numOfSpaces==0){
            this->name=name +" " +name +" " +name ;
        }
        else if (numOfSpaces==1){
            this->name=name + name.substr(index) ;
        }
        else {
            this->name=name;
        }

    }





};

#endif // STUDENTNAME_H

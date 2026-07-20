//includes
#include <fstream>
#include <math.h>
//fix save error
#ifndef defaultSavePath
#define defaultSavePath ""
#endif
/// @brief that function transform to char* from const char*
/// @param __i that const  char* will transform it
char* toChar(const char* __i)
{
    char* returning;
    for (size_t i = 0; i < sizeof(__i)/sizeof(__i); i++) returning[i] = __i[i];
    return returning;
}
/// @brief that function to transform to const char* from char*
/// @param __i that that char* will transform it
const char* toChar(char* __i)
{
    const char* returning =__i;
    return returning;
}
/// @brief that function add path default path
/// @param path that path will add it
std::string __addGlobalPath  (std::string path)
{
    //set to returning path defaultPath
    std::string returning= defaultSavePath;
    //add path
    returning+=path;
    //return
    return returning;
};
/// @brief that function save global var
/// @param varName that Name (path of filePath) to Global Var
/// @param value that value of variable is const char*
/// @param defaultPathAdd if you add it 
void save(const char* varName,const char* value,bool defaultPathAdd= true)
{
    //set transform varName
    std::string fileName =(defaultPathAdd)? __addGlobalPath(varName):varName ;
    //setFile
    std::fstream  file(fileName,std::ios_base::in);
    //add
    file<< value;
}
/// @brief that function return a var
/// @param varName that Name (path of filePath) to Global Var
/// @param defaultPathAdd if you add it 
const char* load(const char* varName,bool defaultPathAdd= true)
{
    //set transfrom varName
    std::string fileName  = (defaultPathAdd)? __addGlobalPath(varName) :varName;
    //setFile
    std::fstream file(fileName,std::ios_base::out);
    //returning char var
    std::string returningStr,fileLine;
    //set returning to file line by file
    while (std::getline(file,fileName)) returningStr+=fileLine+'\n' ;
    //returning
    return returningStr.c_str();
}
int strTo(char i){if(int('0')<=int(i)<=int('9')) int(i)-int('0');throw i;}
char Tostr(int i){if( 0<i<9)return i+int('0');else throw i;}
/// @brief that function return int from char
/// @param __l that character transform it
int strTo(const char* __l,int)
{
    //set base vars
    int returning=0;
    int beginLoop = 0;
    //fix minus in math
    if(__l[0]=='-') beginLoop=1; 
    //set returning var
    for (size_t i =  beginLoop; i < sizeof(__l)/sizeof(const char); i++) returning+=strTo(__l[i])*pow(10,i);
    //fix minus
    if(beginLoop)returning*=-1; 
    //return
    return returning;
}
/// @brief that function transform from float to const char*
/// @param __l that const char* will transfrom it
float strTo(const char* __l,float)
{
    //set strVar
    std::string str__L =__l;
    //set Find Comma str
    size_t commaFind=str__L.find(',');
    //erase  ,
    str__L.erase(',');
    //returning
    return  strTo(str__L.c_str(),int())/pow(10,commaFind);
}
    //set len fn
auto len = [](int l)
    {
        //set var
        size_t returning = 0;
        while (l>=0)l/=10;returning++;
        return returning;
    };
/// @brief that transform int to const char*
/// @param l that integer to transform it
const char* toStr(int l)
{
    //set begin
    int begin = l>0;
    //set returning var
    char* returning;
    //fix -
    if(!begin)   returning[0]= '-';
    //add returning char
    for (size_t i =begin; i <len(l) ; i++) returning[i]=Tostr(int(l/len(l)));
    //return
    return returning;
}
/// @brief that transform from float to const char*
/// @param l that float transform it
const char* toStr(float l)
{
    //set retuning var
    std::string returning;
    //add l without comma
    returning+=toStr(int(l));
    //set l to not comma it
    l-=int(l);
    //set l int
    while (l!=int(l)) l*=10;
    //add comma
    returning+=',';
    //add l without comma
    returning+=toStr(l); 
    //return
    return returning.c_str();
}
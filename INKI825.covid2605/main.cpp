#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct covidMK

{
string grad;
int novi;
int ozdraveni;

    covidMK(const string& grad, int novi, int ozdraveni)

    : grad(grad), novi(novi), ozdraveni(ozdraveni){}

bool operator>(const covidMK& c) const
    {
        return novi > c.novi; //sporedba za sortiranje po novi
    }

};

struct SortPointers
{
    bool operator()(const covidMK* a, const covidMK* b) const
    {
        return *a > *b;
    }
};

int main()
{
vector<covidMK*> vcmk; //definiranje na vektorot
//8zapisi
vcmk.push_back(new covidMK( "Stip", 7, 10));
vcmk.push_back(new covidMK( "Sveti Nikole", 1, 5));
vcmk.push_back(new covidMK( "Bitola", 13, 7));
vcmk.push_back(new covidMK( "Prilep", 2, 4));
vcmk.push_back(new covidMK( "Debar", 1, 5));
vcmk.push_back(new covidMK( "Negotino", 2, 6));
vcmk.push_back(new covidMK( "Gevgelija" , 1, 1));
vcmk.push_back(new covidMK( "Ohrid" , 1, 3));

for(const auto* c: vcmk)

cout <<c->grad <<" "<< c->novi << " " << c->ozdraveni<< '\n';

cout<<"Sortirani"<<endl;
sort(vcmk.begin(), vcmk.end(), SortPointers());

for(const auto* c: vcmk)

cout <<c->grad <<" "<< c->novi << " " << c->ozdraveni<< '\n';

//vector vo nadvoreshen fajl
ofstream outFile ("INKI825IvanPetkovskiCovidMK.txt");
for (const auto& e: vcmk) outFile<<e<<endl;

for(auto* c: vcmk)
delete c;

}

#include <bits/stdc++.h>


using namespace std;
#define pb push_back

struct birthdate
{
    int month, year, day;
    string person; //Este no importa es el nombre de la persona del cumpleaños
    //Redefinición del operador < en este caso para poder ordenar la fechas
    birthdate(){}
    birthdate(string person,int day, int month, int year)
    {
        this->person=person;
        this->day=day;
        this->month=month;
        this->year=year;
    }
    bool operator < (birthdate &fecha) const
    {
        /*Para este problema necesitabamos hacer una redefinición del operador < para poder 
        ordenar las fechas en un orden específicoy así aprovechar las bondades de la stl*/
        if(year < fecha.year) return true;
        if (year==fecha.year && month< fecha.month) return true;
        if (year==fecha.year && month == fecha.month && day<fecha.day) return true;
        else return false;
    }
};

int main()
{
    int people;
    scanf("%d",&people);
    vector<birthdate> nacimientos;
    while(people--)
    {
        string persona;
        int dd,mm,yy; //dia mes y año de nacimiento
        cin>>persona>>dd>>mm>>yy;
        nacimientos.pb(birthdate(persona,dd,mm,yy));
    } 
    sort(nacimientos.begin(),nacimientos.end());
    cout<<nacimientos.back().person<<endl<<nacimientos.front().person<<endl;
    return 0;
}
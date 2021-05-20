#include <bits/stdc++.h>

using namespace std;

//Primero tenemos que converitr lo del calendario Haab a alguna cantidad numérica

map<string,int> Haab;

vector<string> meses={"pop","no","zip","zotz","tzec","xul","yoxkin","mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax",
"koyab","cumhu","uayet"};

vector<string> days={"imix", "ik", "akbal", "kan", "chicchan","cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"}; 

void createmap()
{
    for(int i=0;i<meses.size();i++)
    {
        Haab[meses[i]]=i;
    }
}

int convertHaabDate(float day, string month, int year)
{
    int real_year=year*365;
    int real_month=Haab[month]*20;
    int real_date=(int)day+real_month+real_year;
    return real_date;
}

void convertTzolkinDate(int date)
{
    int year=date/260;
    string day=days[date % 20];
    int number=date % 13 +1;
    cout<<number<<" "<<day<<" "<<year<<endl;
}

void ConvertDates(float day, string month, int year)
{
    int cant=convertHaabDate(day,month,year);
    convertTzolkinDate(cant);
}


int main()
{
    createmap();
    float day;
    int year;
    string month;
    int testcases;
    cin>>testcases;
    cout<<testcases<<endl;
    while(testcases--)
    {
        cin>>day>>month>>year;
        //cout<<day<<" "<<month<<" "<<year<<endl;
        ConvertDates(day,month,year);
    }
    return 0;
}
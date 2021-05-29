
#include<bits/stdc++.h>

using namespace std;

bool operator < (const pair<string,int>&p1,const pair<string,int>&p2)
{
    return p1.second<p2.second;
}

class BaseTokenizer
{
    private:
    vector<pair<string,int>> order;
    map<string,int> freqs;
    vector<string> top10;
    public:
    char limit=' '; //Valores por default del tokenizador
    bool obtain_freqs=true;
    BaseTokenizer()
    {
        freqs.clear();
        order.clear(); //limpiar los remanentes de los vectores y el map
        order.shrink_to_fit();
        top10.clear();
        top10.shrink_to_fit();
    }
    vector<string> tokenize(string s)
    {
        vector <string> tokens;
        stringstream check1(s);
        string intermediate;
        while(getline(check1,intermediate,limit))
        {
            tokens.push_back(intermediate);
        }
        if(obtain_freqs)
        {
            count_freqs(tokens);
            most_frequent(freqs);
        }
        return tokens;
    }
    list<string> toList(string s)
    {
        vector<string> tokens=tokenize(s);
        list<string> tnks;
        for(int i=0;i<tokens.size();i++)
        {
            tnks.push_back(tokens[i]);
        }
        return tnks;
    }
    void count_freqs(vector<string> tokens)
    {
        freqs.clear(); //Para cada cadena hay tokens diferentes si no se limpia el map va a ir incrementando de forma erronea
        for(auto token:tokens)
        {
            if(freqs.find(token)==freqs.end())
            {
                freqs[token]=1;
            }
            else
            {
                freqs[token]+=1;
            }
        }
    }
    void most_frequent(map<string,int> frecuencias)
    {
        for(map<string,int>::iterator it=frecuencias.begin();it!=frecuencias.end();++it)
        {
            order.push_back(make_pair((*it).first,(*it).second));
        }
        sort(order.begin(),order.end());
        int idx=std::min((int)order.size(),10);
        for(int i=0;i<idx;i++)
        {
            top10.push_back(order[i].first);
        }
    }
    map<string,int> get_freqs()
    {
        return freqs;
    }
    vector<string> get_top()
    {
        return top10;
    }
};


class RegexpTokenizer : public BaseTokenizer
{
    public:
    vector<string> tokens;
    map<string,int> frecuencias;
    vector<string> Top10;
    void Tokenize(string s)
    {
        clean();
        tokens=this->tokenize(s);
        frecuencias=this->get_freqs();
        Top10=this->get_top();
    }
    void clean()
    {
        tokens.clear();
        frecuencias.clear();
        Top10.clear();
    }

};

int main()
{
    RegexpTokenizer tokenizador;
    string s="I am wondering where I may gather some pretty, sweet flowers. Whom shall I ask? Suppose that I ask the brilliant humming-bird, the emerald trembler; suppose that I ask the yellow butterfly; they will tell me, they know, where bloom the pretty, sweet flowers, whether I may gather them here in the laurel woods where dwell the tzinitzcan birds, or whether I may gather them in the flowery forests where the tlauquechol lives. There they may be plucked sparkling with dew, there they come forth in perfection. Perhaps there I shall see them if they have appeared; I shall place them in the folds of my garment, and with them I shall greet the children, I shall make glad the nobles.";
    tokenizador.Tokenize(s);
    cout<<"Top 10 words"<<endl;
    for(vector<string>::iterator it=tokenizador.Top10.begin();it!=tokenizador.Top10.end();++it) cout<<*it<<" ";
    cout<<endl;
    return 0;
}
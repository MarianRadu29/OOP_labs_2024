#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<fstream>
#include<string>
struct compare 
{
	bool operator() (std::pair<std::string, int> a, std::pair<std::string, int> b) 
	{
		if (a.second < b.second)
			return true;
	        else
			if (a.second > b.second)
				    return false;
			else
		           	if (a.first < b.first)
		                    return false;
		                else
		                    return true;
	}
};

int main()
{   
    std::ifstream f("input.txt");
    std::string phrase;
    if(f.is_open())
        {
            std::getline(f,phrase);
            f.close();
        }
    else
        {
            std::cout<<"Probleme la deschiderea fisierului";
            exit(1);
        }
   // std::string phrase = "I bought an apple. Then I eat an apple. Apple is my favorite.";
    std::map<std::string,int> MAP;
    for(int i=0;i<phrase.size();i++)
    {   
       if(strchr(" ?.!,",phrase[i])==0)
        {
            std::string aux = "";
            while(strchr(" ?.!,",phrase[i])==0 && i<phrase.length())
                {   
                    if(phrase[i]>='A' && phrase[i]<='Z')
                        phrase[i]+=32;
                    aux.append(1,phrase[i]);
                    i++;
                }
            if(MAP.count(aux)==0)
                MAP[aux] = 1;
            else
                MAP[aux]++;
        }
    }
    std::priority_queue< std::pair<std::string,int> ,std::vector<std::pair<std::string,int>>, compare> pq;
    for(std::map<std::string, int>::iterator i = MAP.begin() ; i!=MAP.end();i++)
            pq.push({i->first , i->second});
    std::cout<<"------------------------"<<'\n';
    while(pq.empty()==false)
    {
		std::cout<<pq.top().first<<" => "<<pq.top().second<<'\n';
        pq.pop();
    }
    std::cout<<"------------------------"<<'\n';                                                 
    return 0;
}

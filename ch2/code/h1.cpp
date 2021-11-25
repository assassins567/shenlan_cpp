#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>

std::vector<std::vector<char>>& file_input(std::ifstream& infile){
    std::vector<std::vector<char>>  bigData;
    infile.open("input.txt");
    char ele;
    std::string line;
    while(getline(infile, line))
    {
        std::stringstream ss(line);
        std::vector<char> oneline;
        while (ss >> ele)
        {
            //std::cout << ele;
            oneline.push_back(ele);
        } 
        bigData.push_back(oneline);
        //std::cout << line.c_str() << std::endl;
    }
    for (auto row : bigData){
		for (auto col : row){
			std::cout << col;
		}
		std::cout << "\n";
	}
    return bigData;
}

bool if_legal(std::vector<std::vector<char>>& bigData)
{
     for(int i=0; i< bigData.size(); i++)
    {
        if (isdigit(bigData[i][0]) || bigData[i][0] == '+' || bigData[i][0] == '-')
        {
            for (int j = 0; j < bigData[i].size(); j++)
            {
                if (isdigit(bigData[i][j])) return 1; 
                else return 0;
            }
        }
        else 
        {
             return 0;
        } 
    }
}

void calculation(std::vector<std::vector<char>>& bigData)
{
    std::vector<int> numbers;
    for(int i=0; i< bigData.size(); i++)
    {
        if(bigData[i][0] == '+' )
        {
            int num = 0;
            for (int j = 1; j < bigData[j].size(); j++)
            {
                num += (int)(bigData[i][bigData[j].size()-j] - '0') * pow(10, j) ; 
            } 
        }
        else if(bigData[i][0] == '-' )
        {
            int num = 0;
            for (int j = 1; j < bigData[j].size(); j++)
            {
                num += (int)(bigData[i][bigData[j].size()-j] - '0') * pow(10, j) * (-1) ; 
            } 
        }
        else 
         {
            int num = 0;
            for (int j = 0; j < bigData[j].size(); j++)
            {
                num += (int)(bigData[i][bigData[j].size()-j-1] - '0') * pow(10, j)  ; 
            } 
        }
    }
}
int main( int argc, char* argv[]){
    
    std::ifstream infile;
    std::vector<std::vector<char>>  bigData;
    bigData =  file_input(infile);
    
    return 0;
}



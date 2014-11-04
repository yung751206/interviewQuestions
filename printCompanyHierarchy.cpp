#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using std::cout;
using std::endl;

void getInputToVector(std::string line,std::vector<std::vector<std::string>> &employee);
void getChart(std::vector<std::vector<std::string>> &employee,std::map<std::string,std::map<std::string,int>> &chart);
void printOutChart(std::ofstream &outputWriter,std::map<std::string,std::map<std::string,int>> &chart,std::vector<std::vector<std::string>> &employee,std::string name,int dasuCount);

int main()
{
    int num_cases;
    std::string line;
    std::ifstream inputReader("org_chart_sample.in");
    std::ofstream outputWriter("sum_sample_solution_cpp.out");
    std::vector<std::vector<std::string>> employee;
    std::map<std::string,std::map<std::string,int>> chart;
    inputReader >> num_cases;
    getline(inputReader,line);
    
    for (int i = 0; i < num_cases; i++)
    {
        getline(inputReader,line);
        std::cout << line << std::endl;
        getInputToVector(line,employee);
        getChart(employee,chart);
        outputWriter << "Case #" << i+1 << std::endl;
        printOutChart(outputWriter,chart,employee,"NULL",0);
        employee.clear();
        chart.clear();
    }
    
    inputReader.close();
    outputWriter.close();
    return 0;
}

void getInputToVector(std::string line,std::vector<std::vector<std::string>> &employee){
    std::string delimiter = "--";
    std::vector<std::string> data;
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        data.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    data.push_back(line);
    
    for(int i=0;i<data.size();i++){
        delimiter = ",";
        std::vector<std::string> information;
        while ((pos = data[i].find(delimiter)) != std::string::npos) {
            token = data[i].substr(0, pos);
            information.push_back(token);
            data[i].erase(0, pos + delimiter.length());
        }
        information.push_back(data[i]);
        employee.push_back(information);
    }
}

void getChart(std::vector<std::vector<std::string>> &employee,std::map<std::string,std::map<std::string,int>> &chart){
    //    int index = 0;
    std::pair <std::string,int> p1;
    std::map<std::string,int> m1;
    std::pair<std::string,std::map<std::string,int>> p2;
    
    for(int i=0;i<employee.size();i++){
        std::string manager = employee[i][1];
        if(chart.find(manager) != chart.end() ){
            continue;
        }
        else{
            for(int j=i;j<employee.size();j++){
                if(employee[j][1] == employee[i][1]){
                    p1 = std::make_pair (employee[j][0],j);
                    m1.insert(p1);
                }
            }
            p2 = std::make_pair(manager,m1);
            m1.clear();
            chart.insert(p2);
        }
    }
    //    for(std::map<std::string,std::map<std::string,int>>::iterator it = chart.begin();it!=chart.end();it++){
    //        cout<<it->first<<endl;
    //        for(std::map<std::string,int>::iterator jt = it->second.begin();jt!=it->second.end();jt++){
    //            cout<<jt->first<<endl;
    //        }
    //        cout<<endl;
    //    }
}

void printOutChart(std::ofstream &outputWriter,std::map<std::string,std::map<std::string,int>> &chart,std::vector<std::vector<std::string>> &employee,std::string name,int dashCount){
    //    cout<<"name = "<<name<<endl;
    std::map<std::string,std::map<std::string,int>>::iterator it = chart.find(name);
    if( it == chart.end()){
        return;
    }
    std::map<std::string,int>::iterator jt = it->second.begin();
    while(jt!=it->second.end()){
        for(int i=0;i<dashCount;i++){
            outputWriter<<"-";
        }
        outputWriter<<jt->first<<" ("<<employee[jt->second][2]<<") "<<employee[jt->second][3]<<endl;
        printOutChart(outputWriter, chart,employee,jt->first,dashCount+1);
        jt++;
    }
}
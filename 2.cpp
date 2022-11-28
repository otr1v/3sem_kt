#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <exception>
#include <stdexcept>
#include <set>
#include <vector>

using namespace std;

void new_bus(string bus, int stop_count, vector<string> stops, map<string, vector<string>>& table)
{
    for (int i = 0; i < stop_count; i++)
    {
        table[bus].push_back(stops[i]);
    }
}
void buses_for_stop(string stop, map<string, vector<string>>& table)
{
    int counter = 0;
    for (auto i : table)
    {
        int size = i.second.size();
        for (int k = 0; k < size; k++)
        {
            if(i.second[k] == stop)
            {
                counter++;
                cout << i.first << endl;
            }
        }
        
    }
    if (counter == 0)
    {
        cout << "no stop";
    }
}

void stops_for_bus(string bus, map<string, vector<string>>& table)
{
   
   int counter = 0;
   try
   {
    if (&table.at(bus) == 0)
        {
            //cout<<"what?";
        }
    else
    {
        vector<string> stops = table[bus];
        int size = stops.size();
        for (int i = 0; i < size; i++)
        {
            
            for (auto j: table)
            {
                if (j.first != bus)
                {
                    vector<string> changes = j.second;
                    int changes_size = changes.size();
                    for (int k = 0; k < changes_size; k++)
                    {
                        if (stops[i] == changes[k])
                        {
                            if (counter == 0)
                            {
                                cout << stops[i] << " : change for ";
                            }
                            counter++;
                            cout << j.first << ", ";
                        }
                    }
                }
            }
        }
    }
   }
   
   catch(exception& ex)
    {
    	std::cerr << ex.what() << '\n';
    }

    // vector<string> stops = table[bus];
    // int size = stops.size();
    // for (int i = 0; i < size; i++)
    // {
        
    //     for (auto j: table)
    //     {
    //         if (j.first != bus)
    //         {
    //             vector<string> changes = j.second;
    //             int changes_size = changes.size();
    //             for (int k = 0; k < changes_size; k++)
    //             {
    //                 if (stops[i] == changes[k])
    //                 {
    //                     if (counter == 0)
    //                     {
    //                         cout << stops[i] << " : change for ";
    //                     }
    //                     counter++;
    //                     cout << j.first << ", ";
    //                 }
    //             }
    //         }
    //     }
    // }
   
   
    
    if (counter == 0)
    {
        cout << "no interchange";
    }
}

int main()
{
    map<string, vector<string>> table = {{"1st", {"mck", "mak", "hdijdfogz", "mitino"}}, {"2st", {"mitino", "centr"}}, {"3st", {"mmm", "gggg", "mitino"}}, {"4st", {"empty stop"}}};
    vector<string> commands(10);
    int Q;
    cout << table.size();
    cout << "enter number of commands"<< endl;
    cin >> Q; 
    for (int i = 0; i < Q; i++)
    {
        cout << "enter " << i + 1 << " command" << endl;
        cin >> commands[i];
        if (commands[i] == "new_bus")
        {
            cout << "enter name of route:" << endl;
            string route;
            cin >> route;
            cout << "enter number of stops" << endl;
            int n;
            vector<string> stops;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                cin >> stops[j];
            }
            new_bus(route, n, stops, table);
        }
        if (commands[i] == "buses_for_stop")
        {
            cout << "enter name of stop" << endl;
            string stop;
            cin >> stop;
            buses_for_stop(stop, table);
        }
        if (commands[i] == "all_buses")
        {
            if (table.size() == 0)
            {
                cout << "no buses";
            }
            else
            {
                for (auto i : table)
                {
                    int size = i.second.size();
                    cout << i.first << endl;
                    for (int k = 0; k < size; k++)
                    {
                        cout << i.second[k] << endl;
                    }
                }
            }
        }
        if (commands[i] == "stops_for_bus")
        {
            cout << "choose your fighter:"<< endl;
            string bus;
            cin >> bus;
            stops_for_bus(bus, table);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string name;
    vector<string> lines;
    vector<pair<Node*, int>> connections;

    Node(string n, vector<string> l)
    {
        name = n;
        lines = l;
    }
};

class Metro
{
    vector<Node*> roots;
    int total_stations;
    
public:
    Metro()
    {
        total_stations = 0;
    }

    Node* FindLine(string line)
    {

        for(Node* root: roots)
        {
            bool correct = false;
            for(string curr_line: root->lines)
            {
                if(curr_line == line)
                    {
                        correct = true;
                        break;
                    }
            }

            if(!correct)
                continue;

            return root;
        }

        cout<<"Line: "<<line<<" Doesnt Exist"<<endl;
        return nullptr;
    }

    Node* FindStation(Node* root, string find_name)
    {
        queue<Node*> check;
        check.push(root);

        while(!check.empty())
        {
            Node* temp = check.front();
            
            if(temp->name == find_name)
                return temp;

            for(pair<Node*,int> to_add: temp->connections)
            {
                check.push(to_add.first);
            }

            check.pop();
        }

        cout<<"Station: "<<find_name<<" Does not exist"<<endl;
        return nullptr;
    }

    void AddConnection(Node* A, Node* B, int dist)
    {
        A->connections.push_back({B,dist});
        B->connections.push_back({A,dist});
    }
void Insert(string name, vector<string> lines, string previousStation = "", int dist = 0)
{
    for(Node* root : roots)
    {
        Node* existing = FindStation(root, name);

        if(existing != nullptr)
        {
            cout << "Station " << name << " already exists." << endl;
            return;
        }
    }

    Node* newNode = new Node(name, lines);

    if(roots.empty())
    {
        roots.push_back(newNode);
        total_stations++;

        cout << "First station " << name << " inserted successfully." << endl;
        return;
    }

    if(previousStation == "")
    {
        roots.push_back(newNode);
        total_stations++;

        cout << "First station of new line " << name
             << " inserted successfully." << endl;
        return;
    }

    Node* previous = nullptr;

    for(Node* root : roots)
    {
        previous = FindStation(root, previousStation);

        if(previous != nullptr)
            break;
    }

    if(previous == nullptr)
    {
        cout << "Previous station " << previousStation
             << " does not exist." << endl;

        delete newNode;
        return;
    }

    AddConnection(previous, newNode, dist);

    total_stations++;

    cout << "Station " << name
         << " inserted successfully after "
         << previousStation << "." << endl;
}
    
};

int main()
{
    
    
    
    
    
    
    
    
    return 0;
}

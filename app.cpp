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

    
};

int main()
{
    
    
    
    
    
    
    
    
    return 0;
}
struct DivisionNode;
    
struct DivisionNode
{
    std::string variable_name;
    vector<struct DivisionEdge> edges;
};

struct DivisionEdge
{
    struct DivisionNode *target_node;
    double value;
};

class Solution {
private:
    double find_solution(std::string start, std::string end, std::unordered_map<std::string, struct DivisionNode> existing_nodes)
    {
        auto start_node = existing_nodes[start];

        std::unordered_map<std::string, bool> visited;
        std::queue<std::pair<double, struct DivisionNode*>> to_visit;

        to_visit.push(std::make_pair(1.0, &start_node));

        while(to_visit.size() > 0)
        {
            auto current_node = to_visit.front().second;
            auto current_name = to_visit.front().second->variable_name;
            auto current_val = to_visit.front().first;

            to_visit.pop();

            // Already visited
            if(visited.find(current_name) != visited.end())
            {
                continue;
            }

            visited[current_name] = true;

            if(current_name == end)
            {
                return current_val;
            }

            for(auto edge : current_node->edges)
            {
                auto edge_val = edge.value;
                to_visit.push(std::make_pair(current_val * edge_val, edge.target_node));
            }

        }


        return -1.0;


    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        std::unordered_map<std::string, struct DivisionNode> existing_nodes;

        vector<double> solutions;

        for(int i = 0; i < equations.size(); ++i)
        {
            auto a = equations[i][0];
            auto b = equations[i][1];
            auto val = values[i];

            // Ensure entries exist
            existing_nodes[a].variable_name = a;
            existing_nodes[b].variable_name = b;

            struct DivisionEdge edge_a_b;
            edge_a_b.target_node = &existing_nodes[b];
            edge_a_b.value = val;

            existing_nodes[a].edges.push_back(edge_a_b);

            if(val != 0)
            {
                struct DivisionEdge edge_b_a;
                edge_b_a.target_node = &existing_nodes[a];
                edge_b_a.value = 1.0/val;

                existing_nodes[b].edges.push_back(edge_b_a);
            }        
        }

        for(auto query : queries)
        {
            auto a = query[0];
            auto b = query[1];
            
            if(existing_nodes.find(a) == existing_nodes.end()
            || existing_nodes.find(b) == existing_nodes.end())
            {
                solutions.push_back(-1.0);
                continue;
            }

            if(a == b)
            {
                solutions.push_back(1.0);
                continue;
            }

            solutions.push_back(find_solution(a, b, existing_nodes));
        }

        return solutions;
    }
};
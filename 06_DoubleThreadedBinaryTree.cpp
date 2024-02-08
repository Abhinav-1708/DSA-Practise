#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;
    Node *parent;

    Node(string name) : name(name), left(nullptr), right(nullptr), parent(nullptr) {}

    void addChild(Node *l, Node *r)
    {
        left = l;
        right = r;
        if (l != nullptr)
            l->parent = this;
        if (r != nullptr)
            r->parent = this;
    }
};

// To find node by name
Node *findNode(Node *root, const string &name)
{
    if (root == nullptr)
        return nullptr;
    if (root->name == name)
        return root;
    Node *leftSearch = findNode(root->left, name);
    if (leftSearch != nullptr)
        return leftSearch;
    return findNode(root->right, name);
}

// To find reporting Authority
string findReportingAuthority(Node *root, const string &name)
{
    Node *node = findNode(root, name);
    if (node != nullptr && node->parent != nullptr)
    {
        return node->parent->name;
    }
    return "Not Found";
}

// To find direct reports
vector<string> findDirectReports(Node *root, const string &nodeName)
{
    vector<string> reports;
    Node *node = findNode(root, nodeName);
    if (node != nullptr)
    {
        if (node->left != nullptr)
            reports.push_back(node->left->name);
        if (node->right != nullptr)
            reports.push_back(node->right->name);
    }
    return reports;
}

// To help with finding all reports
void findAllReportsHelper(Node *node, vector<string> &reports)
{
    if (node == nullptr)
        return;
    reports.push_back(node->name);
    findAllReportsHelper(node->left, reports);
    findAllReportsHelper(node->right, reports);
}

// Function to find all reports under a node
vector<string> findAllReports(Node *root, const string &nodeName)
{
    vector<string> reports;
    Node *node = findNode(root, nodeName);
    if (node != nullptr)
    {
        findAllReportsHelper(node->left, reports);
        findAllReportsHelper(node->right, reports);
    }
    return reports;
}
void printDetailedReports(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    vector<string> directReports = findDirectReports(node, node->name);
    cout << node->name;
    if (!directReports.empty())
    {
        cout << " leads ";
        for (const string &report : directReports)
        {
            cout << report << " ";
        }
    }
    cout << endl;
    if (node->left != nullptr)
    {
        printDetailedReports(node->left);
    }
    if (node->right != nullptr)
    {
        printDetailedReports(node->right);
    }
}
int main()
{
    Node *projectManager = new Node("Project Manager");
    Node *hardwareLead = new Node("Hardware Lead");
    Node *softwareLead = new Node("Software Lead");
    Node *engineer1 = new Node("Engineer 1");
    Node *assistantEngineer1 = new Node("Assistant Engineer 1");
    Node *engineer2 = new Node("Engineer 2");
    Node *assistantEngineer2 = new Node("Assistant Engineer 2");
    Node *assistantEngineer3 = new Node("Assistant Engineer 3");
    Node *lineLead1 = new Node("Line Lead 1");
    Node *asstLineLeader1 = new Node("Asst Line Leader 1");
    Node *asstLineLeader2 = new Node("Asst Line Leader 2");
    Node *lineLead2 = new Node("Line Lead 2");
    Node *asstLineLeader3 = new Node("Asst Line Leader 3");

    // Setting up the hierarchy
    projectManager->addChild(hardwareLead, softwareLead);
    hardwareLead->addChild(engineer1, engineer2);
    engineer1->addChild(assistantEngineer1, nullptr);
    engineer2->addChild(assistantEngineer2, assistantEngineer3);
    softwareLead->addChild(lineLead1, lineLead2);
    lineLead1->addChild(asstLineLeader1, asstLineLeader2);
    lineLead2->addChild(asstLineLeader3, nullptr);

    string inputA, inputB, inputC;
    getline(cin, inputA);
    getline(cin, inputB);
    getline(cin, inputC);
    string authority = findReportingAuthority(projectManager, inputA);
    if (authority != "Not Found")
    {
        cout << authority << endl;
    }
    else
    {
        cout << inputA << "Node Node Found --- Check Spellings." << endl;
    }

    vector<string> directReports = findDirectReports(projectManager, inputB);
    if (!directReports.empty())
    {
        for (const string &report : directReports)
        {
            cout << report << " ";
        }
        cout << endl;
    }
    else
    {
        cout << inputB << " has no direct reports or not found(Check Spellings)." << endl;
    }

    printDetailedReports(projectManager, inputC);

    return 0;
}
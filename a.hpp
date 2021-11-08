#ifndef aa_hpp
#define aa_hpp
#include <bits/stdc++.h>
using namespace std;

class DFA_inputs
{
public:
    int no_of_states, no_of_inputs, no_of_final_states;
    char start_state;
    vector<char> final_states;
    vector<char> inputs;
    vector<char> states;
    map<char, map<char, char>> dfa;
    vector<vector<char>> equilance_sets; //set of non-final states and final states
    map<char, int> state_to_index;       // map of state to index

    DFA_inputs(int n, int m); //constructor

    void NonFinal_States();                      //set of non-final states
    void add_transition(char s, char i, char d); //add transition to dfa
    void print_dfa();                            //print initial dfa
};

DFA_inputs::DFA_inputs(int n, int m) //constructor
{
    no_of_states = n;
    no_of_inputs = m;
}

void DFA_inputs::NonFinal_States() //set of non-final states
{
    vector<char> non_final_states;
    for (auto it : states)
    {
        if (find(final_states.begin(), final_states.end(), it) == final_states.end())
        {
            non_final_states.push_back(it);
        }
    }
    equilance_sets.push_back(non_final_states); //push set of non-final states
    equilance_sets.push_back(final_states);     // push set of final states
    for (int i = 0; i < no_of_states; i++)      // map of state to index
    {
        state_to_index[states[i]] = i;
    }
}

void DFA_inputs::add_transition(char s, char i, char d) //add transition
{
    dfa[s][i] = d;
}

void DFA_inputs::print_dfa() //print dfa
{
    for (auto i : inputs)
    {
        cout << "   |" << i;
    }
    cout << "\n--------------\n";
    for (auto i : dfa)
    {
        cout << i.first << " ";
        for (auto j : i.second)
        {
            cout << " |" << j.second << "  ";
        }
        cout << "\n--------------\n";
    }
}

#endif
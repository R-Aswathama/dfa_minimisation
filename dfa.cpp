#include <bits/stdc++.h>
#include "a.hpp"
#include "b.hpp"
using namespace std;
int main()
{
//     freopen("inputf.txt", "r", stdin);
//     freopen("outputf.txt", "w", stdout);
    
    int n, m;
    cout << "Enter the number of states: ";
    cin >> n;
    cout << "\nEnter the number of inputs: ";
    cin >> m;
    cout << "\nEnter the states: ";
    DFA_minimisation dfa(n, m);
    for (int i = 0; i < n; i++) //enter states
    {
        char c;
        cin >> c;
        dfa.states.push_back(c);
    }
    cout << "\nEnter the inputs: ";
    for (int i = 0; i < m; i++) // enter inputs
    {
        char c;
        cin >> c;
        dfa.inputs.push_back(c);
    }

    cout << "\nEnter the start state: ";
    cin >> dfa.start_state;
    cout << "\nEnter the number of final states: ";
    cin >> dfa.no_of_final_states;

    cout << "\nEnter the final states: ";
    for (int i = 0; i < dfa.no_of_final_states; i++) // enter final states
    {
        char c;
        cin >> c;
        dfa.final_states.push_back(c);
    }

    cout << "\nEnter the transitions:\n";
    for (int i = 0; i < n; i++) // add transitions
    {
        for (int j = 0; j < m; j++)
        {
            char d;
            cin >> d;
            dfa.add_transition(dfa.states[i], dfa.inputs[j], d);
        }
    }

    dfa.NonFinal_States();
    dfa.print_dfa();
    dfa.get_equilance_classes(dfa.states);
    dfa.optimize_states();
    dfa.union_of_optimise_states();
    dfa.final_minimised_dfa();
    dfa.final_minimised_dfa2();
    dfa.print_union_of_dfa_minimised();
    dfa.final_minimised_transition_table();
    dfa.print_final_states();

    return 0;
}

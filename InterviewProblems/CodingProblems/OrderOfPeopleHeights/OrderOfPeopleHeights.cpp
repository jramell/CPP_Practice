/**
 * Contains solution to problem which original statement is at: https://www.interviewbit.com/problems/order-of-people-heights/
 *
 * You are given the following :

    A positive number N
    Heights : A list of heights of N persons standing in a queue
    Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and
                standing in front of P.
    You need to return list of actual order of persons’s height

    Consider that heights will be unique

    Example--------------------

    Input :
        Heights: 5 3 2 6 1 4
        InFronts: 0 1 2 0 3 2
    Output :
        actual order is: 5 3 2 1 6 4

    So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence
    Infronts has 0 for him.

    For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

    You can do similar inference for other people in the list.
 */

#include <vector>
#include <algorithm>

using std::vector;

//helper struct not provided by problem
struct PersonInfo {
    int height;
    int infront;
    PersonInfo() : height(-1), infront(-1) { }
    PersonInfo(int height, int infront) : height(height), infront(infront) { }
};

//helper function to sort the problems more easily
bool personComparison(const PersonInfo& person1, const PersonInfo& person2) {
    return person2.height > person1.height;
}

//actual method that solves the problem
vector<int> orderOfPeopleHeights(vector<int>& heights, vector<int>& infronts) {
    vector<PersonInfo> persons(heights.size());
    for(int i = 0; i < heights.size(); i++) {
        persons.at(i) = PersonInfo(heights.at(i), infronts.at(i));
    }
    std::sort(persons.begin(), persons.end(), personComparison);

    heights.assign(heights.size(), 0);
    for(int i = 0; i < persons.size(); i++) {
        int numberOfSpaces = 0;
        for(int j = 0; j < heights.size(); j++) {
            if(heights.at(j) == 0) {
                if(numberOfSpaces == persons.at(i).infront) {
                    heights.at(j) = persons.at(i).height;
                    break;
                }
                numberOfSpaces++;
            }
        }
    }
    return heights;
}
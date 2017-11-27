#include "ProductsOfOtherNumbers.h"

using std::vector;

vector<int> jr::getProductsOfAllExceptAtIndexQuadratic(vector<int> numbers) {
    if(numbers.size() < 2) {
        return numbers;
    }
    vector<int> products(numbers.size());
    int currentMultiplication = 1;
    for(int i = 0; i < numbers.size(); i++) {
        currentMultiplication = 1;
        for(int j = 0; j < i; j++) {
            currentMultiplication *= numbers.at(j);
        }
        for(int j = i+1; j < numbers.size(); j++) {
            currentMultiplication *= numbers.at(j);
        }
        products.at(i) = currentMultiplication;
    }
    return products;
}

vector<int> jr::getProductsOfAllExceptAtIndexBothLinear(vector<int> numbers) {
    vector<int> answer = numbers;
    if(numbers.size() <= 1) {
        return answer;
    }
    vector<int> productsFromStart(numbers.size());
    vector<int> productsFromEnd(numbers.size());

    productsFromStart.at(0) = numbers.at(0);
    for(int i = 1; i < numbers.size(); i++) {
        productsFromStart.at(i) = productsFromStart.at(i-1)*numbers.at(i);
    }

    productsFromEnd.at(0) = numbers.at(numbers.size()-1);
    for(int i = 1; i < numbers.size(); i++) {
        productsFromEnd.at(i) = productsFromEnd.at(i-1)*numbers.at(numbers.size()-1-i);
    }

    answer.at(0) = productsFromEnd.at(numbers.size()-2);
    answer.at(numbers.size()-1) = productsFromStart.at(numbers.size()-2);
    for(int i = 1; i < numbers.size()-1; i++) {
        answer.at(i) = productsFromStart.at(i-1) * productsFromEnd.at(numbers.size()-2-i);
    }
    return answer;
}

vector<int> jr::getProductsOfAllExceptAtIndexOptimal(std::vector<int> numbers) {
    if(numbers.size() <= 1) {
        return numbers;
    }
    vector<int> products(numbers.size());
    int currentFromStart = numbers.at(0);
    int currentFromEnd = numbers.at(numbers.size()-1);
    for(int i = 1; i < numbers.size()-1; i++) {
        products.at(i) = currentFromStart;
        currentFromStart *= numbers.at(i);
    }
    products.at(numbers.size()-1) = currentFromStart;

    for(int i = numbers.size()-2; i > 0; i--) {
        products.at(i) *= currentFromEnd;
        currentFromEnd *= numbers.at(i);
    }
    products.at(0) = currentFromEnd;
    return products;
}
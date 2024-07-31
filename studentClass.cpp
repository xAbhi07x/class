#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
    string name;
    int mob;
    string age;
    int rank;
    string grade;

    public:
    Student(): name(), mob(), age(), rank(), grade(){}
    Student(string name, int mob, string age, int rank, string grade){
        this->name = name;
        this->age = age;
        this->rank = rank;
        this->mob = mob;
        this->grade = grade;
    }

    void insert(string name, int mob, string age, int rank, string grade, vector<Student>& v){
        v.push_back(Student(name, mob, age, rank, grade));
        sort(v.begin(), v.end(), cmp);
    }

    bool cmp(const Student& a, const Student& b){
        if(a.name!=b.name){
            return a.name < b.name;
        }else{
            return a.rank < b.rank;
        }
    }   

};




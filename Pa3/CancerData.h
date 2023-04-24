#pragma once
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
#include <string>

class CancerData {
public:
    CancerData(const std::string& name, float rate) :
        countryName(name), rate(rate) {}

    CancerData(const CancerData& other) :
        countryName(other.countryName), rate(other.rate) {}

    CancerData& operator=(const CancerData& other) {
        if (this != &other) {
            countryName = other.countryName;
            rate = other.rate;
        }
        return *this;
    }

    ~CancerData() {
     
    }

    std::string getName() const {
        return countryName;
    }

    float getRate() const {
        return rate;
    }

    void setName(const std::string& name) {
        countryName = name;
    }

    void setRate(float rate) {
        this->rate = rate;
    }
    bool operator==(const CancerData& other) const {
        return rate == other.rate;
    }

    bool operator<(const CancerData& other) const {
        return rate < other.rate;
    }
    bool operator>(const CancerData& other) const {
        return other.rate < rate;
    }

private:
    std::string countryName;
    float rate;
};



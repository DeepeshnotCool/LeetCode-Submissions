class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> v;
        double Kelvin = celsius + 273.15;
        double Fahrenheit = celsius * 1.80 + 32.00;
        v.push_back(Kelvin);
        v.push_back(Fahrenheit);
        return v;
    }
};
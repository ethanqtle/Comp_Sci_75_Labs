#include <string>

class Numbers {
public:
    Numbers(int num) : m_num(num) { }

    std::string toEnglish() {
        if (m_num == 0) {
            return "zero";
        }
       
        std::string result;
       
        if (m_num >= 1000) {
            result += digitName(m_num / 1000) + " thousand ";
            m_num %= 1000;
        }
       
        if (m_num >= 100) {
            result += digitName(m_num / 100) + " hundred ";
            m_num %= 100;
        }
       
        if (m_num >= 20) {
            result += tensName(m_num / 10) + " ";
            m_num %= 10;
        }
       
        if (m_num > 0) {
            result += digitName(m_num);
        }
       
        return result;
    }

private:
    int m_num;

    static std::string digitName(int digit) {
        static const std::string names[] = {
            "", "one", "two", "three", "four", "five",
            "six", "seven", "eight", "nine", "ten" ,
            "eleven", "twelve", "thirteen", "fourteen",
            "fifteen", "sixteen", "seventeen", "eighteen",
            "nineteen"
        };
        return names[digit];
    }
   
    static std::string tensName(int tens) {
        static const std::string names[] = {
            "", "", "twenty", "thirty", "forty", "fifty",
            "sixty", "seventy", "eighty", "ninety"
        };
        return names[tens];
    }
};

#include <iostream>

int main() {
    int num;
    std::cout << "Enter a whole dollar amount (0-9999): ";
    std::cin >> num;
   
    Numbers n(num);
    std::string english = n.toEnglish();
   
    std::cout << english << std::endl;
    return 0;
}
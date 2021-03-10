class Solution {
public:
    string intToRoman(int num) {
        string numStr;
        if (num >= 1000) {
            int thousand = num / 1000;
            for (int i = 0; i < thousand; i++) {
                numStr.append("M");
            }
            num = num % 1000;
        }
        if (num >= 900) {
            numStr.append("CM");
            num -= 900;
        }
        if (num >= 500) {
            numStr.append("D");
            num -= 500;
        }
        if (num >= 400) {
            numStr.append("CD");
            num -= 400;
        }
        if (num >= 100) {
            int hundred = num / 100;
            for (int i = 0; i < hundred; i++) {
                numStr.append("C");
            }
            num = num % 100;
        }
        if (num >= 90) {
            numStr.append("XC");
            num -= 90;
        }
        if (num >= 50) {
            numStr.append("L");
            num -= 50;
        }
        if (num >= 40) {
            numStr.append("XL");
            num -= 40;
        }
        if (num >= 10) {
            int ten = num / 10;
            for (int i = 0; i < ten; i++) {
                numStr.append("X");
            }
            num = num % 10;
        }
        if (num >= 9) {
            numStr.append("IX");
            num -= 9;
        }
        if (num >= 5) {
            numStr.append("V");
            num -= 5;
        }
        if (num >= 4) {
            numStr.append("IV");
            num -= 4;
        }
        if (num >= 1) {
            for (int i = 0; i < num; i++) {
                numStr.append("I");
            }
        }
        return numStr;
    }
};
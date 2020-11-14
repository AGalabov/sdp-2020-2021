#include "Decode.h"

std::string Decode::decodeString(std::string s) {
        std::stack<int> repeatTimes;
        std::stack<std::string> strings;
        
        std::string decoded;
        int repeatCount = 0;
        for(char c : s){
            
            if(isdigit(c)){
                repeatCount = repeatCount * 10 + (c - '0');
            }
            
            if(isalpha(c)){
                decoded += c;
            }
            
            if(c == '['){
                repeatTimes.push(repeatCount);
                strings.push(decoded);
                decoded = "";
                repeatCount = 0;
            }
            
            if(c == ']'){
                int repeatTop = repeatTimes.top(); repeatTimes.pop();
                std::string repeatedString = "";
                for(int i = 0; i < repeatTop; i++){
                    repeatedString += decoded;
                }
                decoded = strings.top() + repeatedString;
                strings.pop();                
            }
        }
        return decoded;
}

int main(){
	std::string test1 = "3[a]2[bc]";
	//expected output - "aaabcbc"
	std::cout << "Input: " << test1 << std::endl;
	std::cout << Decode::decodeString(test1) << std::endl;
	std::cout << "=======================" << std::endl;

	std::string test2 = "3[a2[c]]";
	//expected output - "accaccacc"
	std::cout << "Input: " << test2 << std::endl;
	std::cout << Decode::decodeString(test2) << std::endl;
	std::cout << "=======================" << std::endl;

	std::string test3 = "2[abc]3[cd]ef";
	//expected output - "abcabccdcdcdef"
	std::cout << "Input: " << test3 << std::endl;
	std::cout << Decode::decodeString(test3) << std::endl;
	std::cout << "=======================" << std::endl;

	std::string test4 = "abc3[cd]xyz";
	//expected output - "abccdcdcdxyz"
	std::cout << "Input: " << test4 << std::endl;
	std::cout << Decode::decodeString(test4) << std::endl;
	std::cout << "=======================" << std::endl;

	return 0;
}
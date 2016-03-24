#include<stdio.h>
#include<fstream>
#include<iostream>
#include<map>
#include<math.h>

#include"alien_number.h"

void alien_number(void){
	// read the file line by line
	std::ifstream read_file("alien_number.txt");
	std::string line;

	std::string alien_number_str;
	std::string source_language_str;
	std::string target_language_str;
	int num_in_decimal;
	std::string num_in_local;
	int case_num 	= 1 ;

	while (std::getline(read_file, line)){

		alien_number_str	= line.substr(0, line.find(' '));
		line.erase(0, line.find(' ') + 1);
		source_language_str = line.substr(0, line.find(' '));	
		line.erase(0, line.find(' ') + 1);
		target_language_str = line.substr(0, line.find(' '));		
		// string extracted
	
		num_in_decimal		= convert_to_decimal(alien_number_str, source_language_str);
		num_in_local		= convert_to_local(num_in_decimal, target_language_str);
		std::cout << "Case #" << case_num << ": " << num_in_local << std::endl;
		case_num++;
		
	}
	read_file.close();
}

int convert_to_decimal(std::string alien_number_str, std::string source_language_str){
	// create dictionary for source language
	std::map<std::string, int> 	source_language_dict;
	std::string					dict_key;
	int 						dict_size = source_language_str.size();
	int							dict_value	= 0;
	while (source_language_str.size() != 0){
		dict_key	= source_language_str[0];
		source_language_str.erase(source_language_str.begin());
		// add the new item in the dictionary
		source_language_dict.insert(std::pair<std::string, int>(dict_key, dict_value));
		dict_value++;
	}
	// dictionary created
	int 						return_value = 0;	
	std::string					single_digit_str;
	while (alien_number_str.size() != 0){
		single_digit_str	= alien_number_str[0];
		return_value		+= source_language_dict[single_digit_str] * pow(dict_size, alien_number_str.size() - 1);
		alien_number_str.erase(alien_number_str.begin());
	}
	return return_value;
}

std::string convert_to_local(int num_in_decimal, std::string target_language_str){
	// create dictionary for source language
	std::map<int, std::string> 	target_language_dict;
	std::string					dict_key;
	int 						dict_size = target_language_str.size();
	int							dict_value	= 0;
	while (target_language_str.size() != 0){
		dict_key	= target_language_str[0];
		target_language_str.erase(target_language_str.begin());
		// add the new item in the dictionary
		target_language_dict.insert(std::pair<int, std::string>(dict_value, dict_key));
		dict_value++;
	}
	// dictionary created
	int 						single_digit;
	std::string					return_string;
	while (num_in_decimal / dict_size != 0){
		single_digit			= num_in_decimal % dict_size;
		// update input value
		num_in_decimal			= (num_in_decimal - single_digit) / dict_size;
		return_string.insert(0, target_language_dict[single_digit]);
	}
	single_digit			= num_in_decimal - num_in_decimal / dict_size;
	return_string.insert(0, target_language_dict[single_digit]);
	return return_string;

}

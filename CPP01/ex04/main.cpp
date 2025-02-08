/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:40:59 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/08 13:44:19 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	find_and_replace(const std::string &file_content, const std::string &file_name, const std::string &old_word, const std::string &new_word)
{
	std::ofstream outfile((file_name + ".replace").c_str());
	if (!outfile)
    {
        std::cerr << "Error\nUnable to create the output file." << std::endl;
        return ;
    }
	size_t pos = 0;
    size_t found;
    while ((found = file_content.find(old_word, pos)) != std::string::npos)
    {
        outfile << file_content.substr(pos, found - pos) << new_word;
        pos = found + old_word.length();
    }
    outfile << file_content.substr(pos);
    outfile.close();
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error\nUsage : " << argv[0] << "<in_file> <old_word> <new_word>." << std::endl;
		return (EXIT_FAILURE);
	}
	std::string file_name(argv[1]);
	std::string old_word(argv[2]);
	std::string new_word(argv[3]);
	if (old_word.empty())
	{
		std::cerr << "Error\nThe string to replace cannot be empty." << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream infile(file_name.c_str());
    if (!infile)
    {
        std::cerr << "Error\nCould not open file '" << file_name << "'" << std::endl;
        return (EXIT_FAILURE);
    }
	std::string line;
	std::string file_content;
	while (std::getline(infile, line))
	{
		file_content += line;
		if (!infile.eof())
			file_content += '\n';
	}
	infile.close();
	find_and_replace(file_content, file_name, old_word, new_word);
	return (EXIT_SUCCESS);
}


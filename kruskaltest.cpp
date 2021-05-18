/*
 * kruskaltest.cpp
 *
 *  Created on: Dec. 2, 2020
 *      Author: Raksha
 */

#include <iostream>
#include <string>
#include <map>

#include "Graph.hpp"
#include "invalid.hpp"

/// using maps to use switch case on string and detect user input
// code inspiration from - https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4067/Switch-on-Strings-in-C.htm
enum class user_commands {random,n,i,d,degree,edge_count,mst,clear,exit};

std::map <std::string, user_commands> commands_map {{"random", user_commands::random},
													{"n ", user_commands::n},
													{"i ", user_commands::i},
													{"de", user_commands::degree},
													{"d ", user_commands::d},
													{"ed", user_commands::edge_count},
													{"ms", user_commands::mst},
													{"cl", user_commands::clear},
													{"ex",user_commands::exit}
												};





int main(){
	std::string cmdline;
	user_commands value;

	Graph G;

	//exceptions - https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm#:~:text=A%20C%2B%2B%20exception%20is%20a,try%2C%20catch%2C%20and%20throw.
	while ( std::getline(std::cin,cmdline) ) {
		try {
			value = commands_map[cmdline.substr(0,2)];
			cmdline = cmdline.substr(2);

			switch (value) {
				case user_commands::n : {
					long int m = std::stol(cmdline);
					G.init_Graph(m);

					break;
				}

				case user_commands::i : {
					int diff = cmdline.find(";");
					long int source = std::stol(cmdline.substr(0, diff)) ;
					cmdline = cmdline.substr(diff+1);

					diff = cmdline.find(";");
					long int destination = std::stol(cmdline.substr(0, diff)) ;
					cmdline = cmdline.substr(diff+1);

					long double weight = std::stold(cmdline) ;

					G.insert_Edge (weight, source, destination);

					break;
				}

				case user_commands::d : {
					int diff = cmdline.find(";");
					long int source = std::stol(cmdline.substr(0, diff)) ;
					cmdline = cmdline.substr(diff+1);

					long int destination = std::stol(cmdline) ;

					G.delete_Edge(source, destination);

					break;
				}

				case user_commands::degree : {
					cmdline = cmdline.substr(5);
					long int vertex =  std::stol(cmdline);

					G.print_vertex_degree(vertex);
					break;
				}

				case user_commands::edge_count : {
					G.print_edge_count();
					break;
				}

				case user_commands::mst : {
					G.print_mst_Weight();
					break;
				}

				case user_commands::clear : {
					G.clear_edges();
					break;
				}

				case user_commands::exit : {
					return 0;
					break;
				}

				default : {
					throw 505;
					break;
				}

			}
		}
		catch (Invalid) {
			std::cout<<"invalid argument"<<std::endl;
		}
		catch (...) {
			std::cout<<"invalid command"<<std::endl;
		}
	}

	return 0;
}





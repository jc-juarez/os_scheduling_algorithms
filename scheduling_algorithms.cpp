/*****************************************
*  OS Scheduling Algorithms - Refactoring
*  'scheduling_algorithms.cpp'
*  Author: Juan Carlos Juárez
*  Contact: jc.juarezgarcia@outlook.com
*****************************************/

#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include "scheduling_algorithms.hpp"

namespace os_scheduling {

    std::pair<int,double> FIFO(std::string process_string, int number_pages) {

        // Number of Page Fails
        int fails{}; 

        // Current Processes for Constant Time Look-Up
        std::unordered_set<char> process_set{};

        // Queue of Processes
        std::queue<char> process_queue{};
        
        for(char process : process_string) { 

            if(process_set.size() < number_pages && !process_set.count(process)) {  

                fails++; 
                process_set.insert(process); 
                process_queue.push(process); 

            } else if(!process_set.count(process)) { 

                fails++; 
                char current_process = process_queue.front(); 
                process_queue.pop(); 
                process_set.erase(current_process); 
                process_queue.push(process); 
                process_set.insert(process); 

            }
            
        }

        // Efficiecy = (1 - (fails / size)) * 100
        double efficiency = (1.0 - (double(fails) / double(process_string.size()))) * 100.0; 
        return {fails, efficiency}; 

    } // FIFO

    std::pair<int,double> LRU(std::string process_string, int number_pages) {
        
        // Number of Page Fails
        int fails{}; 

        // Unordered Map for Allocating Processes and their last seen position 
        std::unordered_map<char,int> process_index_map; 
        
        for(int index = 0; index < process_string.size(); ++index) {

            char process = process_string[index];

            if(process_index_map.size() < number_pages) { 

                if(!process_index_map.count(process)) fails++; 
                process_index_map[process] = index; 

            } else { 

                if(!process_index_map.count(process)) { 

                    fails++; 
                    
                    int greatest_index = INT_MIN; 
                    char greatest_process = ' '; 

                    // Oldest Process Removal
                    for(auto &x : process_index_map) { 
                        char current_process = x.first;
                        int current_index = x.second;
                        int current_distance = index - current_index; 
                        if(current_distance > greatest_index) { 
                            greatest_index = current_distance; 
                            greatest_process = current_process; 
                        }  
                    }

                    process_index_map.erase(greatest_process); 
                    process_index_map[process] = index; 

                } else { 

                    process_index_map[process] = index;  
                    
                }  

            }

        } 

        // Efficiecy = (1 - (fails / size)) * 100
        double efficiency = (1.0 - (double(fails) / double(process_string.size()))) * 100.0; 
        return {fails, efficiency};

    } // LRU

} // namespace os_scheduling
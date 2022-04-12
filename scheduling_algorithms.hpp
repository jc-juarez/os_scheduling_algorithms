/*****************************************
*  OS Scheduling Algorithms - Refactoring
*  'scheduling_algorithms.hpp'
*  Author: Juan Carlos Juárez
*  Contact: jc.juarezgarcia@outlook.com
*****************************************/

#ifndef SCH_ALGO
#define SCH_ALGO

#include <string>
#include <utility>

namespace os_scheduling {

    std::pair<int,double> FIFO(std::string, int);
    std::pair<int,double> LRU(std::string, int);

} // namespace os_scheduling

#endif
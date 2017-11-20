#ifndef SERGIOTEST_SOLUTIONS1_H
#define SERGIOTEST_SOLUTIONS1_H

#include <string>

//based on Cracking the Code interview, 4th Edition
class Solutions1
{
public:
    //1.3 ------------------------------------------------------------------------------
    static std::string removeLowercaseEnglishDuplicates(const std::string&);
    static std::string removeASCIIDuplicates(const std::string&);
    //End of 1.3 -----------------------------------------------------------------------

    //1.4
    static bool areAnagrams(const std::string& string1, const std::string& string2);
    //end of 1.4 -----
};
#endif //SERGIOTEST_SOLUTIONS1_H

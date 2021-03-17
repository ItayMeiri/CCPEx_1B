#include "snowman.hpp"
#include <iostream>

namespace ariel
{

const int options = 4;
const int required_seed_length = 8;


std::array<std::string, options> hats = {
    " _===_",
    "  ___\n .....",
    "   _\n  /_\\",
    "  ___ \n (_*_)"
};
std::array<std::string, options> noses = {",", ".", "_", " "};
std::array<std::string, options> eyes = {".", "o", "O", "-"};
std::array<std::string, options> base = {" : ", "\" \"", "___", "   "};
std::array<std::string, options> torso = {" : ", "] [", "> <", "   "};
std::array<std::string, options> leftHand = {" <", "\\ ", " /", "  "};
std::array<std::string, options> rightHand = {" >", "/ ", " \\", "  "};

const int Hat=0 , Nose=1, LeftEye=2 , RightEye=3, RightHand=4, LeftHand=5, Torso=6, Base=7; 

std::string snowman(int seed)
{
    
    // validate snowman seed, throws exception when invalid
    std::array<std::string, required_seed_length> strSeed = seedValidator(seed); // stored as the seed HNLRXYTB 

    std::string sman = 
    strSeed.at(Hat) + "\n" // hat
    +strSeed.at(RightHand).at(0) + "(" // right arm, char 0
    +strSeed.at(LeftEye) + strSeed.at(1) + strSeed.at(3) + ")" // face and eyes
    +strSeed.at(LeftHand).at(0) + "\n" // left arm, char 0
    +strSeed.at(RightHand).at(1) + "(" // right arm, char 1
    +strSeed.at(Torso) + ")" // torso
    +strSeed.at(LeftHand).at(1) + "\n (" // left arm, char 1
    +strSeed.at(Base) + ")"; // base

    return sman;
}

constexpr int TEN{10};
std::array<std::string, required_seed_length> seedValidator(int seed)
{
    if(seed < 0) { throw std::out_of_range("Invalid code '5'");}
    int count = 0;
    std::array<std::string, required_seed_length> str;
    int size = required_seed_length - 1;
    while(seed > 0)
    {
        if ((seed % TEN) > 4){ // get last digit
            throw std::out_of_range("Invalid code '5'");
        }
        //HNLRXYTB
        int index = (seed % TEN) - 1;
        int strCount = size - count; 
        if(count == Base){str.at(strCount) = hats.at(index);}
        else if(count == Torso){str.at(strCount) = noses.at(index);}
        else if( (count == LeftHand) || (count == RightHand) ){str.at(strCount) = eyes.at(index);} // left
        else if(count == RightEye){str.at(strCount) = leftHand.at(index);}
        else if(count == LeftEye){str.at(strCount) = rightHand.at(index);}
        else if(count == Nose){str.at(strCount) = torso.at(index);}
        else if(count == Hat){str.at(strCount) = base.at(index);}

        seed = (seed/TEN); // removes last digit
        count++; // counts the digits
    }
    
    if(count != required_seed_length ){
        throw std::out_of_range("Invalid code '5'");
    }
    return str;
}
}
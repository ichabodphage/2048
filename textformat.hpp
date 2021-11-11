
namespace tf{
    //variables that hold bash formating codes
    std::string bold = "\033[1m";
    std::string dim = "\033[2m";
    std::string underline = "\033[4m";
    std::string blink = "\033[5m";
    std::string invert = "\033[7m";
    std::string hide = "\033[8m";

    //variables that hold the end to bash formating codes
    std::string boldEnd = "\033[21m\033[24m";
    std::string dimEnd = "\033[22m";
    std::string underlineEnd = "\033[24m";
    std::string blinkEnd = "\033[25m";
    std::string invertEnd = "\033[27m";
    std::string hideEnd = "\033[28m";
    //returns a color escapeKey
    std::string color(int colorNum){
      return "\033[38;5;" +std::to_string(colorNum)+"m";
    }
    //returns a color background escapeKey
    std::string colorbg(int colorNum){
      return "\033[48;5;" +std::to_string(colorNum)+"m";
    }

    
}

#include <iostream>
#include <unistd.h>

int main(int argc, char argv[][]) {
    if (geteuid() != 0) {
        std::cout << "You need root privileges to run " << argv[0] << std::endl ;
        return 1;
    }

    std::cout << "Normal mod mu Ultra mod mu? (N/U)  >";
    char mode;
    std::cin >> mode;

    if (mod == 'N')
        system("sudo echo powersave > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
    else if (mod == 'U')
        system("sudo echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
    else {
        std::cout << "Hata." << std::endl;
        return 1;
    }
}

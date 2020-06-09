/*
* IN PROGRESS
*/


#include <iostream>
#include <unistd.h>
#include <thread>
#include <string> 

using namespace std;

struct cpu_params {
  const char *governors;
  int cores;
};

cpu_params params;

const string cpuPath = "/sys/devices/system/cpu/cpu";
const string govPath = "/cpufreq/scaling_governor";

void coreSetter(string kernelParameterPath) {
  
  string command = "";

  for (int i = 0; i < params.cores; i++) {
    string index = cpuPath;
    index += to_string(i);
    index += kernelParameterPath;
    index += i == params.cores - 1 ? "" : " && ";

    command.append(index);

    cout << index << "\n";
  }

  //system(command.c_str());
}

int main() {

  params.cores = sysconf(_SC_NPROCESSORS_ONLN);

  coreSetter(govPath);



  return 0;
}
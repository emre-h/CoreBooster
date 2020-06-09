/*
* UNDER DEVELOPMENT
* Author: Emre Harbutoğlu
*/

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <string> 

using namespace std;

struct cpu_params {
  string governors;
  int cores;
};

cpu_params params;

const string cpu_path = "/sys/devices/system/cpu/cpu";
const string gov_path = "/cpufreq/scaling_governor";

void core_setter(string kernel_parameter_path) {
  
  string command = "";

  for (int i = 0; i < params.cores; i++) {
    command.append(cpu_path + to_string(i) + kernel_parameter_path + (i == params.cores - 1 ? "" : " && "));
  }

  //system(command.c_str());
}

void set_cpu_params() {
  params.cores = sysconf(_SC_NPROCESSORS_ONLN);

  ifstream file(cpu_path + to_string(0) + "/cpufreq/scaling_available_governors");

  if (file.is_open()) {
    getline(file, params.governors);

    file.close();
  }
}

bool is_governor_exist(string gov) {
  return params.governors.find(gov) != string::npos;
}

void mode_setter(int mode) {

}

int main() {  
  core_setter(gov_path);
  set_cpu_params();


  cout << is_governor_exist("performance");

  return 0;
}
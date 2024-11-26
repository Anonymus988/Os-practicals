#include <iostream>
#include <unistd.h>
#include <cstdlib> //for execl()
#include <sys/wait.h> //for wait()
using namespace std;

// 1. same program same code
// int main() {
//     pid_t pid = fork();
//     if(pid < 0){
//         cerr << "Fork failed" << endl;
//         return -1;
//     }
//     if(pid == 0) cout << "Child process executing" <<endl;
//     else cout << "Parent process executing" << endl;

// return 0;
// }

// 2. same program different code
// int main() {
//     pid_t pid = fork();
//     if(pid < 0){
//         cerr << "Fork failed" << endl;
//         return -1;
//     }
//     if(pid == 0) {
//         execl("/bin/touch","touch","text.txt",NULL);
//         cerr << "Child process failed to exec ls" << endl;
//         cout << "Child process executing" <<endl;
//         }
//     else cout << "Parent process executing" << endl;

// return 0;
// }

// 3. Parent waits for child process to finish
int main() {
    pid_t pid = fork();
    if(pid < 0){
        cerr << "Fork failed" << endl;
        return -1;
    }
    if(pid == 0) {

        cout << "Child process executing" <<endl;
        sleep(2);
        cout << "Child process finished" <<endl;
        }
    else{
         cout << "Parent process executing" << endl;
         wait(NULL);
         cout << "Parent process resumed and finished" << endl;
         }

return 0;
}
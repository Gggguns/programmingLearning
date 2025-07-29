#include "PollServer.hpp"
#include <memory>

int main()
{
    std::unique_ptr<PollServer> svr(new PollServer());
    svr->Init();
    svr->Start();
    // cout << "fd_set size: " << (sizeof(fd_set)*8) << endl;    
    return 0;
}
#include "SelectServer.hpp"
#include <memory>

int main()
{
    std::unique_ptr<SelectServer> svr(new SelectServer());
    svr->Init();
    svr->Start();
    // cout << "fd_set size: " << (sizeof(fd_set)*8) << endl;    
    return 0;
}
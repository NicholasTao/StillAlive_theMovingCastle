#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <dlfcn.h>
#include <fstream>

using namespace std;

void inputCode()
{
    // string a;
    // cin >> a;
    ofstream outputMyFile("./ai.cpp");
    string info = "";
    cin >> info ;
    info = "extern \"C\" int count(){return "+info+" ;}";
    outputMyFile << info ;
    outputMyFile.close();
}

void creatCode()
{

}

void compileCode()
{
	system("gcc -fpic -shared ai.cpp -o ai.so");
}

void addLinking()
{

	typedef void (*func_t)();

	void *pdlHandle = dlopen("./ai.so", RTLD_LAZY); // RTLD_LAZY 延迟加载
    char *pszErr = dlerror();
    if( !pdlHandle || pszErr )
    {
        printf("Load mylib failed!\n");
        return;
    }

    int (*count)() = (int(*)()) dlsym(pdlHandle, "count"); // 定位动态链接库中的函数
    if( !count )
    {
        pszErr = dlerror();
        printf("Find symbol failed!%s\n", pszErr);
        dlclose(pdlHandle);
        return;
    }

    int a = count(); // 调用动态链接库中的函数

    printf("\ni am %d", a);

    dlclose(pdlHandle); // 系统动态链接库引用数减1

}

int main()
{
    inputCode();
    creatCode();
    compileCode();
    addLinking();
    return 0;
}

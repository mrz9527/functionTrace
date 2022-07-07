// author : zhoukang
// date   : 2022-07-07 15:13:46

extern "C" {
#include <stdio.h>
#include <dlfcn.h>
#include <cxxabi.h>

//#define _GNU_SOURCE

static FILE *file = nullptr;

const char *get_funcname(const char *src) {
    int status = 99;
    const char *f = abi::__cxa_demangle(src, nullptr, nullptr, &status);
    return f == nullptr ? src : f;
}

void __attribute__((constructor)) traceBegin(void)
{
    file = fopen("func_trace.log", "w+");
}

void __attribute__((destructor)) traceEnd(void)
{
    if (file) {
        fclose(file);
    }
}

void __cyg_profile_func_enter(void *func, void *caller)
{
    if (file) {
        Dl_info info1, info2;
        if (dladdr(func, &info1) & dladdr(caller, &info2)) {
            fprintf(file, "entry %s called from %s\n", get_funcname(info1.dli_sname), get_funcname(info2.dli_sname));
        }
        // fprintf(file, "entry %p %p\n", func caller); // 打印函数名的地址，在通过addr2line命令行来得到函数名，func_trace.sh已经封装好了addr2line

    }
}

void __cyg_profile_func_exit(void *func, void *caller)
{
    if (file) {
        Dl_info info1, info2;
        if (dladdr(func, &info1) & dladdr(caller, &info2)) {
            fprintf(file, "exit %s called from %s\n", get_funcname(info1.dli_sname), get_funcname(info2.dli_sname));
        }
        // fprintf(file, "exit %p %p\n", func caller); // 打印函数名的地址，在通过addr2line命令行来得到函数名，func_trace.sh已经封装好了addr2line
    }
}
}
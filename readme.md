# 查看函数调用关系
通过gcc编译选项-finstrument-functions的方式
实现两个函数：__cyg_profile_func_enter和__cyg_profile_func_exit
得到函数运行过程中的所有函数执行顺序

只支持gcc编译器

# 如何使用？
1.在自己的可执行文件中添加编译选项-g -finstrument-functions -export-dynamic,以cmakelists.txt为例
```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -finstrument-functions -export-dynamic")
```
2.在自己的可执行文件中链接libfunctionTrace.so,以cmakelists.txt为例
```cmake
target_link_libraries(functionTraceDemo functionTrace)
```

# 常见内存错误（/memcheck/mc_errors.c）

    /* What kind of error it is. */
    typedef 
    enum { 
        Err_Value, // 使用未初始化变量
        Err_Cond, // 使用未初始化值进行条件跳转
        Err_CoreMem, // 地址中包含未初始化字节
        Err_Addr, // 地址不可读或不可写
        Err_Jump, // 程序运行跳转至非法内存
        Err_RegParam, // Syscall寄存器参数包含未初始化字节
        Err_MemParam, // Syscall堆栈参数包含未初始化或不可寻址字节
        Err_User,
        Err_Free, // 释放了非法内存
        Err_FreeMismatch, // new/new[]/malloc的内存没用对应delete/delete[]/free释放
        Err_Overlap, // strcpy/memcpy等函数的src和dest地址有重叠
        Err_Leak, // 内存泄露
        Err_IllegalMempool, // 内存池地址非法
        Err_FishyValue, // 函数参数中带有非法值，如size_t类型传入了负数
    }
    MC_ErrorTag;



用于 将浮点值转换为字符串，并将其存储在缓冲区中。 此函数有一个更安全的版本；请参阅 _gcvt_s。

``` c++
 float add_2(float *arr)
    {
        char sBuf[15];
        gcvt(arr[0], 12, sBuf);
        // emscripten_console_logf(temp);
        cout << sBuf << endl;
        // emscripten_console_log("11111");
        // emscripten_console_logf(sBuf);
        gcvt(arr[1], 12, sBuf);
        // emscripten_console_logf(sBuf);
        cout << sBuf << endl;
        print_args(arr[0], arr[1]);
        return arr[1] + arr[0];
    }

```
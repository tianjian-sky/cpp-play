set(a A;B;C)
set(b 0;1;2)
set(c X;Y)

foreach(x IN ZIP_LISTS a;b c)
    message("x_0: ${x_0}    x_1: ${x_1}     x_2: ${x_2}")
endforeach()
message("------------")

foreach(x y z IN ZIP_LISTS a;b c) # 变量个数需对应
    message("x: ${x}    y: ${y}     z: ${z}")
endforeach()

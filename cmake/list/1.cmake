set(a A;B)
set(b C D)
set(c "E F")
set(d G;H I)
set(e "")

foreach(x IN ITEMS a b c;d;e)
    message("x: ${x}")
endforeach()
message("------------")

foreach(x IN LISTS a b c;d;e ITEMS a b c;d;e)
    message("x: ${x}")
endforeach()

message("------------")

foreach(x IN LISTS a b c;d;e ITEMS a b c)
    message("x: ${x}")
endforeach()

message("------------")

foreach(x IN LISTS b c ITEMS a b c;d;e) # 先把LISTS部分当作列表变量的列表进行遍历，再遍历ITEMS的列表
    message("x: ${x}")
endforeach()

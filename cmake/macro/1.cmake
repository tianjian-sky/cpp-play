macro(my_macro p)
    message("-----my_macro"___${p}___p)
endmacro()

macro(my_macro2 a b)
    set(result "参数a:  ${a}, 参数b: ${b}")
    message("---in macro ${a} ${b}")
endmacro()

set(a 1 2 3)
my_macro(a b c)
message("-----------------------")
my_macro2(cc dd ee)
message("---out macro ${result}")
function addition(a, b, c)
    return (a + b + c)
end

function hello_string(a)
    return ("hello " .. a .. "! :)")
end

function no_param()
    return ("no parameters and a return!")
end

function no_param2()
    print ("no parameters and no return!")
end

function is_true(a)
    if a == true then
        print ("it is... true!")
        return ("true")
    else
        print ("nope, it's false...")
        return ("false")
    end
end

function show_string(a)
    print (a)
end

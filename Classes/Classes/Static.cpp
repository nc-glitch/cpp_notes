static int s_Var = 5; //"static" hides variable from all other translation units: effectively private
//if it was "int s_Var = 5;" instead, there would be a linking error
//name them static, unless you want global scope

int s_V = 5;

//within classes, "static" means there is only ONE INSTANCE of the variable for all of the objects of that class
//"static methods" do not require the class instance because they do not reference any class specific data
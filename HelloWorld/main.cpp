
constexpr int const_expression_function(int n){ return n; }
int main(){ constexpr int n = const_expression_function(100); return n; }


// Inheritance Graph = B:{E,F}:D
struct B {};
struct E : B {};
struct F : B {};
struct D : E, F {};

int main()
{
    D * d = nullptr;

    // Ambiguous conversion from derived class 'D' to base class 'B'
    B * ambiguous_conversion_target = (B *)d;

    B * b = reinterpret_cast<B*>(d);
}

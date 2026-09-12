import math

def beregn(n):
    I_0 = 1*10**(-12)
    K = 1.38064853*10**(-23)
    q = 1.6020*10**(-19)
    T = 300
    R = 9
    Vdd = 10
    Vd = 1.14
    for m in range(100000):
        I = I_0* (math.e**(q*Vd/(n*K*T)) -1);  
        Vr = I*R;

        if (Vdd - Vr) > Vd:
            Vd = Vd + 0.00001;
        else:
            Vd = Vd - 0.00001
    print(I)

beregn(1.6) #-> 0.9840991223273952
beregn(1.3) #-> 1.007634511509793